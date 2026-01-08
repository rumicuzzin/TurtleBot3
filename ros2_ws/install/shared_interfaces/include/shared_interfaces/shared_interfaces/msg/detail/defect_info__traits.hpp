// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from shared_interfaces:msg/DefectInfo.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "shared_interfaces/msg/defect_info.hpp"


#ifndef SHARED_INTERFACES__MSG__DETAIL__DEFECT_INFO__TRAITS_HPP_
#define SHARED_INTERFACES__MSG__DETAIL__DEFECT_INFO__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "shared_interfaces/msg/detail/defect_info__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace shared_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const DefectInfo & msg,
  std::ostream & out)
{
  out << "{";
  // member: defect_found
  {
    out << "defect_found: ";
    rosidl_generator_traits::value_to_yaml(msg.defect_found, out);
    out << ", ";
  }

  // member: angle
  {
    out << "angle: ";
    rosidl_generator_traits::value_to_yaml(msg.angle, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const DefectInfo & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: defect_found
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "defect_found: ";
    rosidl_generator_traits::value_to_yaml(msg.defect_found, out);
    out << "\n";
  }

  // member: angle
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "angle: ";
    rosidl_generator_traits::value_to_yaml(msg.angle, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const DefectInfo & msg, bool use_flow_style = false)
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
  const shared_interfaces::msg::DefectInfo & msg,
  std::ostream & out, size_t indentation = 0)
{
  shared_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use shared_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const shared_interfaces::msg::DefectInfo & msg)
{
  return shared_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<shared_interfaces::msg::DefectInfo>()
{
  return "shared_interfaces::msg::DefectInfo";
}

template<>
inline const char * name<shared_interfaces::msg::DefectInfo>()
{
  return "shared_interfaces/msg/DefectInfo";
}

template<>
struct has_fixed_size<shared_interfaces::msg::DefectInfo>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<shared_interfaces::msg::DefectInfo>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<shared_interfaces::msg::DefectInfo>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // SHARED_INTERFACES__MSG__DETAIL__DEFECT_INFO__TRAITS_HPP_
