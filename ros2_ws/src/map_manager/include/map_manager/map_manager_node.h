// MTRX3760 2025 Project 2: Warehouse Robot DevKit
// File: map_manager_node.h
// Author(s): Angus Mclean
//
// Thisfile declares the MapManagerNode class, which manages the runtime switching
// between SLAM and localization modes for a warehouse robot. It utilizes lifecycle
// service managers to control the states of SLAM, AMCL, and map_server nodes,
// and provides functionality to save maps via the map_saver service.   

#ifndef MAP_MANAGER__MAP_MANAGER_NODE_H_
#define MAP_MANAGER__MAP_MANAGER_NODE_H_

#include <memory>
#include <string>
#include <chrono>

#include <rclcpp/rclcpp.hpp>
#include <nav2_msgs/srv/save_map.hpp>

#include "map_manager/lifecycle_service_manager.h"

class MapManagerNode : public rclcpp::Node
{
public:
  explicit MapManagerNode(const rclcpp::NodeOptions & options = rclcpp::NodeOptions());

  bool switchToMapping();        // slam ON, amcl/map_server OFF
  bool switchToLocalization();   // slam OFF, amcl/map_server ON
  bool saveMap(const std::string & path);

private:
  // concrete helpers
  std::unique_ptr<LifecycleServiceManager> slam_;
  std::unique_ptr<LifecycleServiceManager> amcl_;
  std::unique_ptr<LifecycleServiceManager> map_server_;

  rclcpp::Client<nav2_msgs::srv::SaveMap>::SharedPtr save_map_cli_;

  bool ensureConfiguredAndActive (LifecycleServiceManager & n, std::chrono::milliseconds to);
  bool ensureDeactivatedAndCleaned(LifecycleServiceManager & n, std::chrono::milliseconds to);
};

#endif  // MAP_MANAGER__MAP_MANAGER_NODE_H_