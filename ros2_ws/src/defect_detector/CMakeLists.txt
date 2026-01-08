cmake_minimum_required(VERSION 3.8)
project(defect_detector)

# COMPILER SETTINGS
if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# FIND DEPENDENCIES
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(tf2_ros REQUIRED)
find_package(tf2_geometry_msgs REQUIRED)
find_package(OpenCV REQUIRED)
find_package(cv_bridge REQUIRED)
find_package(shared_interfaces REQUIRED)

# INCLUDE DIRECTORIES
include_directories(
  include
  ${OpenCV_INCLUDE_DIRS}
  ${cv_bridge_INCLUDE_DIRS}
)

# SOURCE FILES
set(SRC_FILES
  src/defect_detection_node.cpp
  src/defect_manager.cpp
  src/defect_detector.cpp
  src/defect_filtering.cpp
)

# CREATE EXECUTABLE
add_executable(defect_detection_node ${SRC_FILES})

# Link all necessary dependencies
ament_target_dependencies(defect_detection_node
  rclcpp
  sensor_msgs
  geometry_msgs
  tf2_ros
  tf2_geometry_msgs
  cv_bridge
  shared_interfaces
)

# Explicitly link OpenCV libraries (for image processing)
target_link_libraries(defect_detection_node
  ${OpenCV_LIBS}
)

ament_export_include_directories(include)

# INSTALL TARGETS
install(TARGETS defect_detection_node
  DESTINATION lib/${PROJECT_NAME}
)

# Install header files
install(DIRECTORY include/
  DESTINATION include
)

# Install launch/config files if present
install(DIRECTORY launch/
  DESTINATION share/${PROJECT_NAME}
  OPTIONAL
)

# Uncomment if you later include config files
# install(DIRECTORY config/
#   DESTINATION share/${PROJECT_NAME}/config
# )

# TESTING
if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  ament_lint_auto_find_test_dependencies()
endif()

# EXPORT PACKAGE
ament_export_dependencies(
  rclcpp
  sensor_msgs
  geometry_msgs
  tf2_ros
  tf2_geometry_msgs
  cv_bridge
  OpenCV
  shared_interfaces
)

ament_package()
