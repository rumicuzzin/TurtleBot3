#ifndef ROBOT_NODE_H
#define ROBOT_NODE_H

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/int32.hpp"
#include "std_msgs/msg/string.hpp"
#include "example_interfaces/srv/trigger.hpp"
#include "robot_logic.h"

class RobotNode : public rclcpp::Node {
    public:
        explicit RobotNode(const std::string &start_mode);
        std::string start_mode_;
    
    private:
        rclcpp::Subscription<std_msgs::msg::Int32>::SharedPtr battery_sub_;
        rclcpp::Subscription<std_msgs::msg::String>::SharedPtr gui_sub_;
        rclcpp::Service<example_interfaces::srv::Trigger>::SharedPtr mode_service_;
        rclcpp::TimerBase::SharedPtr timer_;

        std::shared_ptr<RobotLogic> logic_;

        void batteryCallback(const std_msgs::msg::Int32::SharedPtr msg);
        void guiCallback(const std_msgs::msg::String::SharedPtr msg);
        void modeServiceCallback(
            const std::shared_ptr<example_interfaces::srv::Trigger::Request> request,
            std::shared_ptr<example_interfaces::srv::Trigger::Response> response);
        void timerCallback();
};

#endif // ROBOT_NODE_H