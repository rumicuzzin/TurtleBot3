/* 
TODO:
- make all the consts params
*/

#ifndef BATTERY_NODE_H
#define BATTERY_NODE_H

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/int32.hpp"
#include "shared_interfaces/srv/charging.hpp"

class BatteryNode : public rclcpp::Node
{
    public:
        BatteryNode();

    private:
        void timerCallback();
        void chargingCallback(
            const std::shared_ptr<shared_interfaces::srv::Charging::Request> req,
            std::shared_ptr<shared_interfaces::srv::Charging::Response> res);


        rclcpp::Service<shared_interfaces::srv::Charging>::SharedPtr charging_srv_;
        rclcpp::Publisher<std_msgs::msg::Int32>::SharedPtr battery_pub_;
        rclcpp::TimerBase::SharedPtr timer_;

        int32_t battery_level_ = 100;           // 0..100
        bool charging_ = false;
        bool depleting_ = false;
        // std::chrono::milliseconds tick_period_{500};
};

#endif  // BATTERY_NODE_HPP_
