// MTRX3760 2025 Project 2: Warehouse Robot DevKit
// File: perception_node.h
// Author(s): Natalie Brown
//
// Defines the PerceptionNode class responsible for interpreting sensor data.
// It subscribes to LaserScan and Odometry, computes wall distances and angles,
// and publishes structured wall and pose information for higher-level modules.

#ifndef PERCEPTION_NODE_H_
#define PERCEPTION_NODE_H_

#include <rclcpp/rclcpp.hpp>
#include <sensor_msgs/msg/laser_scan.hpp> 
#include <sensor_msgs/msg/image.hpp>
#include <nav_msgs/msg/odometry.hpp>  
#include <geometry_msgs/msg/pose2_d.hpp>   
#include <std_msgs/msg/float32.hpp> 
#include <cv_bridge/cv_bridge.hpp>
#include <opencv2/opencv.hpp>
#include <sensor_msgs/image_encodings.hpp>
#include <shared_interfaces/msg/goal_info.hpp>
#include <cmath>
#include <algorithm>

#include <perception_logic.h>
#include <shared_interfaces/msg/wall_info.hpp>

using std::placeholders::_1;

class PerceptionNode : public rclcpp::Node
{
public:
    PerceptionNode();

private:
    // Receives odometry data from the /odom topic
    rclcpp::Subscription<nav_msgs::msg::Odometry>::SharedPtr odom_sub_;

    // Publishes the robot’s planar pose (x, y, heading) on /pose2d
    rclcpp::Publisher<geometry_msgs::msg::Pose2D>::SharedPtr pose_;

    // Updates the internal pose of the robot using odometry feedback
    void odom_callback(const nav_msgs::msg::Odometry::SharedPtr msg);
};

#endif  // PERCEPTION_NODE_H_
