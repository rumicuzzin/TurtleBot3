// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from shared_interfaces:msg/CheckLog.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "shared_interfaces/msg/check_log.h"


#ifndef SHARED_INTERFACES__MSG__DETAIL__CHECK_LOG__STRUCT_H_
#define SHARED_INTERFACES__MSG__DETAIL__CHECK_LOG__STRUCT_H_

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

/// Struct defined in msg/CheckLog in the package shared_interfaces.
/**
  * Custom Message for logger to publish
  * From logger node
 */
typedef struct shared_interfaces__msg__CheckLog
{
  /// defect or delivery
  rosidl_runtime_c__String task_type;
  /// logger to index based on when they receive them
  int8_t index;
  geometry_msgs__msg__PoseStamped pose;
  /// visited/delivered
  bool complete;
} shared_interfaces__msg__CheckLog;

// Struct for a sequence of shared_interfaces__msg__CheckLog.
typedef struct shared_interfaces__msg__CheckLog__Sequence
{
  shared_interfaces__msg__CheckLog * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} shared_interfaces__msg__CheckLog__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // SHARED_INTERFACES__MSG__DETAIL__CHECK_LOG__STRUCT_H_
