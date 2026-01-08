// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from shared_interfaces:srv/RobotType.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "shared_interfaces/srv/robot_type.hpp"


#ifndef SHARED_INTERFACES__SRV__DETAIL__ROBOT_TYPE__TRAITS_HPP_
#define SHARED_INTERFACES__SRV__DETAIL__ROBOT_TYPE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "shared_interfaces/srv/detail/robot_type__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'pose'
#include "geometry_msgs/msg/detail/pose_stamped__traits.hpp"

namespace shared_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const RobotType_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: robot_type
  {
    out << "robot_type: ";
    rosidl_generator_traits::value_to_yaml(msg.robot_type, out);
    out << ", ";
  }

  // member: index
  {
    out << "index: ";
    rosidl_generator_traits::value_to_yaml(msg.index, out);
    out << ", ";
  }

  // member: pose
  {
    out << "pose: ";
    to_flow_style_yaml(msg.pose, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const RobotType_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: robot_type
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "robot_type: ";
    rosidl_generator_traits::value_to_yaml(msg.robot_type, out);
    out << "\n";
  }

  // member: index
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "index: ";
    rosidl_generator_traits::value_to_yaml(msg.index, out);
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
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const RobotType_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace shared_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use shared_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const shared_interfaces::srv::RobotType_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  shared_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use shared_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const shared_interfaces::srv::RobotType_Request & msg)
{
  return shared_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<shared_interfaces::srv::RobotType_Request>()
{
  return "shared_interfaces::srv::RobotType_Request";
}

template<>
inline const char * name<shared_interfaces::srv::RobotType_Request>()
{
  return "shared_interfaces/srv/RobotType_Request";
}

template<>
struct has_fixed_size<shared_interfaces::srv::RobotType_Request>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<shared_interfaces::srv::RobotType_Request>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<shared_interfaces::srv::RobotType_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace shared_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const RobotType_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: success
  {
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const RobotType_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: success
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const RobotType_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace shared_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use shared_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const shared_interfaces::srv::RobotType_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  shared_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use shared_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const shared_interfaces::srv::RobotType_Response & msg)
{
  return shared_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<shared_interfaces::srv::RobotType_Response>()
{
  return "shared_interfaces::srv::RobotType_Response";
}

template<>
inline const char * name<shared_interfaces::srv::RobotType_Response>()
{
  return "shared_interfaces/srv/RobotType_Response";
}

template<>
struct has_fixed_size<shared_interfaces::srv::RobotType_Response>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<shared_interfaces::srv::RobotType_Response>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<shared_interfaces::srv::RobotType_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__traits.hpp"

namespace shared_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const RobotType_Event & msg,
  std::ostream & out)
{
  out << "{";
  // member: info
  {
    out << "info: ";
    to_flow_style_yaml(msg.info, out);
    out << ", ";
  }

  // member: request
  {
    if (msg.request.size() == 0) {
      out << "request: []";
    } else {
      out << "request: [";
      size_t pending_items = msg.request.size();
      for (auto item : msg.request) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: response
  {
    if (msg.response.size() == 0) {
      out << "response: []";
    } else {
      out << "response: [";
      size_t pending_items = msg.response.size();
      for (auto item : msg.response) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const RobotType_Event & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: info
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "info:\n";
    to_block_style_yaml(msg.info, out, indentation + 2);
  }

  // member: request
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.request.size() == 0) {
      out << "request: []\n";
    } else {
      out << "request:\n";
      for (auto item : msg.request) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }

  // member: response
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.response.size() == 0) {
      out << "response: []\n";
    } else {
      out << "response:\n";
      for (auto item : msg.response) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const RobotType_Event & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace shared_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use shared_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const shared_interfaces::srv::RobotType_Event & msg,
  std::ostream & out, size_t indentation = 0)
{
  shared_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use shared_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const shared_interfaces::srv::RobotType_Event & msg)
{
  return shared_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<shared_interfaces::srv::RobotType_Event>()
{
  return "shared_interfaces::srv::RobotType_Event";
}

template<>
inline const char * name<shared_interfaces::srv::RobotType_Event>()
{
  return "shared_interfaces/srv/RobotType_Event";
}

template<>
struct has_fixed_size<shared_interfaces::srv::RobotType_Event>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<shared_interfaces::srv::RobotType_Event>
  : std::integral_constant<bool, has_bounded_size<service_msgs::msg::ServiceEventInfo>::value && has_bounded_size<shared_interfaces::srv::RobotType_Request>::value && has_bounded_size<shared_interfaces::srv::RobotType_Response>::value> {};

template<>
struct is_message<shared_interfaces::srv::RobotType_Event>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<shared_interfaces::srv::RobotType>()
{
  return "shared_interfaces::srv::RobotType";
}

template<>
inline const char * name<shared_interfaces::srv::RobotType>()
{
  return "shared_interfaces/srv/RobotType";
}

template<>
struct has_fixed_size<shared_interfaces::srv::RobotType>
  : std::integral_constant<
    bool,
    has_fixed_size<shared_interfaces::srv::RobotType_Request>::value &&
    has_fixed_size<shared_interfaces::srv::RobotType_Response>::value
  >
{
};

template<>
struct has_bounded_size<shared_interfaces::srv::RobotType>
  : std::integral_constant<
    bool,
    has_bounded_size<shared_interfaces::srv::RobotType_Request>::value &&
    has_bounded_size<shared_interfaces::srv::RobotType_Response>::value
  >
{
};

template<>
struct is_service<shared_interfaces::srv::RobotType>
  : std::true_type
{
};

template<>
struct is_service_request<shared_interfaces::srv::RobotType_Request>
  : std::true_type
{
};

template<>
struct is_service_response<shared_interfaces::srv::RobotType_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // SHARED_INTERFACES__SRV__DETAIL__ROBOT_TYPE__TRAITS_HPP_
