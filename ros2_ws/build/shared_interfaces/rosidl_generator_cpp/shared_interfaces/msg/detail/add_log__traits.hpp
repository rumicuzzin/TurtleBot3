// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from shared_interfaces:msg/AddLog.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "shared_interfaces/msg/add_log.hpp"


#ifndef SHARED_INTERFACES__MSG__DETAIL__ADD_LOG__TRAITS_HPP_
#define SHARED_INTERFACES__MSG__DETAIL__ADD_LOG__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "shared_interfaces/msg/detail/add_log__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'pose'
#include "geometry_msgs/msg/detail/pose_stamped__traits.hpp"

namespace shared_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const AddLog & msg,
  std::ostream & out)
{
  out << "{";
  // member: task_type
  {
    out << "task_type: ";
    rosidl_generator_traits::value_to_yaml(msg.task_type, out);
    out << ", ";
  }

  // member: pose
  {
    out << "pose: ";
    to_flow_style_yaml(msg.pose, out);
    out << ", ";
  }

  // member: complete
  {
    out << "complete: ";
    rosidl_generator_traits::value_to_yaml(msg.complete, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const AddLog & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: task_type
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "task_type: ";
    rosidl_generator_traits::value_to_yaml(msg.task_type, out);
    out << "\n";
  }

  // member: pose
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "pose:\n";
    to_block_style_yaml(msg.pose, out, indentation + 2);
  }

  // member: complete
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "complete: ";
    rosidl_generator_traits::value_to_yaml(msg.complete, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const AddLog & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace shared_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use shared_interfaces::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const shared_interfaces::msg::AddLog & msg,
  std::ostream & out, size_t indentation = 0)
{
  shared_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use shared_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const shared_interfaces::msg::AddLog & msg)
{
  return shared_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<shared_interfaces::msg::AddLog>()
{
  return "shared_interfaces::msg::AddLog";
}

template<>
inline const char * name<shared_interfaces::msg::AddLog>()
{
  return "shared_interfaces/msg/AddLog";
}

template<>
struct has_fixed_size<shared_interfaces::msg::AddLog>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<shared_interfaces::msg::AddLog>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<shared_interfaces::msg::AddLog>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // SHARED_INTERFACES__MSG__DETAIL__ADD_LOG__TRAITS_HPP_
