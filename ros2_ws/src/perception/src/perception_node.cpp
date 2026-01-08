
// MTRX3760 2025 Project 2: Warehouse Robot DevKit
// File: perception_node.cpp
// Author(s): Natalie Brown

// Implements the PerceptionNode class, which fuses LiDAR and odometry data to
// produce wall and pose information for other modules. It computes distances,
// wall angles, and 2D pose and publishes results to relevant topics.

#include <perception_node.h>

PerceptionNode::PerceptionNode() : Node("perception_node")
{
    declare_parameter<int>("queue_size", 10);
    queue_size_ = this->get_parameter("queue_size").as_int();

    // Subscribe to Odom and LiDAR data 
    odom_sub_ = create_subscription<nav_msgs::msg::Odometry>("/odom", queue_size_, 
        std::bind(&PerceptionNode::odom_callback,this,std::placeholders::_1));
   
    // Publishers
    pose_ = create_publisher<geometry_msgs::msg::Pose2D>("/pose2d", queue_size_);
      
    RCLCPP_INFO(get_logger(), "PerceptionNode started");
}

// Handle incoming Odometry messages
void PerceptionNode::odom_callback( const nav_msgs::msg::Odometry::SharedPtr msg)
{
    // Robot position (x, y)
    double x = msg->pose.pose.position.x;
    double y = msg->pose.pose.position.y;

    // Robot orientation 
    double qx = msg->pose.pose.orientation.x;
    double qy = msg->pose.pose.orientation.y;
    double qz = msg->pose.pose.orientation.z;
    double qw = msg->pose.pose.orientation.w;

    // Calculating yaw (rads)
    double yaw = std::atan2(2.0*(qw*qz+qx*qy), (1.0-2.0*(qy*qy+qz*qz)));

    // Publish pose
    geometry_msgs::msg::Pose2D pose_msg;
    pose_msg.x = x;
    pose_msg.y = y;
    pose_msg.theta = yaw;
    pose_->publish(pose_msg);
}


int main(int argc, char * argv[])
{
    rclcpp::init(argc, argv);   
    auto node = std::make_shared<PerceptionNode>(); 
    rclcpp::spin(node);      
    rclcpp::shutdown();  
    return 0;
}
