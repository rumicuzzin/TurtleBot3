cmake_minimum_required(VERSION 3.8)
project(perception_pkg)


#if(NOT CMAKE_CXX_STANDARD)
# set(CMAKE_CXX_STANDARD 17)
#endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# Find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(nav_msgs REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(shared_interfaces REQUIRED)
find_package(std_msgs REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(tf2 REQUIRED)
find_package(cv_bridge REQUIRED)
find_package(OpenCV REQUIRED)
find_package(example_interfaces REQUIRED)
find_package(rosidl_default_generators REQUIRED)

include_directories(${OpenCV_INCLUDE_DIRS}) 

# # --- Message generation ---
# rosidl_generate_interfaces(${PROJECT_NAME}
#   "msg/GoalInfo.msg"
# )
# rosidl_get_typesupport_target(cpp_typesupport_target "${PROJECT_NAME}" "rosidl_typesupport_cpp")

# Create the executable
add_executable(perception_node src/perception_node.cpp src/perception_logic.cpp)

# Link dependencies
ament_target_dependencies(perception_node
  rclcpp
  sensor_msgs
  nav_msgs
  shared_interfaces
  cv_bridge
  OpenCV
  example_interfaces
)
target_link_libraries(perception_node ${cpp_typesupport_target})

target_include_directories(perception_node PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>
)

# Install target so ROS can find it when you run ros2 run
install(TARGETS perception_node
  DESTINATION lib/${PROJECT_NAME}
)

# Export package to ament
ament_package()
