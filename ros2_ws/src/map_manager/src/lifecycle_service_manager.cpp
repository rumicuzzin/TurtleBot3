// MTRX3760 2025 Project 2: Warehouse Robot DevKit
// File: lifecycle_service_manager.cpp
// Author(s): Angus Mclean
//
// Implements the LifecycleServiceManager class, which provides an interface for
// managing the lifecycle of ROS 2 nodes. It encapsulates the logic for
// transitioning between different lifecycle states and provides a convenient
// API for interacting with the lifecycle services.     

#include "map_manager/lifecycle_service_manager.h"

// ---------------- LifecycleServiceManager Implementation ----------------
// Constructor
LifecycleServiceManager::LifecycleServiceManager(rclcpp::Node & parent, const std::string & lifecycle_node_name)
: parent_(parent), name_(lifecycle_node_name)
{
  change_cli_ = parent_.create_client<lifecycle_msgs::srv::ChangeState>(name_ + "/change_state");
  state_cli_  = parent_.create_client<lifecycle_msgs::srv::GetState>(name_ + "/get_state");
}

// Wait for lifecycle services to be available
bool LifecycleServiceManager::wait_for_services(std::chrono::milliseconds timeout)
{
  const bool ok1 = change_cli_->wait_for_service(timeout);
  const bool ok2 = state_cli_->wait_for_service(timeout);
  if (!ok1 || !ok2) {
    RCLCPP_WARN(parent_.get_logger(), "Lifecycle services not ready for '%s'", name_.c_str());
    return false;
  }
  return true;
}

// Get current state of the lifecycle node
lifecycle_msgs::msg::State LifecycleServiceManager::get_state(std::chrono::milliseconds timeout)
{
  lifecycle_msgs::msg::State s;
  if (!wait_for_services(timeout)) {
    s.id = lifecycle_msgs::msg::State::PRIMARY_STATE_UNKNOWN;
    return s;
  }
  auto req = std::make_shared<lifecycle_msgs::srv::GetState::Request>();
  auto fut = state_cli_->async_send_request(req);
  if (fut.wait_for(timeout) != std::future_status::ready) {
    RCLCPP_WARN(parent_.get_logger(), "Timeout getting state from '%s'", name_.c_str());
    s.id = lifecycle_msgs::msg::State::PRIMARY_STATE_UNKNOWN;
    return s;
  }
  return fut.get()->current_state;
}

// Change the state of the lifecycle node
bool LifecycleServiceManager::change_state(uint8_t transition_id, std::chrono::milliseconds timeout)
{
  if (!wait_for_services(timeout)) return false;
  auto req = std::make_shared<lifecycle_msgs::srv::ChangeState::Request>();
  req->transition.id = transition_id;
  auto fut = change_cli_->async_send_request(req);
  if (fut.wait_for(timeout) != std::future_status::ready) {
    RCLCPP_WARN(parent_.get_logger(), "Timeout changing state on '%s' (transition %u)", name_.c_str(), transition_id);
    return false;
  }
  return fut.get()->success;
}

// State transition methods
bool LifecycleServiceManager::configure (std::chrono::milliseconds timeout) {
  return change_state(lifecycle_msgs::msg::Transition::TRANSITION_CONFIGURE, timeout);
}

bool LifecycleServiceManager::activate  (std::chrono::milliseconds timeout) {
  return change_state(lifecycle_msgs::msg::Transition::TRANSITION_ACTIVATE, timeout);
}
bool LifecycleServiceManager::deactivate(std::chrono::milliseconds timeout) {
  return change_state(lifecycle_msgs::msg::Transition::TRANSITION_DEACTIVATE, timeout);
}
bool LifecycleServiceManager::cleanup   (std::chrono::milliseconds timeout) {
  return change_state(lifecycle_msgs::msg::Transition::TRANSITION_CLEANUP, timeout);
}
