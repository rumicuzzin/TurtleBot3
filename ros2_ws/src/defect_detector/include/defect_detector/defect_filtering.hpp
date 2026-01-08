
// MTRX3760 2025 Project 2: Warehouse Robot DevKit
// File: defect_filtering.hpp
// Author(s): Will Rumi
//
// This header defines the DefectFiltering class. It handles pre-processing of
// camera images used for defect detection by cropping the image and dividing it
// into sections for region-based colour analysis.

#ifndef DEFECT_FILTERING_HPP
#define DEFECT_FILTERING_HPP

#include <rclcpp/rclcpp.hpp>
#include <sensor_msgs/msg/image.hpp>
#include <geometry_msgs/msg/pose_stamped.hpp>
#include <opencv2/core.hpp>
#include <vector>
#include <string>
#include <optional>
#include "defect_detector/defect.hpp"

class DefectFiltering
{
    public:
        // Constructor
        DefectFiltering(double top_crop_ratio, double bottom_crop_ratio);

        cv::Mat applyCrop(const cv::Mat &full_image);
        void saveCroppedImage(const cv::Mat &cropped_image, const std::string &filename);

    private:
        double top_crop_ratio_;
        double bottom_crop_ratio_;
};

#endif // DEFECT_FILTERING_HPP
