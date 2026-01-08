// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from shared_interfaces:msg/AddLog.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "shared_interfaces/msg/detail/add_log__rosidl_typesupport_introspection_c.h"
#include "shared_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "shared_interfaces/msg/detail/add_log__functions.h"
#include "shared_interfaces/msg/detail/add_log__struct.h"


// Include directives for member types
// Member `task_type`
#include "rosidl_runtime_c/string_functions.h"
// Member `pose`
#include "geometry_msgs/msg/pose_stamped.h"
// Member `pose`
#include "geometry_msgs/msg/detail/pose_stamped__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void shared_interfaces__msg__AddLog__rosidl_typesupport_introspection_c__AddLog_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  shared_interfaces__msg__AddLog__init(message_memory);
}

void shared_interfaces__msg__AddLog__rosidl_typesupport_introspection_c__AddLog_fini_function(void * message_memory)
{
  shared_interfaces__msg__AddLog__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember shared_interfaces__msg__AddLog__rosidl_typesupport_introspection_c__AddLog_message_member_array[3] = {
  {
    "task_type",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(shared_interfaces__msg__AddLog, task_type),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "pose",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(shared_interfaces__msg__AddLog, pose),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "complete",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(shared_interfaces__msg__AddLog, complete),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers shared_interfaces__msg__AddLog__rosidl_typesupport_introspection_c__AddLog_message_members = {
  "shared_interfaces__msg",  // message namespace
  "AddLog",  // message name
  3,  // number of fields
  sizeof(shared_interfaces__msg__AddLog),
  false,  // has_any_key_member_
  shared_interfaces__msg__AddLog__rosidl_typesupport_introspection_c__AddLog_message_member_array,  // message members
  shared_interfaces__msg__AddLog__rosidl_typesupport_introspection_c__AddLog_init_function,  // function to initialize message memory (memory has to be allocated)
  shared_interfaces__msg__AddLog__rosidl_typesupport_introspection_c__AddLog_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t shared_interfaces__msg__AddLog__rosidl_typesupport_introspection_c__AddLog_message_type_support_handle = {
  0,
  &shared_interfaces__msg__AddLog__rosidl_typesupport_introspection_c__AddLog_message_members,
  get_message_typesupport_handle_function,
  &shared_interfaces__msg__AddLog__get_type_hash,
  &shared_interfaces__msg__AddLog__get_type_description,
  &shared_interfaces__msg__AddLog__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_shared_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, shared_interfaces, msg, AddLog)() {
  shared_interfaces__msg__AddLog__rosidl_typesupport_introspection_c__AddLog_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, PoseStamped)();
  if (!shared_interfaces__msg__AddLog__rosidl_typesupport_introspection_c__AddLog_message_type_support_handle.typesupport_identifier) {
    shared_interfaces__msg__AddLog__rosidl_typesupport_introspection_c__AddLog_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &shared_interfaces__msg__AddLog__rosidl_typesupport_introspection_c__AddLog_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
