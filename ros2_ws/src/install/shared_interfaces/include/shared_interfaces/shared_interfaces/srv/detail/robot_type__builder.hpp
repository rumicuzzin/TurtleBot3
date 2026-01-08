// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from shared_interfaces:srv/RobotType.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "shared_interfaces/srv/robot_type.hpp"


#ifndef SHARED_INTERFACES__SRV__DETAIL__ROBOT_TYPE__BUILDER_HPP_
#define SHARED_INTERFACES__SRV__DETAIL__ROBOT_TYPE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "shared_interfaces/srv/detail/robot_type__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace shared_interfaces
{

namespace srv
{

namespace builder
{

class Init_RobotType_Request_pose
{
public:
  explicit Init_RobotType_Request_pose(::shared_interfaces::srv::RobotType_Request & msg)
  : msg_(msg)
  {}
  ::shared_interfaces::srv::RobotType_Request pose(::shared_interfaces::srv::RobotType_Request::_pose_type arg)
  {
    msg_.pose = std::move(arg);
    return std::move(msg_);
  }

private:
  ::shared_interfaces::srv::RobotType_Request msg_;
};

class Init_RobotType_Request_index
{
public:
  explicit Init_RobotType_Request_index(::shared_interfaces::srv::RobotType_Request & msg)
  : msg_(msg)
  {}
  Init_RobotType_Request_pose index(::shared_interfaces::srv::RobotType_Request::_index_type arg)
  {
    msg_.index = std::move(arg);
    return Init_RobotType_Request_pose(msg_);
  }

private:
  ::shared_interfaces::srv::RobotType_Request msg_;
};

class Init_RobotType_Request_robot_type
{
public:
  Init_RobotType_Request_robot_type()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_RobotType_Request_index robot_type(::shared_interfaces::srv::RobotType_Request::_robot_type_type arg)
  {
    msg_.robot_type = std::move(arg);
    return Init_RobotType_Request_index(msg_);
  }

private:
  ::shared_interfaces::srv::RobotType_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::shared_interfaces::srv::RobotType_Request>()
{
  return shared_interfaces::srv::builder::Init_RobotType_Request_robot_type();
}

}  // namespace shared_interfaces


namespace shared_interfaces
{

namespace srv
{

namespace builder
{

class Init_RobotType_Response_success
{
public:
  Init_RobotType_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::shared_interfaces::srv::RobotType_Response success(::shared_interfaces::srv::RobotType_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return std::move(msg_);
  }

private:
  ::shared_interfaces::srv::RobotType_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::shared_interfaces::srv::RobotType_Response>()
{
  return shared_interfaces::srv::builder::Init_RobotType_Response_success();
}

}  // namespace shared_interfaces


namespace shared_interfaces
{

namespace srv
{

namespace builder
{

class Init_RobotType_Event_response
{
public:
  explicit Init_RobotType_Event_response(::shared_interfaces::srv::RobotType_Event & msg)
  : msg_(msg)
  {}
  ::shared_interfaces::srv::RobotType_Event response(::shared_interfaces::srv::RobotType_Event::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::shared_interfaces::srv::RobotType_Event msg_;
};

class Init_RobotType_Event_request
{
public:
  explicit Init_RobotType_Event_request(::shared_interfaces::srv::RobotType_Event & msg)
  : msg_(msg)
  {}
  Init_RobotType_Event_response request(::shared_interfaces::srv::RobotType_Event::_request_type arg)
  {
    msg_.request = std::move(arg);
    return Init_RobotType_Event_response(msg_);
  }

private:
  ::shared_interfaces::srv::RobotType_Event msg_;
};

class Init_RobotType_Event_info
{
public:
  Init_RobotType_Event_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_RobotType_Event_request info(::shared_interfaces::srv::RobotType_Event::_info_type arg)
  {
    msg_.info = std::move(arg);
    return Init_RobotType_Event_request(msg_);
  }

private:
  ::shared_interfaces::srv::RobotType_Event msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::shared_interfaces::srv::RobotType_Event>()
{
  return shared_interfaces::srv::builder::Init_RobotType_Event_info();
}

}  // namespace shared_interfaces

#endif  // SHARED_INTERFACES__SRV__DETAIL__ROBOT_TYPE__BUILDER_HPP_
