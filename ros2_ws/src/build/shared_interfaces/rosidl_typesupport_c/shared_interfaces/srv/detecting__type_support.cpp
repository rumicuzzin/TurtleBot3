// generated from rosidl_typesupport_c/resource/idl__type_support.cpp.em
// with input from shared_interfaces:srv/Detecting.idl
// generated code does not contain a copyright notice

#include "cstddef"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "shared_interfaces/srv/detail/detecting__struct.h"
#include "shared_interfaces/srv/detail/detecting__type_support.h"
#include "shared_interfaces/srv/detail/detecting__functions.h"
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

typedef struct _Detecting_Request_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _Detecting_Request_type_support_ids_t;

static const _Detecting_Request_type_support_ids_t _Detecting_Request_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _Detecting_Request_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _Detecting_Request_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _Detecting_Request_type_support_symbol_names_t _Detecting_Request_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, shared_interfaces, srv, Detecting_Request)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, shared_interfaces, srv, Detecting_Request)),
  }
};

typedef struct _Detecting_Request_type_support_data_t
{
  void * data[2];
} _Detecting_Request_type_support_data_t;

static _Detecting_Request_type_support_data_t _Detecting_Request_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _Detecting_Request_message_typesupport_map = {
  2,
  "shared_interfaces",
  &_Detecting_Request_message_typesupport_ids.typesupport_identifier[0],
  &_Detecting_Request_message_typesupport_symbol_names.symbol_name[0],
  &_Detecting_Request_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t Detecting_Request_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_Detecting_Request_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
  &shared_interfaces__srv__Detecting_Request__get_type_hash,
  &shared_interfaces__srv__Detecting_Request__get_type_description,
  &shared_interfaces__srv__Detecting_Request__get_type_description_sources,
};

}  // namespace rosidl_typesupport_c

}  // namespace srv

}  // namespace shared_interfaces

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, shared_interfaces, srv, Detecting_Request)() {
  return &::shared_interfaces::srv::rosidl_typesupport_c::Detecting_Request_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "shared_interfaces/srv/detail/detecting__struct.h"
// already included above
// #include "shared_interfaces/srv/detail/detecting__type_support.h"
// already included above
// #include "shared_interfaces/srv/detail/detecting__functions.h"
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

typedef struct _Detecting_Response_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _Detecting_Response_type_support_ids_t;

static const _Detecting_Response_type_support_ids_t _Detecting_Response_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _Detecting_Response_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _Detecting_Response_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _Detecting_Response_type_support_symbol_names_t _Detecting_Response_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, shared_interfaces, srv, Detecting_Response)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, shared_interfaces, srv, Detecting_Response)),
  }
};

typedef struct _Detecting_Response_type_support_data_t
{
  void * data[2];
} _Detecting_Response_type_support_data_t;

static _Detecting_Response_type_support_data_t _Detecting_Response_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _Detecting_Response_message_typesupport_map = {
  2,
  "shared_interfaces",
  &_Detecting_Response_message_typesupport_ids.typesupport_identifier[0],
  &_Detecting_Response_message_typesupport_symbol_names.symbol_name[0],
  &_Detecting_Response_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t Detecting_Response_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_Detecting_Response_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
  &shared_interfaces__srv__Detecting_Response__get_type_hash,
  &shared_interfaces__srv__Detecting_Response__get_type_description,
  &shared_interfaces__srv__Detecting_Response__get_type_description_sources,
};

}  // namespace rosidl_typesupport_c

}  // namespace srv

}  // namespace shared_interfaces

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, shared_interfaces, srv, Detecting_Response)() {
  return &::shared_interfaces::srv::rosidl_typesupport_c::Detecting_Response_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "shared_interfaces/srv/detail/detecting__struct.h"
// already included above
// #include "shared_interfaces/srv/detail/detecting__type_support.h"
// already included above
// #include "shared_interfaces/srv/detail/detecting__functions.h"
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

typedef struct _Detecting_Event_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _Detecting_Event_type_support_ids_t;

static const _Detecting_Event_type_support_ids_t _Detecting_Event_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _Detecting_Event_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _Detecting_Event_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _Detecting_Event_type_support_symbol_names_t _Detecting_Event_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, shared_interfaces, srv, Detecting_Event)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, shared_interfaces, srv, Detecting_Event)),
  }
};

typedef struct _Detecting_Event_type_support_data_t
{
  void * data[2];
} _Detecting_Event_type_support_data_t;

static _Detecting_Event_type_support_data_t _Detecting_Event_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _Detecting_Event_message_typesupport_map = {
  2,
  "shared_interfaces",
  &_Detecting_Event_message_typesupport_ids.typesupport_identifier[0],
  &_Detecting_Event_message_typesupport_symbol_names.symbol_name[0],
  &_Detecting_Event_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t Detecting_Event_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_Detecting_Event_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
  &shared_interfaces__srv__Detecting_Event__get_type_hash,
  &shared_interfaces__srv__Detecting_Event__get_type_description,
  &shared_interfaces__srv__Detecting_Event__get_type_description_sources,
};

}  // namespace rosidl_typesupport_c

}  // namespace srv

}  // namespace shared_interfaces

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, shared_interfaces, srv, Detecting_Event)() {
  return &::shared_interfaces::srv::rosidl_typesupport_c::Detecting_Event_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "shared_interfaces/srv/detail/detecting__type_support.h"
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
typedef struct _Detecting_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _Detecting_type_support_ids_t;

static const _Detecting_type_support_ids_t _Detecting_service_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _Detecting_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _Detecting_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _Detecting_type_support_symbol_names_t _Detecting_service_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, shared_interfaces, srv, Detecting)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, shared_interfaces, srv, Detecting)),
  }
};

typedef struct _Detecting_type_support_data_t
{
  void * data[2];
} _Detecting_type_support_data_t;

static _Detecting_type_support_data_t _Detecting_service_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _Detecting_service_typesupport_map = {
  2,
  "shared_interfaces",
  &_Detecting_service_typesupport_ids.typesupport_identifier[0],
  &_Detecting_service_typesupport_symbol_names.symbol_name[0],
  &_Detecting_service_typesupport_data.data[0],
};

static const rosidl_service_type_support_t Detecting_service_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_Detecting_service_typesupport_map),
  rosidl_typesupport_c__get_service_typesupport_handle_function,
  &Detecting_Request_message_type_support_handle,
  &Detecting_Response_message_type_support_handle,
  &Detecting_Event_message_type_support_handle,
  ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_CREATE_EVENT_MESSAGE_SYMBOL_NAME(
    rosidl_typesupport_c,
    shared_interfaces,
    srv,
    Detecting
  ),
  ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_DESTROY_EVENT_MESSAGE_SYMBOL_NAME(
    rosidl_typesupport_c,
    shared_interfaces,
    srv,
    Detecting
  ),
  &shared_interfaces__srv__Detecting__get_type_hash,
  &shared_interfaces__srv__Detecting__get_type_description,
  &shared_interfaces__srv__Detecting__get_type_description_sources,
};

}  // namespace rosidl_typesupport_c

}  // namespace srv

}  // namespace shared_interfaces

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_c, shared_interfaces, srv, Detecting)() {
  return &::shared_interfaces::srv::rosidl_typesupport_c::Detecting_service_type_support_handle;
}

#ifdef __cplusplus
}
#endif
