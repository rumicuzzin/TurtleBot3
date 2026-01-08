// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from shared_interfaces:srv/NavigationMode.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "shared_interfaces/srv/navigation_mode.h"


#ifndef SHARED_INTERFACES__SRV__DETAIL__NAVIGATION_MODE__STRUCT_H_
#define SHARED_INTERFACES__SRV__DETAIL__NAVIGATION_MODE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'nav_mode'
#include "rosidl_runtime_c/string.h"
// Member 'target_pose'
#include "geometry_msgs/msg/detail/pose_stamped__struct.h"

/// Struct defined in srv/NavigationMode in the package shared_interfaces.
typedef struct shared_interfaces__srv__NavigationMode_Request
{
  rosidl_runtime_c__String nav_mode;
  geometry_msgs__msg__PoseStamped target_pose;
} shared_interfaces__srv__NavigationMode_Request;

// Struct for a sequence of shared_interfaces__srv__NavigationMode_Request.
typedef struct shared_interfaces__srv__NavigationMode_Request__Sequence
{
  shared_interfaces__srv__NavigationMode_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} shared_interfaces__srv__NavigationMode_Request__Sequence;

// Constants defined in the message

/// Struct defined in srv/NavigationMode in the package shared_interfaces.
typedef struct shared_interfaces__srv__NavigationMode_Response
{
  bool success;
} shared_interfaces__srv__NavigationMode_Response;

// Struct for a sequence of shared_interfaces__srv__NavigationMode_Response.
typedef struct shared_interfaces__srv__NavigationMode_Response__Sequence
{
  shared_interfaces__srv__NavigationMode_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} shared_interfaces__srv__NavigationMode_Response__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__struct.h"

// constants for array fields with an upper bound
// request
enum
{
  shared_interfaces__srv__NavigationMode_Event__request__MAX_SIZE = 1
};
// response
enum
{
  shared_interfaces__srv__NavigationMode_Event__response__MAX_SIZE = 1
};

/// Struct defined in srv/NavigationMode in the package shared_interfaces.
typedef struct shared_interfaces__srv__NavigationMode_Event
{
  service_msgs__msg__ServiceEventInfo info;
  shared_interfaces__srv__NavigationMode_Request__Sequence request;
  shared_interfaces__srv__NavigationMode_Response__Sequence response;
} shared_interfaces__srv__NavigationMode_Event;

// Struct for a sequence of shared_interfaces__srv__NavigationMode_Event.
typedef struct shared_interfaces__srv__NavigationMode_Event__Sequence
{
  shared_interfaces__srv__NavigationMode_Event * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} shared_interfaces__srv__NavigationMode_Event__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // SHARED_INTERFACES__SRV__DETAIL__NAVIGATION_MODE__STRUCT_H_
