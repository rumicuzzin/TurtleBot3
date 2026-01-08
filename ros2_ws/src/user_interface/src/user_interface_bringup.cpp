// MTRX3760 2025 Project 2: Warehouse Robot DevKit
// File: user_interface_bringup.cpp
// Author(s): Matylda Hayne
//
// Entry point for the Pascal GUI. Initializes ROS 2, creates the UserInterface
// instance, and runs the GUI loop until shutdown.

#include "user_interface/user_interface.hpp"
#include "rclcpp/rclcpp.hpp"

int main(int argc, char **argv)
{
    // Initialize ROS 2
    rclcpp::init(argc, argv);

    // Create and run the Pascal UI
    UserInterface ui;
    if (!ui.Initialize()) {
        RCLCPP_ERROR(rclcpp::get_logger("user_interface_bringup"), "Failed to initialize Pascal UI.");
        return 1;
    }

    ui.Run();

    // Shutdown ROS and exit cleanly
    rclcpp::shutdown();
    return 0;
}
