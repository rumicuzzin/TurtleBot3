// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from shared_interfaces:msg/DefectInfo.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "shared_interfaces/msg/defect_info.hpp"


#ifndef SHARED_INTERFACES__MSG__DETAIL__DEFECT_INFO__STRUCT_HPP_
#define SHARED_INTERFACES__MSG__DETAIL__DEFECT_INFO__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__shared_interfaces__msg__DefectInfo __attribute__((deprecated))
#else
# define DEPRECATED__shared_interfaces__msg__DefectInfo __declspec(deprecated)
#endif

namespace shared_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct DefectInfo_
{
  using Type = DefectInfo_<ContainerAllocator>;

  explicit DefectInfo_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->defect_found = false;
      this->angle = 0.0f;
    }
  }

  explicit DefectInfo_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->defect_found = false;
      this->angle = 0.0f;
    }
  }

  // field types and members
  using _defect_found_type =
    bool;
  _defect_found_type defect_found;
  using _angle_type =
    float;
  _angle_type angle;

  // setters for named parameter idiom
  Type & set__defect_found(
    const bool & _arg)
  {
    this->defect_found = _arg;
    return *this;
  }
  Type & set__angle(
    const float & _arg)
  {
    this->angle = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    shared_interfaces::msg::DefectInfo_<ContainerAllocator> *;
  using ConstRawPtr =
    const shared_interfaces::msg::DefectInfo_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<shared_interfaces::msg::DefectInfo_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<shared_interfaces::msg::DefectInfo_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      shared_interfaces::msg::DefectInfo_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<shared_interfaces::msg::DefectInfo_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      shared_interfaces::msg::DefectInfo_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<shared_interfaces::msg::DefectInfo_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<shared_interfaces::msg::DefectInfo_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<shared_interfaces::msg::DefectInfo_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__shared_interfaces__msg__DefectInfo
    std::shared_ptr<shared_interfaces::msg::DefectInfo_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__shared_interfaces__msg__DefectInfo
    std::shared_ptr<shared_interfaces::msg::DefectInfo_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const DefectInfo_ & other) const
  {
    if (this->defect_found != other.defect_found) {
      return false;
    }
    if (this->angle != other.angle) {
      return false;
    }
    return true;
  }
  bool operator!=(const DefectInfo_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct DefectInfo_

// alias to use template instance with default allocator
using DefectInfo =
  shared_interfaces::msg::DefectInfo_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace shared_interfaces

#endif  // SHARED_INTERFACES__MSG__DETAIL__DEFECT_INFO__STRUCT_HPP_
