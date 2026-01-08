// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from shared_interfaces:msg/AddLog.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "shared_interfaces/msg/add_log.hpp"


#ifndef SHARED_INTERFACES__MSG__DETAIL__ADD_LOG__BUILDER_HPP_
#define SHARED_INTERFACES__MSG__DETAIL__ADD_LOG__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "shared_interfaces/msg/detail/add_log__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace shared_interfaces
{

namespace msg
{

namespace builder
{

class Init_AddLog_complete
{
public:
  explicit Init_AddLog_complete(::shared_interfaces::msg::AddLog & msg)
  : msg_(msg)
  {}
  ::shared_interfaces::msg::AddLog complete(::shared_interfaces::msg::AddLog::_complete_type arg)
  {
    msg_.complete = std::move(arg);
    return std::move(msg_);
  }

private:
  ::shared_interfaces::msg::AddLog msg_;
};

class Init_AddLog_pose
{
public:
  explicit Init_AddLog_pose(::shared_interfaces::msg::AddLog & msg)
  : msg_(msg)
  {}
  Init_AddLog_complete pose(::shared_interfaces::msg::AddLog::_pose_type arg)
  {
    msg_.pose = std::move(arg);
    return Init_AddLog_complete(msg_);
  }

private:
  ::shared_interfaces::msg::AddLog msg_;
};

class Init_AddLog_task_type
{
public:
  Init_AddLog_task_type()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_AddLog_pose task_type(::shared_interfaces::msg::AddLog::_task_type_type arg)
  {
    msg_.task_type = std::move(arg);
    return Init_AddLog_pose(msg_);
  }

private:
  ::shared_interfaces::msg::AddLog msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::shared_interfaces::msg::AddLog>()
{
  return shared_interfaces::msg::builder::Init_AddLog_task_type();
}

}  // namespace shared_interfaces

#endif  // SHARED_INTERFACES__MSG__DETAIL__ADD_LOG__BUILDER_HPP_
