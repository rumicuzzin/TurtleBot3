// MTRX3760 2025 Project 2: Warehouse Robot DevKit
// File: user_interface.hpp
// Author(s): Matylda Hayne
//
// This header defines the UserInterface class for the Pascal GUI. It declares
// all member variables and functions required to manage the ImGui-based user
// interface, handle ROS 2 communication, texture resources, event handling, and
// map interaction for the warehouse robot system.

#ifndef USER_INTERFACE_HPP
#define USER_INTERFACE_HPP

#include <rclcpp/rclcpp.hpp>
#include <shared_interfaces/srv/robot_type.hpp>
#include <std_msgs/msg/int32.hpp>
#include <std_msgs/msg/string.hpp>

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <imgui.h>

#include <string>
#include <vector>
#include <atomic>
#include <array>

class UserInterface
{
public:
    UserInterface();
    ~UserInterface();

    bool Initialize();
    void Run();

private:
    // ROS 2
    rclcpp::Node::SharedPtr node_;
    rclcpp::Client<shared_interfaces::srv::RobotType>::SharedPtr client_;
    rclcpp::Subscription<std_msgs::msg::Int32>::SharedPtr battery_sub_;
    rclcpp::Subscription<std_msgs::msg::String>::SharedPtr current_type_sub_;

    // Data
    std::atomic<int> battery_level_{100};
    std::string current_type_{"None"};

    // Window and rendering
    GLFWwindow *window_{nullptr};

    // Paths and resources
    std::string package_share_dir_;
    std::string image_path_;
    std::string pascal_intro_;
    std::string pascal_serial_;

    // Textures
    GLuint pascal_texture_{0};
    int pascal_width_{0};
    int pascal_height_{0};

    GLuint map_texture_{0};
    int map_w_{0};
    int map_h_{0};
    double map_resolution_{0.05};
    std::array<double, 3> map_origin_{0.0, 0.0, 0.0};
    std::vector<unsigned char> map_data_;

    // Map click markers
    std::vector<ImVec2> map_markers_;
    bool has_click_{false};
    double last_world_x_{0.0};
    double last_world_y_{0.0};

    // UI state
    bool mode_locked_{false};
    bool flagged_startup_{false};
    int sequence_number_{0};

    // Fonts
    ImFont *default_font_{nullptr};
    ImFont *bold_font_{nullptr};
    ImFont *big_bold_font_{nullptr};
    ImFont *italic_font_{nullptr};
    ImFont *big_font_{nullptr};
    ImFont *medium_font_{nullptr};
    ImFont *mini_font_{nullptr};
    ImFont *mini_italic_font_{nullptr};

    // Temporary storage for YAML data
    std::vector<std::string> temp_storage_;
};

#endif // USER_INTERFACE_HPP
