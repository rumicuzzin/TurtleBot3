// MTRX3760 2025 Project 2: Warehouse Robot DevKit
// File: defect_manager.hpp
// Author(s): Will Rumi
// 
// This header defines the DefectManager class. The manager stores detected
// defects, prevents duplicates based on position, and can save/load them
// to/from a YAML file for use by the UI or logger node.

#ifndef DEFECT_MANAGER_HPP
#define DEFECT_MANAGER_HPP

#include "defect_detector/defect.hpp"
#include <rclcpp/rclcpp.hpp>
#include <vector>
#include <string>
#include <fstream>

class DefectManager
{
public:
    DefectManager(const std::string& log_file_path, bool append_logs = true,
        double min_duplicate_distance_ = 0.15); // default 15 cm

    bool addDefect(const Defect& defect);
    bool isDuplicate(const Defect& defect);

    bool saveToFile();
    bool loadFromFile();
    bool removeDefect(size_t defect_index);

private:
    std::string log_file_path_;
    bool append_logs_;
    double min_duplicate_distance_;
    std::vector<Defect> defects_;
};

#endif // DEFECT_MANAGER_HPP
