// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from shared_interfaces:msg/DefectInfo.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "shared_interfaces/msg/defect_info.hpp"


#ifndef SHARED_INTERFACES__MSG__DETAIL__DEFECT_INFO__BUILDER_HPP_
#define SHARED_INTERFACES__MSG__DETAIL__DEFECT_INFO__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "shared_interfaces/msg/detail/defect_info__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace shared_interfaces
{

namespace msg
{

namespace builder
{

class Init_DefectInfo_angle
{
public:
  explicit Init_DefectInfo_angle(::shared_interfaces::msg::DefectInfo & msg)
  : msg_(msg)
  {}
  ::shared_interfaces::msg::DefectInfo angle(::shared_interfaces::msg::DefectInfo::_angle_type arg)
  {
    msg_.angle = std::move(arg);
    return std::move(msg_);
  }

private:
  ::shared_interfaces::msg::DefectInfo msg_;
};

class Init_DefectInfo_defect_found
{
public:
  Init_DefectInfo_defect_found()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_DefectInfo_angle defect_found(::shared_interfaces::msg::DefectInfo::_defect_found_type arg)
  {
    msg_.defect_found = std::move(arg);
    return Init_DefectInfo_angle(msg_);
  }

private:
  ::shared_interfaces::msg::DefectInfo msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::shared_interfaces::msg::DefectInfo>()
{
  return shared_interfaces::msg::builder::Init_DefectInfo_defect_found();
}

}  // namespace shared_interfaces

#endif  // SHARED_INTERFACES__MSG__DETAIL__DEFECT_INFO__BUILDER_HPP_
