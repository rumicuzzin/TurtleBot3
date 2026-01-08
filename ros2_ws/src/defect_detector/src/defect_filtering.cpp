
// MTRX3760 2025 Project 2: Warehouse Robot DevKit
// File: defect_filtering.cpp
// Author(s): Will Rumi
//
// This file implements the DefectFiltering class. It provides methods for
// cropping camera frames and dividing them into zones for simplified analysis
// by the defect detection pipeline.

#include "defect_detector/defect_filtering.hpp"
#include <opencv2/imgproc.hpp>
#include <opencv2/imgcodecs.hpp>
#include <filesystem>
#include <rclcpp/rclcpp.hpp>

// IMPLEMENTATION OF DEFECT FILTERING CLASS

// Constructs the filter with top and bottom crop ratios
DefectFiltering::DefectFiltering(double top_crop_ratio, double bottom_crop_ratio)
    : top_crop_ratio_(top_crop_ratio), bottom_crop_ratio_(bottom_crop_ratio)
{
    RCLCPP_INFO(rclcpp::get_logger("DefectFiltering"),
        "Initialised with top_crop_ratio=%.2f, bottom_crop_ratio=%.2f",
        top_crop_ratio_, bottom_crop_ratio_);
}

// Crops the input image by removing fixed top and bottom regions
cv::Mat DefectFiltering::applyCrop(const cv::Mat &full_image)
{
    if (full_image.empty())
    {
        return {};
    }

    int top_crop = static_cast<int>(full_image.rows * top_crop_ratio_);
    int bottom_crop = static_cast<int>(full_image.rows * (1.0 - bottom_crop_ratio_));
    cv::Rect roi(0, top_crop, full_image.cols, bottom_crop - top_crop);

    return full_image(roi);
}

// Saves a given image to disk for debugging purposes
void DefectFiltering::saveCroppedImage(const cv::Mat &cropped_image, const std::string &filename)
{
    namespace fs = std::filesystem;
    fs::path full_path = fs::path(filename);

    try
    {
        cv::imwrite(full_path.string(), cropped_image);
        RCLCPP_INFO(rclcpp::get_logger("DefectFiltering"),
                    "Saved cropped image to %s", full_path.string().c_str());
    }
    catch (const std::exception &e)
    {
        RCLCPP_WARN(rclcpp::get_logger("DefectFiltering"),
                    "Failed to save image: %s", e.what());
    }
}