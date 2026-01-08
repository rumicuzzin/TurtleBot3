// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from shared_interfaces:srv/Charging.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "shared_interfaces/srv/charging.h"


#ifndef SHARED_INTERFACES__SRV__DETAIL__CHARGING__STRUCT_H_
#define SHARED_INTERFACES__SRV__DETAIL__CHARGING__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'command'
#include "rosidl_runtime_c/string.h"

/// Struct defined in srv/Charging in the package shared_interfaces.
typedef struct shared_interfaces__srv__Charging_Request
{
  /// "start_charging" or "stop_charging" or "start_depleting" or "stop_depleting"
  rosidl_runtime_c__String command;
} shared_interfaces__srv__Charging_Request;

// Struct for a sequence of shared_interfaces__srv__Charging_Request.
typedef struct shared_interfaces__srv__Charging_Request__Sequence
{
  shared_interfaces__srv__Charging_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} shared_interfaces__srv__Charging_Request__Sequence;

// Constants defined in the message

/// Struct defined in srv/Charging in the package shared_interfaces.
typedef struct shared_interfaces__srv__Charging_Response
{
  bool success;
} shared_interfaces__srv__Charging_Response;

// Struct for a sequence of shared_interfaces__srv__Charging_Response.
typedef struct shared_interfaces__srv__Charging_Response__Sequence
{
  shared_interfaces__srv__Charging_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} shared_interfaces__srv__Charging_Response__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__struct.h"

// constants for array fields with an upper bound
// request
enum
{
  shared_interfaces__srv__Charging_Event__request__MAX_SIZE = 1
};
// response
enum
{
  shared_interfaces__srv__Charging_Event__response__MAX_SIZE = 1
};

/// Struct defined in srv/Charging in the package shared_interfaces.
typedef struct shared_interfaces__srv__Charging_Event
{
  service_msgs__msg__ServiceEventInfo info;
  shared_interfaces__srv__Charging_Request__Sequence request;
  shared_interfaces__srv__Charging_Response__Sequence response;
} shared_interfaces__srv__Charging_Event;

// Struct for a sequence of shared_interfaces__srv__Charging_Event.
typedef struct shared_interfaces__srv__Charging_Event__Sequence
{
  shared_interfaces__srv__Charging_Event * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} shared_interfaces__srv__Charging_Event__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // SHARED_INTERFACES__SRV__DETAIL__CHARGING__STRUCT_H_
