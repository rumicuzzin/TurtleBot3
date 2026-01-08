// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from shared_interfaces:msg/AddLog.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "shared_interfaces/msg/detail/add_log__functions.h"
#include "shared_interfaces/msg/detail/add_log__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace shared_interfaces
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void AddLog_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) shared_interfaces::msg::AddLog(_init);
}

void AddLog_fini_function(void * message_memory)
{
  auto typed_message = static_cast<shared_interfaces::msg::AddLog *>(message_memory);
  typed_message->~AddLog();
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember AddLog_message_member_array[3] = {
  {
    "task_type",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(shared_interfaces::msg::AddLog, task_type),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "pose",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<geometry_msgs::msg::PoseStamped>(),  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(shared_interfaces::msg::AddLog, pose),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "complete",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(shared_interfaces::msg::AddLog, complete),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers AddLog_message_members = {
  "shared_interfaces::msg",  // message namespace
  "AddLog",  // message name
  3,  // number of fields
  sizeof(shared_interfaces::msg::AddLog),
  false,  // has_any_key_member_
  AddLog_message_member_array,  // message members
  AddLog_init_function,  // function to initialize message memory (memory has to be allocated)
  AddLog_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t AddLog_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &AddLog_message_members,
  get_message_typesupport_handle_function,
  &shared_interfaces__msg__AddLog__get_type_hash,
  &shared_interfaces__msg__AddLog__get_type_description,
  &shared_interfaces__msg__AddLog__get_type_description_sources,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace shared_interfaces


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<shared_interfaces::msg::AddLog>()
{
  return &::shared_interfaces::msg::rosidl_typesupport_introspection_cpp::AddLog_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, shared_interfaces, msg, AddLog)() {
  return &::shared_interfaces::msg::rosidl_typesupport_introspection_cpp::AddLog_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
