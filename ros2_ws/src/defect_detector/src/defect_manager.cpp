// MTRX3760 2025 Project 2: Warehouse Robot DevKit
// File: defect_manager.cpp
// Author(s): Will Rumi
//
// This file implements the DefectManager class. It is responsible for storing
// unique defects and serialising them to a simple YAML-like format.

#include "defect_detector/defect_manager.hpp"
#include <cmath>
#include <filesystem>

// CONSTRUCTOR

DefectManager::DefectManager(const std::string& log_file_path, bool append_logs,
    double min_duplicate_distance) : log_file_path_(log_file_path),
    append_logs_(append_logs), min_duplicate_distance_(min_duplicate_distance)
{
    defects_.clear();

    // Create directory if it doesn't exist
    std::filesystem::create_directories(std::filesystem::path(log_file_path_).parent_path());

    RCLCPP_INFO(rclcpp::get_logger("DefectManager"),
        "DefectManager initialised: %s (append=%s, min_dist=%.2f)",
        log_file_path_.c_str(),
        append_logs_ ? "true" : "false",
        min_duplicate_distance_);
}

// ADDING AND DUPLICATE HANDLING

bool DefectManager::addDefect(const Defect& defect)
{
    try
    {
        // Skip if duplicate
        if (!defects_.empty() && isDuplicate(defect))
        {
            return false;
        }

        defects_.push_back(defect);
        return true;
    }
    catch (const std::exception& e)
    {
        RCLCPP_ERROR(rclcpp::get_logger("DefectManager"), "Failed to add defect: %s", e.what());
        return false;
    }
}

// Checks if the given defect is too close to an existing one
bool DefectManager::isDuplicate(const Defect& defect)
{
    for (const auto& existing_defect : defects_)
    {
        double dx = defect.x - existing_defect.x;
        double dy = defect.y - existing_defect.y;
        double distance = std::sqrt(dx * dx + dy * dy);

        if (distance < min_duplicate_distance_)
        {
            return true;
        }
    }
    return false;
}

// FILE SAVING AND LOADING

bool DefectManager::saveToFile()
{
    std::ofstream file;
    file.open(log_file_path_, append_logs_ ? std::ios::app : std::ios::out);

    if (!file.is_open())
    {
        RCLCPP_ERROR(rclcpp::get_logger("DefectManager"),
            "Could not open log file for writing: %s", log_file_path_.c_str());
        return false;
    }

    if (!append_logs_)
    {
        file << "defects:\n";
    }

    for (const auto& defect : defects_)
    {
        file << " - x: " << defect.x << "\n";
        file << "   y: " << defect.y << "\n";
        file << "   type: " << defect.type << "\n";
        file << "   severity: " << defect.severity << "\n";
    }

    file.close();
    return true;
}

bool DefectManager::loadFromFile()
{
    std::ifstream file(log_file_path_);
    if (!file.is_open())
    {
        return false;
    }
    defects_.clear();

    std::string line;
    bool first_line = true;
    Defect defect;

    while (std::getline(file, line))
    {
        if (first_line)
        {
            first_line = false;
            continue;
        }
        
        if (line.find("x:") != std::string::npos)
        {
            defect.x = std::stod(line.substr(line.find(":") + 1));
        }
        else if (line.find("y:") != std::string::npos)
        {
            defect.y = std::stod(line.substr(line.find(":") + 1));
        }
        else if (line.find("type:") != std::string::npos)
        {
            defect.type = line.substr(line.find(":") + 1);
        }
        else if (line.find("severity:") != std::string::npos)
        {
            defect.severity = std::stod(line.substr(line.find(":") + 1));
            defects_.push_back(defect);
        }
    }

    file.close();
    return true;
}

bool DefectManager::removeDefect(size_t defect_index)
{
    if (defect_index >= defects_.size())
    {
        return false;
    }

    defects_.erase(defects_.begin() + defect_index);
    return true;
}
