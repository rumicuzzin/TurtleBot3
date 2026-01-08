cmake_minimum_required(VERSION 3.8)
project(shared_interfaces)

# Compiler settings
if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# Find dependencies
find_package(ament_cmake REQUIRED)
find_package(rosidl_default_generators REQUIRED)
find_package(std_msgs REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(builtin_interfaces REQUIRED)
find_package(cv_bridge REQUIRED)

# Message and Service Definitions
rosidl_generate_interfaces(${PROJECT_NAME}
  "msg/AddLog.msg"
  "msg/CheckLog.msg"
  "srv/NavigationMode.srv"
  "srv/RobotType.srv"
  "srv/Detecting.srv"
  "srv/Charging.srv"
  DEPENDENCIES
    std_msgs
    geometry_msgs
    builtin_interfaces
)

# Export Dependencies
ament_export_dependencies(
  rosidl_default_runtime
  std_msgs
  geometry_msgs
  builtin_interfaces
  cv_bridge
)

# Testing
if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  set(ament_cmake_copyright_FOUND TRUE)
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()


# Package
ament_package()
