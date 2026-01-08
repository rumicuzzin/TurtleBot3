// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from shared_interfaces:srv/Charging.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "shared_interfaces/srv/charging.hpp"


#ifndef SHARED_INTERFACES__SRV__DETAIL__CHARGING__BUILDER_HPP_
#define SHARED_INTERFACES__SRV__DETAIL__CHARGING__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "shared_interfaces/srv/detail/charging__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace shared_interfaces
{

namespace srv
{

namespace builder
{

class Init_Charging_Request_command
{
public:
  Init_Charging_Request_command()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::shared_interfaces::srv::Charging_Request command(::shared_interfaces::srv::Charging_Request::_command_type arg)
  {
    msg_.command = std::move(arg);
    return std::move(msg_);
  }

private:
  ::shared_interfaces::srv::Charging_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::shared_interfaces::srv::Charging_Request>()
{
  return shared_interfaces::srv::builder::Init_Charging_Request_command();
}

}  // namespace shared_interfaces


namespace shared_interfaces
{

namespace srv
{

namespace builder
{

class Init_Charging_Response_success
{
public:
  Init_Charging_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::shared_interfaces::srv::Charging_Response success(::shared_interfaces::srv::Charging_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return std::move(msg_);
  }

private:
  ::shared_interfaces::srv::Charging_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::shared_interfaces::srv::Charging_Response>()
{
  return shared_interfaces::srv::builder::Init_Charging_Response_success();
}

}  // namespace shared_interfaces


namespace shared_interfaces
{

namespace srv
{

namespace builder
{

class Init_Charging_Event_response
{
public:
  explicit Init_Charging_Event_response(::shared_interfaces::srv::Charging_Event & msg)
  : msg_(msg)
  {}
  ::shared_interfaces::srv::Charging_Event response(::shared_interfaces::srv::Charging_Event::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::shared_interfaces::srv::Charging_Event msg_;
};

class Init_Charging_Event_request
{
public:
  explicit Init_Charging_Event_request(::shared_interfaces::srv::Charging_Event & msg)
  : msg_(msg)
  {}
  Init_Charging_Event_response request(::shared_interfaces::srv::Charging_Event::_request_type arg)
  {
    msg_.request = std::move(arg);
    return Init_Charging_Event_response(msg_);
  }

private:
  ::shared_interfaces::srv::Charging_Event msg_;
};

class Init_Charging_Event_info
{
public:
  Init_Charging_Event_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Charging_Event_request info(::shared_interfaces::srv::Charging_Event::_info_type arg)
  {
    msg_.info = std::move(arg);
    return Init_Charging_Event_request(msg_);
  }

private:
  ::shared_interfaces::srv::Charging_Event msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::shared_interfaces::srv::Charging_Event>()
{
  return shared_interfaces::srv::builder::Init_Charging_Event_info();
}

}  // namespace shared_interfaces

#endif  // SHARED_INTERFACES__SRV__DETAIL__CHARGING__BUILDER_HPP_
