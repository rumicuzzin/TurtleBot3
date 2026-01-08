// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from shared_interfaces:srv/NavigationMode.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "shared_interfaces/srv/navigation_mode.hpp"


#ifndef SHARED_INTERFACES__SRV__DETAIL__NAVIGATION_MODE__BUILDER_HPP_
#define SHARED_INTERFACES__SRV__DETAIL__NAVIGATION_MODE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "shared_interfaces/srv/detail/navigation_mode__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace shared_interfaces
{

namespace srv
{

namespace builder
{

class Init_NavigationMode_Request_target_pose
{
public:
  explicit Init_NavigationMode_Request_target_pose(::shared_interfaces::srv::NavigationMode_Request & msg)
  : msg_(msg)
  {}
  ::shared_interfaces::srv::NavigationMode_Request target_pose(::shared_interfaces::srv::NavigationMode_Request::_target_pose_type arg)
  {
    msg_.target_pose = std::move(arg);
    return std::move(msg_);
  }

private:
  ::shared_interfaces::srv::NavigationMode_Request msg_;
};

class Init_NavigationMode_Request_nav_mode
{
public:
  Init_NavigationMode_Request_nav_mode()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_NavigationMode_Request_target_pose nav_mode(::shared_interfaces::srv::NavigationMode_Request::_nav_mode_type arg)
  {
    msg_.nav_mode = std::move(arg);
    return Init_NavigationMode_Request_target_pose(msg_);
  }

private:
  ::shared_interfaces::srv::NavigationMode_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::shared_interfaces::srv::NavigationMode_Request>()
{
  return shared_interfaces::srv::builder::Init_NavigationMode_Request_nav_mode();
}

}  // namespace shared_interfaces


namespace shared_interfaces
{

namespace srv
{

namespace builder
{

class Init_NavigationMode_Response_success
{
public:
  Init_NavigationMode_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::shared_interfaces::srv::NavigationMode_Response success(::shared_interfaces::srv::NavigationMode_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return std::move(msg_);
  }

private:
  ::shared_interfaces::srv::NavigationMode_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::shared_interfaces::srv::NavigationMode_Response>()
{
  return shared_interfaces::srv::builder::Init_NavigationMode_Response_success();
}

}  // namespace shared_interfaces


namespace shared_interfaces
{

namespace srv
{

namespace builder
{

class Init_NavigationMode_Event_response
{
public:
  explicit Init_NavigationMode_Event_response(::shared_interfaces::srv::NavigationMode_Event & msg)
  : msg_(msg)
  {}
  ::shared_interfaces::srv::NavigationMode_Event response(::shared_interfaces::srv::NavigationMode_Event::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::shared_interfaces::srv::NavigationMode_Event msg_;
};

class Init_NavigationMode_Event_request
{
public:
  explicit Init_NavigationMode_Event_request(::shared_interfaces::srv::NavigationMode_Event & msg)
  : msg_(msg)
  {}
  Init_NavigationMode_Event_response request(::shared_interfaces::srv::NavigationMode_Event::_request_type arg)
  {
    msg_.request = std::move(arg);
    return Init_NavigationMode_Event_response(msg_);
  }

private:
  ::shared_interfaces::srv::NavigationMode_Event msg_;
};

class Init_NavigationMode_Event_info
{
public:
  Init_NavigationMode_Event_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_NavigationMode_Event_request info(::shared_interfaces::srv::NavigationMode_Event::_info_type arg)
  {
    msg_.info = std::move(arg);
    return Init_NavigationMode_Event_request(msg_);
  }

private:
  ::shared_interfaces::srv::NavigationMode_Event msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::shared_interfaces::srv::NavigationMode_Event>()
{
  return shared_interfaces::srv::builder::Init_NavigationMode_Event_info();
}

}  // namespace shared_interfaces

#endif  // SHARED_INTERFACES__SRV__DETAIL__NAVIGATION_MODE__BUILDER_HPP_
