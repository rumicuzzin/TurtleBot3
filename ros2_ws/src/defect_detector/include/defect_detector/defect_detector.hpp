
// MTRX3760 2025 Project 2: Warehouse Robot DevKit
// File: defect_detector.hpp
// Author(s): Will Rumi
//
// This header defines the DefectDetector class. It runs colour-based detection
// on camera images using HSV filtering to identify defects such as red or blue
// markers in the warehouse environment.

#ifndef DEFECT_DETECTOR_HPP
#define DEFECT_DETECTOR_HPP

#include <rclcpp/rclcpp.hpp>
#include <sensor_msgs/msg/image.hpp>
#include <geometry_msgs/msg/pose_stamped.hpp>
#include <opencv2/core.hpp>
#include <vector>
#include <optional>
#include "defect_detector/defect.hpp"

class DefectDetector
{
    public:
        // Constructor with all parameters
        DefectDetector(double top_crop_ratio, double bottom_crop_ratio,
            int red_pixel_threshold, int blue_pixel_threshold, double red_defect_severity,
            double blue_defect_severity, const std::vector<int> &lower_red_1,
            const std::vector<int> &upper_red_1, const std::vector<int> &lower_red_2,
            const std::vector<int> &upper_red_2, const std::vector<int> &lower_blue,
            const std::vector<int> &upper_blue);

        std::optional<Defect> detect(
            const sensor_msgs::msg::Image &image,
            const geometry_msgs::msg::PoseStamped &robot_pose);

    private:

        std::optional<Defect> detectFromHSV(
            const cv::Mat &hsv_image,
            const geometry_msgs::msg::PoseStamped &robot_pose);

        double top_crop_ratio_;
        double bottom_crop_ratio_;
        int red_pixel_threshold_;
        int blue_pixel_threshold_;
        double red_defect_severity_;
        double blue_defect_severity_;

        std::vector<int> lower_red_1_, upper_red_1_;
        std::vector<int> lower_red_2_, upper_red_2_;
        std::vector<int> lower_blue_, upper_blue_;
};

#endif // DEFECT_DETECTOR_HPP