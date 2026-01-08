// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from shared_interfaces:srv/RobotType.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "shared_interfaces/srv/robot_type.h"


#ifndef SHARED_INTERFACES__SRV__DETAIL__ROBOT_TYPE__STRUCT_H_
#define SHARED_INTERFACES__SRV__DETAIL__ROBOT_TYPE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'robot_type'
#include "rosidl_runtime_c/string.h"
// Member 'pose'
#include "geometry_msgs/msg/detail/pose_stamped__struct.h"

/// Struct defined in srv/RobotType in the package shared_interfaces.
typedef struct shared_interfaces__srv__RobotType_Request
{
  rosidl_runtime_c__String robot_type;
  /// index for a delivery or defect
  int8_t index;
  /// desired pose
  geometry_msgs__msg__PoseStamped pose;
} shared_interfaces__srv__RobotType_Request;

// Struct for a sequence of shared_interfaces__srv__RobotType_Request.
typedef struct shared_interfaces__srv__RobotType_Request__Sequence
{
  shared_interfaces__srv__RobotType_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} shared_interfaces__srv__RobotType_Request__Sequence;

// Constants defined in the message

/// Struct defined in srv/RobotType in the package shared_interfaces.
typedef struct shared_interfaces__srv__RobotType_Response
{
  bool success;
} shared_interfaces__srv__RobotType_Response;

// Struct for a sequence of shared_interfaces__srv__RobotType_Response.
typedef struct shared_interfaces__srv__RobotType_Response__Sequence
{
  shared_interfaces__srv__RobotType_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} shared_interfaces__srv__RobotType_Response__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__struct.h"

// constants for array fields with an upper bound
// request
enum
{
  shared_interfaces__srv__RobotType_Event__request__MAX_SIZE = 1
};
// response
enum
{
  shared_interfaces__srv__RobotType_Event__response__MAX_SIZE = 1
};

/// Struct defined in srv/RobotType in the package shared_interfaces.
typedef struct shared_interfaces__srv__RobotType_Event
{
  service_msgs__msg__ServiceEventInfo info;
  shared_interfaces__srv__RobotType_Request__Sequence request;
  shared_interfaces__srv__RobotType_Response__Sequence response;
} shared_interfaces__srv__RobotType_Event;

// Struct for a sequence of shared_interfaces__srv__RobotType_Event.
typedef struct shared_interfaces__srv__RobotType_Event__Sequence
{
  shared_interfaces__srv__RobotType_Event * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} shared_interfaces__srv__RobotType_Event__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // SHARED_INTERFACES__SRV__DETAIL__ROBOT_TYPE__STRUCT_H_
