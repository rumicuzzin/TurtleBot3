// MTRX3760 2025 Project 2: Warehouse Robot DevKit
// File: defect.hpp
// Author(s): Will Rumi
//
// This header defines the Defect struct. It stores the detected defect’s
// position, classification, and severity level for logging and analysis
// within the warehouse inspection system.

#ifndef DEFECT_HPP
#define DEFECT_HPP

#include <string>

// STRUCT DEFINITION

// Represents a single detected defect, including its position in world
// coordinates, classification type, and severity rating.
struct Defect
{
    double x;             // X-coordinate in world space (metres)
    double y;             // Y-coordinate in world space (metres)
    std::string type;     // Defect classification label (e.g., "red_defect")
    double severity;      // Numeric severity score (e.g., 1–5)
};

#endif // DEFECT_HPP
