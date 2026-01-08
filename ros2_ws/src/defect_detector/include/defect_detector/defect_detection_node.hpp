// MTRX3760 2025 Project 2: Warehouse Robot DevKit
// File: defect_detection_node.hpp
// Author(s): Will Rumi 
//
// This header defines the DefectDetectionNode class. It represents a ROS2 node
// responsible for subscribing to camera and pose data, performing defect
// detection, logging results, and providing service control over the detection
// process.

#ifndef DEFECT_DETECTION_NODE_HPP
#define DEFECT_DETECTION_NODE_HPP

#include <rclcpp/rclcpp.hpp>
#include <memory>
#include <string>
#include <optional>

#include <sensor_msgs/msg/image.hpp>
#include <geometry_msgs/msg/pose_stamped.hpp>
#include <tf2_ros/buffer.h>
#include <tf2_ros/transform_listener.h>

#include "shared_interfaces/srv/detecting.hpp"
#include "shared_interfaces/msg/add_log.hpp"

#include "defect_detector/defect_detector.hpp"
#include "defect_detector/defect_filtering.hpp"
#include "defect_detector/defect_manager.hpp"

class DefectDetectionNode : public rclcpp::Node
{
    public:
        explicit DefectDetectionNode(const std::string &node_name = "defect_detection_node");
        ~DefectDetectionNode() override;
    private:
        // Core Methods
        void loadParameters();
        void initializeDetector();
        void imageCallback(const sensor_msgs::msg::Image::SharedPtr msg);
        void processDetection();

        // Service callback to enable or disable detection
        void detectingServiceCallback(
            const std::shared_ptr<shared_interfaces::srv::Detecting::Request> req,
            std::shared_ptr<shared_interfaces::srv::Detecting::Response> res);

        // Get robot pose from TF
        std::optional<geometry_msgs::msg::PoseStamped> getRobotPose();

        // ROS Interfaces
        rclcpp::Subscription<sensor_msgs::msg::Image>::SharedPtr image_sub_;
        rclcpp::Publisher<shared_interfaces::msg::AddLog>::SharedPtr add_log_pub_;
        rclcpp::Service<shared_interfaces::srv::Detecting>::SharedPtr detect_srv_;
        rclcpp::TimerBase::SharedPtr detection_timer_;

        // TF Utilities
        std::unique_ptr<tf2_ros::Buffer> tf_buffer_;
        std::shared_ptr<tf2_ros::TransformListener> tf_listener_;

        // Core Components
        std::unique_ptr<DefectDetector> detector_;
        std::unique_ptr<DefectFiltering> filter_;
        std::unique_ptr<DefectManager> defect_manager_;

        // Internal State
        sensor_msgs::msg::Image::SharedPtr latest_image_;

        // Parameters
        std::string base_frame_;
        std::string map_frame_;
        std::string detection_mode_;
        std::string log_file_path_;
        std::string input_image_topic_;
        std::string detection_result_topic_;
        std::string output_directory_;

        bool save_debug_images_;
        bool enable_filtering_;
        bool append_logs_;
        bool publish_summary_;

        int binary_threshold_;
        int min_contour_area_;
        int max_contour_area_;
        int blur_kernel_size_;
        int crop_x_;
        int crop_y_;
        int crop_width_;
        int crop_height_;
        int max_defect_history_;

        bool detection_enabled_;

        double detection_rate_;
    };

#endif // DEFECT_DETECTION_NODE_HPP
