// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from shared_interfaces:msg/AddLog.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "shared_interfaces/msg/add_log.h"


#ifndef SHARED_INTERFACES__MSG__DETAIL__ADD_LOG__STRUCT_H_
#define SHARED_INTERFACES__MSG__DETAIL__ADD_LOG__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Constants defined in the message

// Include directives for member types
// Member 'task_type'
#include "rosidl_runtime_c/string.h"
// Member 'pose'
#include "geometry_msgs/msg/detail/pose_stamped__struct.h"

/// Struct defined in msg/AddLog in the package shared_interfaces.
/**
  * Custom Message to add log
  * To logger node
 */
typedef struct shared_interfaces__msg__AddLog
{
  /// defect or delivery
  rosidl_runtime_c__String task_type;
  geometry_msgs__msg__PoseStamped pose;
  /// visited/delivered
  bool complete;
} shared_interfaces__msg__AddLog;

// Struct for a sequence of shared_interfaces__msg__AddLog.
typedef struct shared_interfaces__msg__AddLog__Sequence
{
  shared_interfaces__msg__AddLog * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} shared_interfaces__msg__AddLog__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // SHARED_INTERFACES__MSG__DETAIL__ADD_LOG__STRUCT_H_
