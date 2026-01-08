cmake_minimum_required(VERSION 3.8)
project(map_manager)

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(rclcpp_lifecycle REQUIRED)
find_package(lifecycle_msgs REQUIRED)
find_package(std_srvs REQUIRED)
find_package(nav2_msgs REQUIRED)

# Build the node
add_executable(map_manager_node 
  src/map_manager_node.cpp
  src/lifecycle_service_manager.cpp
)
ament_target_dependencies(map_manager_node
  rclcpp rclcpp_lifecycle lifecycle_msgs std_srvs nav2_msgs)

target_include_directories(map_manager_node PUBLIC include)

# Install the binary
install(TARGETS map_manager_node
  RUNTIME DESTINATION lib/${PROJECT_NAME})

# Your existing data installs are fine:
install(DIRECTORY launch DESTINATION share/${PROJECT_NAME})
install(DIRECTORY config DESTINATION share/${PROJECT_NAME})
install(DIRECTORY maps DESTINATION share/${PROJECT_NAME})

ament_package()
