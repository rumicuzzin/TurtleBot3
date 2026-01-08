// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from shared_interfaces:msg/CheckLog.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "shared_interfaces/msg/check_log.hpp"


#ifndef SHARED_INTERFACES__MSG__DETAIL__CHECK_LOG__BUILDER_HPP_
#define SHARED_INTERFACES__MSG__DETAIL__CHECK_LOG__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "shared_interfaces/msg/detail/check_log__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace shared_interfaces
{

namespace msg
{

namespace builder
{

class Init_CheckLog_complete
{
public:
  explicit Init_CheckLog_complete(::shared_interfaces::msg::CheckLog & msg)
  : msg_(msg)
  {}
  ::shared_interfaces::msg::CheckLog complete(::shared_interfaces::msg::CheckLog::_complete_type arg)
  {
    msg_.complete = std::move(arg);
    return std::move(msg_);
  }

private:
  ::shared_interfaces::msg::CheckLog msg_;
};

class Init_CheckLog_pose
{
public:
  explicit Init_CheckLog_pose(::shared_interfaces::msg::CheckLog & msg)
  : msg_(msg)
  {}
  Init_CheckLog_complete pose(::shared_interfaces::msg::CheckLog::_pose_type arg)
  {
    msg_.pose = std::move(arg);
    return Init_CheckLog_complete(msg_);
  }

private:
  ::shared_interfaces::msg::CheckLog msg_;
};

class Init_CheckLog_index
{
public:
  explicit Init_CheckLog_index(::shared_interfaces::msg::CheckLog & msg)
  : msg_(msg)
  {}
  Init_CheckLog_pose index(::shared_interfaces::msg::CheckLog::_index_type arg)
  {
    msg_.index = std::move(arg);
    return Init_CheckLog_pose(msg_);
  }

private:
  ::shared_interfaces::msg::CheckLog msg_;
};

class Init_CheckLog_task_type
{
public:
  Init_CheckLog_task_type()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_CheckLog_index task_type(::shared_interfaces::msg::CheckLog::_task_type_type arg)
  {
    msg_.task_type = std::move(arg);
    return Init_CheckLog_index(msg_);
  }

private:
  ::shared_interfaces::msg::CheckLog msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::shared_interfaces::msg::CheckLog>()
{
  return shared_interfaces::msg::builder::Init_CheckLog_task_type();
}

}  // namespace shared_interfaces

#endif  // SHARED_INTERFACES__MSG__DETAIL__CHECK_LOG__BUILDER_HPP_
