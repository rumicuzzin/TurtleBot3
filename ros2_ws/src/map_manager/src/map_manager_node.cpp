// MTRX3760 2025 Project 2: Warehouse Robot DevKit
// File: map_manager_node.cpp
// Author(s): Angus Mclean
//
// This file implements the MapManagerNode class, which manages the runtime switching
// between SLAM and localization modes for a warehouse robot. It utilizes lifecycle
// service managers to control the states of SLAM, AMCL, and map_server nodes,
// and provides functionality to save maps via the map_saver service.

#include "map_manager/map_manager_node.h"


// ---------------- MapManagerNode Implementation ----------------

// Constructor
MapManagerNode::MapManagerNode(const rclcpp::NodeOptions & options)
: rclcpp::Node("map_manager", options)
{
  const std::string slam_name       = this->declare_parameter<std::string>("slam_toolbox_node", "slam_toolbox");
  const std::string amcl_name       = this->declare_parameter<std::string>("amcl_node",          "amcl");
  const std::string map_server_name = this->declare_parameter<std::string>("map_server_node",    "map_server");
  const std::string saver_name      = this->declare_parameter<std::string>("map_saver_server",   "map_saver_server");

  slam_       = std::make_unique<LifecycleServiceManager>(*this, slam_name);
  amcl_       = std::make_unique<LifecycleServiceManager>(*this, amcl_name);
  map_server_ = std::make_unique<LifecycleServiceManager>(*this, map_server_name);

  save_map_cli_ = this->create_client<nav2_msgs::srv::SaveMap>(saver_name + "/save_map");

  // start in mapping mode at startup
  (void)switchToMapping();
}

// Ensure the node is configured and active
bool MapManagerNode::ensureConfiguredAndActive(LifecycleServiceManager & n, std::chrono::milliseconds to)
{
  auto st = n.get_state(to).id;
  if (st == lifecycle_msgs::msg::State::PRIMARY_STATE_UNCONFIGURED ||
      st == lifecycle_msgs::msg::State::PRIMARY_STATE_INACTIVE ||
      st == lifecycle_msgs::msg::State::PRIMARY_STATE_FINALIZED)
  {
    if (!n.configure(to)) return false;
    st = n.get_state(to).id;
  }
  if (st == lifecycle_msgs::msg::State::PRIMARY_STATE_INACTIVE) {
    if (!n.activate(to)) return false;
  }
  return n.get_state(to).id == lifecycle_msgs::msg::State::PRIMARY_STATE_ACTIVE;
}

// Ensure the node is deactivated and cleaned up
bool MapManagerNode::ensureDeactivatedAndCleaned(LifecycleServiceManager & n, std::chrono::milliseconds to)
{
  auto st = n.get_state(to).id;
  if (st == lifecycle_msgs::msg::State::PRIMARY_STATE_ACTIVE) {
    if (!n.deactivate(to)) return false;
    st = n.get_state(to).id;
  }
  if (st == lifecycle_msgs::msg::State::PRIMARY_STATE_INACTIVE) {
    if (!n.cleanup(to)) return false;
  }
  return n.get_state(to).id == lifecycle_msgs::msg::State::PRIMARY_STATE_UNCONFIGURED;
}

// Switch to MAPPING mode: SLAM ON, AMCL/map_server OFF
bool MapManagerNode::switchToMapping()
{
  RCLCPP_INFO(get_logger(), "Mode: MAPPING (slam ON, amcl/map_server OFF)");
  (void)ensureDeactivatedAndCleaned(*amcl_,       std::chrono::milliseconds(2000));
  (void)ensureDeactivatedAndCleaned(*map_server_, std::chrono::milliseconds(2000));
  const bool ok = ensureConfiguredAndActive(*slam_, std::chrono::milliseconds(3000));
  RCLCPP_INFO(get_logger(), "Mapping %s", ok ? "ready" : "failed");
  return ok;
}

// Switch to LOCALIZATION mode: SLAM OFF, AMCL/map_server ON
bool MapManagerNode::switchToLocalization()
{
  RCLCPP_INFO(get_logger(), "Mode: LOCALIZATION (slam OFF, amcl/map_server ON)");
  (void)ensureDeactivatedAndCleaned(*slam_, std::chrono::milliseconds(3000));
  const bool map_ok = ensureConfiguredAndActive(*map_server_, std::chrono::milliseconds(3000));
  const bool amcl_ok = ensureConfiguredAndActive(*amcl_, std::chrono::milliseconds(3000));
  const bool ok = map_ok && amcl_ok;
  RCLCPP_INFO(get_logger(), "Localization %s", ok ? "ready" : "failed");
  return ok;
}

// Save the current map to the specified path
bool MapManagerNode::saveMap(const std::string & path)
{
  if (!save_map_cli_->wait_for_service(std::chrono::milliseconds(2000))) {
    RCLCPP_WARN(get_logger(), "save_map service not available");
    return false;
  }

  auto req = std::make_shared<nav2_msgs::srv::SaveMap::Request>();
  req->map_url = path;
  req->image_format = "pgm";
  req->map_mode = "trinary";
  req->free_thresh = 0.25;
  req->occupied_thresh = 0.65;

  auto fut = save_map_cli_->async_send_request(req);
  if (fut.wait_for(std::chrono::milliseconds(5000)) != std::future_status::ready) {
    RCLCPP_WARN(get_logger(), "Timeout waiting for save_map");
    return false;
  }
  return fut.get()->result;
}

// ---------------- Main Function ----------------
int main(int argc, char ** argv)
{
  rclcpp::init(argc, argv);
  auto node = std::make_shared<MapManagerNode>();
  rclcpp::spin(node);
  rclcpp::shutdown();
  return 0;
}