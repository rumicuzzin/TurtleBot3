// MTRX3760 2025 Project 2: Warehouse Robot DevKit
// File: defect_detector.cpp
// Author(s): Will Rumi
//
// This file implements the DefectDetector class. It converts ROS camera images
// to OpenCV format, applies HSV filtering, and classifies red or blue defects
// based on configurable colour thresholds.

#include "defect_detector/defect_detector.hpp"
#include <sensor_msgs/image_encodings.hpp>
#include <opencv2/imgproc.hpp>
#include <cv_bridge/cv_bridge.hpp>
#include <cmath>
#include <algorithm>
#include <rclcpp/rclcpp.hpp>

// CONSTRUCTOR

// Constructs the detector and initialises parameters and filtering.
DefectDetector::DefectDetector(double top_crop_ratio, double bottom_crop_ratio,
    int red_pixel_threshold, int blue_pixel_threshold, double red_defect_severity,
    double blue_defect_severity, const std::vector<int>& lower_red_1,
    const std::vector<int>& upper_red_1, const std::vector<int>& lower_red_2,
    const std::vector<int>& upper_red_2, const std::vector<int>& lower_blue,
    const std::vector<int>& upper_blue)
    : top_crop_ratio_(top_crop_ratio),
      bottom_crop_ratio_(bottom_crop_ratio),
      red_pixel_threshold_(red_pixel_threshold),
      blue_pixel_threshold_(blue_pixel_threshold),
      red_defect_severity_(red_defect_severity),
      blue_defect_severity_(blue_defect_severity),
      lower_red_1_(lower_red_1),
      upper_red_1_(upper_red_1),
      lower_red_2_(lower_red_2),
      upper_red_2_(upper_red_2),
      lower_blue_(lower_blue),
      upper_blue_(upper_blue)
{
    RCLCPP_INFO(rclcpp::get_logger("DefectDetector"), 
        "DefectDetector initialised with thresholds - Red: %d, Blue: %d",
        red_pixel_threshold_, blue_pixel_threshold_);
}

// MAIN DETECTION ENTRY POINT

// Performs RGB-to-HSV conversion, cropping, and invokes colour detection.
std::optional<Defect> DefectDetector::detect(const sensor_msgs::msg::Image& image,
    const geometry_msgs::msg::PoseStamped& robot_pose)
{
    // Convert ROS image message to OpenCV matrix
    cv_bridge::CvImagePtr cv_ptr = cv_bridge::toCvCopy(image, sensor_msgs::image_encodings::BGR8);
    cv::Mat frame = cv_ptr->image;

    // Apply top/bottom cropping ratios (to reduce noise)
    const int top_crop = static_cast<int>(frame.rows * top_crop_ratio_);
    const int bottom_crop = static_cast<int>(frame.rows * (1.0 - bottom_crop_ratio_));
    const cv::Rect roi(0, top_crop, frame.cols, bottom_crop - top_crop);
    cv::Mat cropped = frame(roi);

    // Convert to HSV for robust colour segmentation
    cv::Mat hsv_image;
    cv::cvtColor(cropped, hsv_image, cv::COLOR_BGR2HSV);

    return detectFromHSV(hsv_image, robot_pose);
}

// HSV COLOUR-BASED DEFECT CLASSIFICATION

// Performs HSV filtering and classifies detected colour blobs.
std::optional<Defect> DefectDetector::detectFromHSV(const cv::Mat& hsv_image,
    const geometry_msgs::msg::PoseStamped& robot_pose)
{
    // Red Colour Mask
    cv::Mat lower_red_mask, upper_red_mask;
    cv::inRange(hsv_image,
                cv::Scalar(lower_red_1_[0], lower_red_1_[1], lower_red_1_[2]),
                cv::Scalar(upper_red_1_[0], upper_red_1_[1], upper_red_1_[2]),
                lower_red_mask);

    cv::inRange(hsv_image,
                cv::Scalar(lower_red_2_[0], lower_red_2_[1], lower_red_2_[2]),
                cv::Scalar(upper_red_2_[0], upper_red_2_[1], upper_red_2_[2]),
                upper_red_mask);

    cv::Mat red_mask = lower_red_mask | upper_red_mask;

    // Blue Colour Mask
    cv::Mat blue_mask;
    cv::inRange(hsv_image,
                cv::Scalar(lower_blue_[0], lower_blue_[1], lower_blue_[2]),
                cv::Scalar(upper_blue_[0], upper_blue_[1], upper_blue_[2]),
                blue_mask);

    // Count number of colour pixels
    const int red_pixels = cv::countNonZero(red_mask);
    const int blue_pixels = cv::countNonZero(blue_mask);

    // Defect Classification
    if (red_pixels > red_pixel_threshold_)
    {
        return Defect{
            robot_pose.pose.position.x,
            robot_pose.pose.position.y,
            "red_defect",
            red_defect_severity_};
    }

    if (blue_pixels > blue_pixel_threshold_)
    {
        return Defect{
            robot_pose.pose.position.x,
            robot_pose.pose.position.y,
            "blue_defect",
            blue_defect_severity_};
    }
    return std::nullopt;
}
