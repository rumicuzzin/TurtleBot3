cmake_minimum_required(VERSION 3.8)
project(user_interface)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# ------------------------------------------------------------------------------
# Dependencies
# ------------------------------------------------------------------------------
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(ament_index_cpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(shared_interfaces REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(nav_msgs REQUIRED)
find_package(OpenGL REQUIRED)
find_package(PkgConfig REQUIRED)
find_package(GLEW REQUIRED)
find_package(yaml-cpp REQUIRED)

pkg_check_modules(GLFW REQUIRED glfw3)

# ------------------------------------------------------------------------------
# Include dirs (make vendor/ and vendor/stb/ visible)
# ------------------------------------------------------------------------------
include_directories(
  include
  vendor
  vendor/stb
  vendor/imgui
  vendor/imgui/backends
  ${GLFW_INCLUDE_DIRS}
  ${GLEW_INCLUDE_DIRS}
)

# ------------------------------------------------------------------------------
# Library: user_interface_lib
#   - this is the class-based UI (src/user_interface.cpp)
#   - we put ImGui sources here too, so anything that links this lib can draw
# ------------------------------------------------------------------------------
add_library(user_interface_lib
  src/user_interface.cpp

  # ImGui core
  vendor/imgui/imgui.cpp
  vendor/imgui/imgui_draw.cpp
  vendor/imgui/imgui_widgets.cpp
  vendor/imgui/imgui_tables.cpp
  vendor/imgui/imgui_demo.cpp

  # ImGui backends
  vendor/imgui/backends/imgui_impl_glfw.cpp
  vendor/imgui/backends/imgui_impl_opengl3.cpp
)

target_link_libraries(user_interface_lib
  ${GLFW_LIBRARIES}
  ${GLEW_LIBRARIES}
  OpenGL::GL
  dl
  pthread
  yaml-cpp
)

ament_target_dependencies(user_interface_lib
  rclcpp
  std_msgs
  nav_msgs
  geometry_msgs
  shared_interfaces
  ament_index_cpp
)

# ------------------------------------------------------------------------------
# Executable: user_interface_bringup
#   - tiny main() that just creates/initializes/runs the UI class
# ------------------------------------------------------------------------------
add_executable(user_interface_bringup
  src/user_interface_bringup.cpp
)

target_link_libraries(user_interface_bringup
  user_interface_lib
)

ament_target_dependencies(user_interface_bringup
  rclcpp
)

# ------------------------------------------------------------------------------
# Install
# ------------------------------------------------------------------------------
install(TARGETS
  user_interface_bringup
  user_interface_lib
  DESTINATION lib/${PROJECT_NAME}
)

install(DIRECTORY include
  DESTINATION include
)

install(DIRECTORY launch/
  DESTINATION share/${PROJECT_NAME}/launch
)

install(DIRECTORY resources/
  DESTINATION share/${PROJECT_NAME}/resources
)

install(FILES
  resources/pascal_intro.txt
  resources/pascal_serial.txt
  DESTINATION share/${PROJECT_NAME}/resources
)

ament_package()
