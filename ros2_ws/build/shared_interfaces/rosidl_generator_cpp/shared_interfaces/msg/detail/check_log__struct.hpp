// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from shared_interfaces:msg/CheckLog.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "shared_interfaces/msg/check_log.hpp"


#ifndef SHARED_INTERFACES__MSG__DETAIL__CHECK_LOG__STRUCT_HPP_
#define SHARED_INTERFACES__MSG__DETAIL__CHECK_LOG__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'pose'
#include "geometry_msgs/msg/detail/pose_stamped__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__shared_interfaces__msg__CheckLog __attribute__((deprecated))
#else
# define DEPRECATED__shared_interfaces__msg__CheckLog __declspec(deprecated)
#endif

namespace shared_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct CheckLog_
{
  using Type = CheckLog_<ContainerAllocator>;

  explicit CheckLog_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : pose(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->task_type = "";
      this->index = 0;
      this->complete = false;
    }
  }

  explicit CheckLog_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : task_type(_alloc),
    pose(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->task_type = "";
      this->index = 0;
      this->complete = false;
    }
  }

  // field types and members
  using _task_type_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _task_type_type task_type;
  using _index_type =
    int8_t;
  _index_type index;
  using _pose_type =
    geometry_msgs::msg::PoseStamped_<ContainerAllocator>;
  _pose_type pose;
  using _complete_type =
    bool;
  _complete_type complete;

  // setters for named parameter idiom
  Type & set__task_type(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->task_type = _arg;
    return *this;
  }
  Type & set__index(
    const int8_t & _arg)
  {
    this->index = _arg;
    return *this;
  }
  Type & set__pose(
    const geometry_msgs::msg::PoseStamped_<ContainerAllocator> & _arg)
  {
    this->pose = _arg;
    return *this;
  }
  Type & set__complete(
    const bool & _arg)
  {
    this->complete = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    shared_interfaces::msg::CheckLog_<ContainerAllocator> *;
  using ConstRawPtr =
    const shared_interfaces::msg::CheckLog_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<shared_interfaces::msg::CheckLog_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<shared_interfaces::msg::CheckLog_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      shared_interfaces::msg::CheckLog_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<shared_interfaces::msg::CheckLog_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      shared_interfaces::msg::CheckLog_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<shared_interfaces::msg::CheckLog_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<shared_interfaces::msg::CheckLog_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<shared_interfaces::msg::CheckLog_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__shared_interfaces__msg__CheckLog
    std::shared_ptr<shared_interfaces::msg::CheckLog_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__shared_interfaces__msg__CheckLog
    std::shared_ptr<shared_interfaces::msg::CheckLog_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const CheckLog_ & other) const
  {
    if (this->task_type != other.task_type) {
      return false;
    }
    if (this->index != other.index) {
      return false;
    }
    if (this->pose != other.pose) {
      return false;
    }
    if (this->complete != other.complete) {
      return false;
    }
    return true;
  }
  bool operator!=(const CheckLog_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct CheckLog_

// alias to use template instance with default allocator
using CheckLog =
  shared_interfaces::msg::CheckLog_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace shared_interfaces

#endif  // SHARED_INTERFACES__MSG__DETAIL__CHECK_LOG__STRUCT_HPP_
