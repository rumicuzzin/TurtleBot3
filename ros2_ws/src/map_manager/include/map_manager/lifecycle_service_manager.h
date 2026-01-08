// MTRX3760 2025 Project 2: Warehouse Robot DevKit
// File: lifecycle_service_manager.h
// Author(s): Angus Mclean
//
// Declares the LifecycleServiceManager class, which provides an interface for
// managing the lifecycle of ROS 2 nodes. It encapsulates the logic for
// transitioning between different lifecycle states and provides a convenient
// API for interacting with the lifecycle services.

#ifndef LIFECYCLE_SERVICE_MANAGER_H_
#define LIFECYCLE_SERVICE_MANAGER_H_

#include <string>
#include <chrono>
#include <rclcpp/rclcpp.hpp>
#include <lifecycle_msgs/srv/change_state.hpp>
#include <lifecycle_msgs/srv/get_state.hpp>
#include <lifecycle_msgs/msg/state.hpp>
#include <lifecycle_msgs/msg/transition.hpp>


// ---------------- LifecycleServiceManager Declaration ----------------
class LifecycleServiceManager {
public:
  LifecycleServiceManager(rclcpp::Node & parent, const std::string & lifecycle_node_name);

  bool configure (std::chrono::milliseconds timeout);
  bool activate  (std::chrono::milliseconds timeout);
  bool deactivate(std::chrono::milliseconds timeout);
  bool cleanup   (std::chrono::milliseconds timeout);

  lifecycle_msgs::msg::State get_state(std::chrono::milliseconds timeout);
  const std::string & name() const { return name_; }

private:
  bool wait_for_services(std::chrono::milliseconds timeout);
  bool change_state(uint8_t transition_id, std::chrono::milliseconds timeout);

  // Member variables
  rclcpp::Node & parent_;
  std::string name_;
  rclcpp::Client<lifecycle_msgs::srv::ChangeState>::SharedPtr change_cli_;
  rclcpp::Client<lifecycle_msgs::srv::GetState>::SharedPtr    state_cli_;
};

#endif  // LIFECYCLE_SERVICE_MANAGER_H_