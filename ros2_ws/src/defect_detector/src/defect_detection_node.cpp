// MTRX3760 2025 Project 2: Warehouse Robot DevKit
// File: defect_detection_node.cpp
// Author(s): Will Rumi
//
// This file implements the DefectDetectionNode class. The node subscribes to
// camera and pose topics, manages parameter configuration, handles detection
// services, and logs detected defects using the DefectManager.

#include "defect_detector/defect_detection_node.hpp"
#include <rclcpp/rclcpp.hpp>

#include <tf2_ros/buffer.h>
#include <tf2_ros/transform_listener.h>
#include <geometry_msgs/msg/pose_stamped.hpp>

// CONSTRUCTOR AND DESTRUCTOR

// Constructs and initialises the defect detection node.
DefectDetectionNode::DefectDetectionNode(const std::string &node_name)
    : Node(node_name)
{
    RCLCPP_INFO(this->get_logger(), "Defect Detection Node Initialising...");

    // Load parameters from YAML (declares if not present)
    loadParameters();

    // Initialise TF2 components for robot localisation
    tf_buffer_ = std::make_unique<tf2_ros::Buffer>(this->get_clock());
    tf_listener_ = std::make_shared<tf2_ros::TransformListener>(*tf_buffer_);
    RCLCPP_INFO(this->get_logger(), "TF2 buffer and listener initialised.");

    // Initialise defect manager
    defect_manager_ = std::make_unique<DefectManager>(
        log_file_path_,
        this->get_parameter("append_logs").as_bool(),
        this->get_parameter("min_duplicate_distance").as_double());

    RCLCPP_INFO(this->get_logger(), "Defect manager initialised with log file: %s",
                log_file_path_.c_str());

    // Initialise the detector algorithm using configured parameters
    initializeDetector();

    // Create service for controlling detection
    detect_srv_ = this->create_service<shared_interfaces::srv::Detecting>(
        "/detecting",
        std::bind(&DefectDetectionNode::detectingServiceCallback,
                  this, std::placeholders::_1, std::placeholders::_2));

    // Publisher for logging detected defects
    add_log_pub_ = this->create_publisher<shared_interfaces::msg::AddLog>("/add_log", 10);

    // Create image subscription
    image_sub_ = this->create_subscription<sensor_msgs::msg::Image>(
        input_image_topic_, 10,
        std::bind(&DefectDetectionNode::imageCallback, this, std::placeholders::_1));

    RCLCPP_INFO(this->get_logger(), "Subscribed to camera topic: %s", input_image_topic_.c_str());

    // Timer for periodic detection
    auto timer_period = std::chrono::milliseconds(static_cast<int>(1000.0 / detection_rate_));
    detection_timer_ = this->create_wall_timer(timer_period,
                                               std::bind(&DefectDetectionNode::processDetection, this));

    RCLCPP_INFO(this->get_logger(),
                "Detection timer created at %.2f Hz.", detection_rate_);
    RCLCPP_INFO(this->get_logger(), "Defect Detection Node initialised successfully!");
}

// Destructor - ensures all detected defects are saved before shutdown.
DefectDetectionNode::~DefectDetectionNode()
{
    RCLCPP_INFO(this->get_logger(), "Shutting down Defect Detection Node...");

    if (defect_manager_)
    {
        RCLCPP_INFO(this->get_logger(), "Saving defects to file...");
        if (defect_manager_->saveToFile())
        {
            RCLCPP_INFO(this->get_logger(), "✓ Defects saved successfully.");
        }
        else
        {
            RCLCPP_ERROR(this->get_logger(), "✗ Failed to save defects.");
        }
    }

    RCLCPP_INFO(this->get_logger(), "Defect Detection Node shutdown complete.");
}

// PARAMETER DECLARATION AND INITIALISATION

void DefectDetectionNode::loadParameters()
{
    RCLCPP_INFO(this->get_logger(), "Loading parameters...");

    // General parameters
    base_frame_ = this->declare_parameter<std::string>("base_frame", "camera_link");
    map_frame_ = this->declare_parameter<std::string>("map_frame", "map");
    detection_mode_ = this->declare_parameter<std::string>("detection_mode", "RGB");
    log_file_path_ = this->declare_parameter<std::string>("log_file_path", "logs/defect_log.txt");
    input_image_topic_ = this->declare_parameter<std::string>("input_image_topic", "/camera/image_raw");
    detection_result_topic_ = this->declare_parameter<std::string>("detection_result_topic", "/defect_detector/detections");
    output_directory_ = this->declare_parameter<std::string>("output_directory", "saved_crops/");

    // Boolean flags
    save_debug_images_ = this->declare_parameter<bool>("save_debug_images", true);
    enable_filtering_ = this->declare_parameter<bool>("enable_filtering", true);
    append_logs_ = this->declare_parameter<bool>("append_logs", true);
    publish_summary_ = this->declare_parameter<bool>("publish_summary", true);

    // Detection parameters
    binary_threshold_ = this->declare_parameter<int>("binary_threshold", 120);
    min_contour_area_ = this->declare_parameter<int>("min_contour_area", 80);
    max_contour_area_ = this->declare_parameter<int>("max_contour_area", 10000);
    blur_kernel_size_ = this->declare_parameter<int>("blur_kernel_size", 5);

    // Filtering parameters
    crop_x_ = this->declare_parameter<int>("crop_x", 100);
    crop_y_ = this->declare_parameter<int>("crop_y", 150);
    crop_width_ = this->declare_parameter<int>("crop_width", 250);
    crop_height_ = this->declare_parameter<int>("crop_height", 250);

    // Detection history and rate
    max_defect_history_ = this->declare_parameter<int>("max_defect_history", 100);
    detection_rate_ = this->declare_parameter<double>("detection_rate", 5.0);

    // HSV & defect thresholds
    double top_crop_ratio = this->declare_parameter<double>("top_crop_ratio", 0.1);
    double bottom_crop_ratio = this->declare_parameter<double>("bottom_crop_ratio", 0.9);
    int red_pixel_threshold = this->declare_parameter<int>("red_pixel_threshold", 500);
    int blue_pixel_threshold = this->declare_parameter<int>("blue_pixel_threshold", 500);
    double red_defect_severity = this->declare_parameter<double>("red_defect_severity", 0.8);
    double blue_defect_severity = this->declare_parameter<double>("blue_defect_severity", 0.6);

    // HSV bounds (load as long and convert to int)
    auto lower_red_1_long = this->declare_parameter<std::vector<long>>("lower_red_1", {0, 120, 70});
    auto upper_red_1_long = this->declare_parameter<std::vector<long>>("upper_red_1", {10, 255, 255});
    auto lower_red_2_long = this->declare_parameter<std::vector<long>>("lower_red_2", {170, 120, 70});
    auto upper_red_2_long = this->declare_parameter<std::vector<long>>("upper_red_2", {180, 255, 255});
    auto lower_blue_long  = this->declare_parameter<std::vector<long>>("lower_blue", {100, 120, 70});
    auto upper_blue_long  = this->declare_parameter<std::vector<long>>("upper_blue", {140, 255, 255});

    // Convert vectors to int
    std::vector<int> lower_red_1(lower_red_1_long.begin(), lower_red_1_long.end());
    std::vector<int> upper_red_1(upper_red_1_long.begin(), upper_red_1_long.end());
    std::vector<int> lower_red_2(lower_red_2_long.begin(), lower_red_2_long.end());
    std::vector<int> upper_red_2(upper_red_2_long.begin(), upper_red_2_long.end());
    std::vector<int> lower_blue(lower_blue_long.begin(), lower_blue_long.end());
    std::vector<int> upper_blue(upper_blue_long.begin(), upper_blue_long.end());

    // Store as member parameters (for use in initialization)
    detector_ = std::make_unique<DefectDetector>(
        top_crop_ratio, bottom_crop_ratio,
        red_pixel_threshold, blue_pixel_threshold,
        red_defect_severity, blue_defect_severity,
        lower_red_1, upper_red_1,
        lower_red_2, upper_red_2,
        lower_blue, upper_blue
    );

    RCLCPP_INFO(this->get_logger(), "Parameters loaded successfully.");
}

// DETECTOR INITIALISATION

void DefectDetectionNode::initializeDetector()
{
    RCLCPP_INFO(this->get_logger(), "Initializing Defect Detector...");

    if (!detector_)
    {
        RCLCPP_ERROR(this->get_logger(), "Detector not initialized properly (nullptr).");
        return;
    }

    if (enable_filtering_)
    {
        filter_ = std::make_unique<DefectFiltering>(0.1, 0.9);
        RCLCPP_INFO(this->get_logger(), "Defect filtering enabled.");
    }

    defect_manager_ = std::make_unique<DefectManager>(log_file_path_, append_logs_, 0.15);
    detection_enabled_ = true;

    RCLCPP_INFO(this->get_logger(), "Defect detection node fully initialized.");
}

// SERVICE CALLBACKS

// Handles requests to start or stop defect detection.
void DefectDetectionNode::detectingServiceCallback(
    const std::shared_ptr<shared_interfaces::srv::Detecting::Request> req,
    std::shared_ptr<shared_interfaces::srv::Detecting::Response> res)
{
    if (req->command == "start_detecting")
    {
        detection_enabled_ = true;
        res->success = true;
        RCLCPP_INFO(this->get_logger(), "Detection started.");
    }
    else if (req->command == "stop_detecting")
    {
        detection_enabled_ = false;
        res->success = true;
        RCLCPP_INFO(this->get_logger(), "Detection stopped.");
    }
    else
    {
        RCLCPP_WARN(this->get_logger(),
                    "Unknown detecting command: %s", req->command.c_str());
        res->success = false;
    }
}

// IMAGE CALLBACK

// Stores the latest image for timer-based detection processing.
void DefectDetectionNode::imageCallback(const sensor_msgs::msg::Image::SharedPtr msg)
{
    latest_image_ = msg;
}

// DETECTION PROCESSING

// Executes detection if enabled and new image data is available.
void DefectDetectionNode::processDetection()
{
    if (!detection_enabled_)
    {
        return;
    }

    if (!latest_image_)
    {
        RCLCPP_WARN(this->get_logger(), "No image received yet for detection.");
        return;
    }

    auto robot_pose_opt = getRobotPose();
    if (!robot_pose_opt)
    {
        RCLCPP_WARN(this->get_logger(), "Could not get robot pose for detection.");
        return;
    }

    auto robot_pose = robot_pose_opt.value();
    auto defect_opt = detector_->detect(*latest_image_, robot_pose);

    if (defect_opt)
    {
        bool added = defect_manager_->addDefect(defect_opt.value());

        if (added)
        {
            RCLCPP_INFO(this->get_logger(),
                        "Defect detected: %s at (%.2f, %.2f)",
                        defect_opt->type.c_str(),
                        defect_opt->x,
                        defect_opt->y);

            shared_interfaces::msg::AddLog log_msg;
            log_msg.task_type = "defect";
            log_msg.pose = robot_pose;
            log_msg.complete = true;

            add_log_pub_->publish(log_msg);
        }
    }
    else
    {
        RCLCPP_INFO(this->get_logger(), "No defect detected in the latest image.");
    }
}

// ROBOT POSE RETRIEVAL

// Retrieves the robot's pose using TF2 lookup between map and base frames.
std::optional<geometry_msgs::msg::PoseStamped> DefectDetectionNode::getRobotPose()
{
    try
    {
        geometry_msgs::msg::TransformStamped transform =
            tf_buffer_->lookupTransform(map_frame_, base_frame_, tf2::TimePointZero);

        geometry_msgs::msg::PoseStamped pose_stamped;
        pose_stamped.header = transform.header;
        pose_stamped.pose.position.x = transform.transform.translation.x;
        pose_stamped.pose.position.y = transform.transform.translation.y;
        pose_stamped.pose.position.z = transform.transform.translation.z;
        pose_stamped.pose.orientation = transform.transform.rotation;

        return pose_stamped;
    }
    catch (tf2::TransformException &ex)
    {
        RCLCPP_DEBUG(this->get_logger(), "TF lookup failed: %s", ex.what());
        return std::nullopt;
    }
}

// MAIN FUNCTION

// Entry point for the Defect Detection Node.
int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<DefectDetectionNode>();
    RCLCPP_INFO(node->get_logger(), "Defect Detection Node spinning...");
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}
