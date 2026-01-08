// generated from rosidl_typesupport_c/resource/idl__type_support.cpp.em
// with input from shared_interfaces:srv/NavigationMode.idl
// generated code does not contain a copyright notice

#include "cstddef"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "shared_interfaces/srv/detail/navigation_mode__struct.h"
#include "shared_interfaces/srv/detail/navigation_mode__type_support.h"
#include "shared_interfaces/srv/detail/navigation_mode__functions.h"
#include "rosidl_typesupport_c/identifier.h"
#include "rosidl_typesupport_c/message_type_support_dispatch.h"
#include "rosidl_typesupport_c/type_support_map.h"
#include "rosidl_typesupport_c/visibility_control.h"
#include "rosidl_typesupport_interface/macros.h"

namespace shared_interfaces
{

namespace srv
{

namespace rosidl_typesupport_c
{

typedef struct _NavigationMode_Request_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _NavigationMode_Request_type_support_ids_t;

static const _NavigationMode_Request_type_support_ids_t _NavigationMode_Request_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _NavigationMode_Request_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _NavigationMode_Request_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _NavigationMode_Request_type_support_symbol_names_t _NavigationMode_Request_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, shared_interfaces, srv, NavigationMode_Request)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, shared_interfaces, srv, NavigationMode_Request)),
  }
};

typedef struct _NavigationMode_Request_type_support_data_t
{
  void * data[2];
} _NavigationMode_Request_type_support_data_t;

static _NavigationMode_Request_type_support_data_t _NavigationMode_Request_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _NavigationMode_Request_message_typesupport_map = {
  2,
  "shared_interfaces",
  &_NavigationMode_Request_message_typesupport_ids.typesupport_identifier[0],
  &_NavigationMode_Request_message_typesupport_symbol_names.symbol_name[0],
  &_NavigationMode_Request_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t NavigationMode_Request_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_NavigationMode_Request_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
  &shared_interfaces__srv__NavigationMode_Request__get_type_hash,
  &shared_interfaces__srv__NavigationMode_Request__get_type_description,
  &shared_interfaces__srv__NavigationMode_Request__get_type_description_sources,
};

}  // namespace rosidl_typesupport_c

}  // namespace srv

}  // namespace shared_interfaces

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, shared_interfaces, srv, NavigationMode_Request)() {
  return &::shared_interfaces::srv::rosidl_typesupport_c::NavigationMode_Request_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "shared_interfaces/srv/detail/navigation_mode__struct.h"
// already included above
// #include "shared_interfaces/srv/detail/navigation_mode__type_support.h"
// already included above
// #include "shared_interfaces/srv/detail/navigation_mode__functions.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
// already included above
// #include "rosidl_typesupport_c/message_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_c/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace shared_interfaces
{

namespace srv
{

namespace rosidl_typesupport_c
{

typedef struct _NavigationMode_Response_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _NavigationMode_Response_type_support_ids_t;

static const _NavigationMode_Response_type_support_ids_t _NavigationMode_Response_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _NavigationMode_Response_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _NavigationMode_Response_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _NavigationMode_Response_type_support_symbol_names_t _NavigationMode_Response_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, shared_interfaces, srv, NavigationMode_Response)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, shared_interfaces, srv, NavigationMode_Response)),
  }
};

typedef struct _NavigationMode_Response_type_support_data_t
{
  void * data[2];
} _NavigationMode_Response_type_support_data_t;

static _NavigationMode_Response_type_support_data_t _NavigationMode_Response_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _NavigationMode_Response_message_typesupport_map = {
  2,
  "shared_interfaces",
  &_NavigationMode_Response_message_typesupport_ids.typesupport_identifier[0],
  &_NavigationMode_Response_message_typesupport_symbol_names.symbol_name[0],
  &_NavigationMode_Response_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t NavigationMode_Response_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_NavigationMode_Response_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
  &shared_interfaces__srv__NavigationMode_Response__get_type_hash,
  &shared_interfaces__srv__NavigationMode_Response__get_type_description,
  &shared_interfaces__srv__NavigationMode_Response__get_type_description_sources,
};

}  // namespace rosidl_typesupport_c

}  // namespace srv

}  // namespace shared_interfaces

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, shared_interfaces, srv, NavigationMode_Response)() {
  return &::shared_interfaces::srv::rosidl_typesupport_c::NavigationMode_Response_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "shared_interfaces/srv/detail/navigation_mode__struct.h"
// already included above
// #include "shared_interfaces/srv/detail/navigation_mode__type_support.h"
// already included above
// #include "shared_interfaces/srv/detail/navigation_mode__functions.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
// already included above
// #include "rosidl_typesupport_c/message_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_c/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace shared_interfaces
{

namespace srv
{

namespace rosidl_typesupport_c
{

typedef struct _NavigationMode_Event_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _NavigationMode_Event_type_support_ids_t;

static const _NavigationMode_Event_type_support_ids_t _NavigationMode_Event_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _NavigationMode_Event_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _NavigationMode_Event_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _NavigationMode_Event_type_support_symbol_names_t _NavigationMode_Event_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, shared_interfaces, srv, NavigationMode_Event)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, shared_interfaces, srv, NavigationMode_Event)),
  }
};

typedef struct _NavigationMode_Event_type_support_data_t
{
  void * data[2];
} _NavigationMode_Event_type_support_data_t;

static _NavigationMode_Event_type_support_data_t _NavigationMode_Event_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _NavigationMode_Event_message_typesupport_map = {
  2,
  "shared_interfaces",
  &_NavigationMode_Event_message_typesupport_ids.typesupport_identifier[0],
  &_NavigationMode_Event_message_typesupport_symbol_names.symbol_name[0],
  &_NavigationMode_Event_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t NavigationMode_Event_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_NavigationMode_Event_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
  &shared_interfaces__srv__NavigationMode_Event__get_type_hash,
  &shared_interfaces__srv__NavigationMode_Event__get_type_description,
  &shared_interfaces__srv__NavigationMode_Event__get_type_description_sources,
};

}  // namespace rosidl_typesupport_c

}  // namespace srv

}  // namespace shared_interfaces

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, shared_interfaces, srv, NavigationMode_Event)() {
  return &::shared_interfaces::srv::rosidl_typesupport_c::NavigationMode_Event_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "shared_interfaces/srv/detail/navigation_mode__type_support.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
#include "rosidl_typesupport_c/service_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"
#include "service_msgs/msg/service_event_info.h"
#include "builtin_interfaces/msg/time.h"

namespace shared_interfaces
{

namespace srv
{

namespace rosidl_typesupport_c
{
typedef struct _NavigationMode_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _NavigationMode_type_support_ids_t;

static const _NavigationMode_type_support_ids_t _NavigationMode_service_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _NavigationMode_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _NavigationMode_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _NavigationMode_type_support_symbol_names_t _NavigationMode_service_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, shared_interfaces, srv, NavigationMode)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, shared_interfaces, srv, NavigationMode)),
  }
};

typedef struct _NavigationMode_type_support_data_t
{
  void * data[2];
} _NavigationMode_type_support_data_t;

static _NavigationMode_type_support_data_t _NavigationMode_service_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _NavigationMode_service_typesupport_map = {
  2,
  "shared_interfaces",
  &_NavigationMode_service_typesupport_ids.typesupport_identifier[0],
  &_NavigationMode_service_typesupport_symbol_names.symbol_name[0],
  &_NavigationMode_service_typesupport_data.data[0],
};

static const rosidl_service_type_support_t NavigationMode_service_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_NavigationMode_service_typesupport_map),
  rosidl_typesupport_c__get_service_typesupport_handle_function,
  &NavigationMode_Request_message_type_support_handle,
  &NavigationMode_Response_message_type_support_handle,
  &NavigationMode_Event_message_type_support_handle,
  ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_CREATE_EVENT_MESSAGE_SYMBOL_NAME(
    rosidl_typesupport_c,
    shared_interfaces,
    srv,
    NavigationMode
  ),
  ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_DESTROY_EVENT_MESSAGE_SYMBOL_NAME(
    rosidl_typesupport_c,
    shared_interfaces,
    srv,
    NavigationMode
  ),
  &shared_interfaces__srv__NavigationMode__get_type_hash,
  &shared_interfaces__srv__NavigationMode__get_type_description,
  &shared_interfaces__srv__NavigationMode__get_type_description_sources,
};

}  // namespace rosidl_typesupport_c

}  // namespace srv

}  // namespace shared_interfaces

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_c, shared_interfaces, srv, NavigationMode)() {
  return &::shared_interfaces::srv::rosidl_typesupport_c::NavigationMode_service_type_support_handle;
}

#ifdef __cplusplus
}
#endif
