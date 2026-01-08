// generated from rosidl_typesupport_cpp/resource/idl__type_support.cpp.em
// with input from shared_interfaces:srv/NavigationMode.idl
// generated code does not contain a copyright notice

#include "cstddef"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "shared_interfaces/srv/detail/navigation_mode__functions.h"
#include "shared_interfaces/srv/detail/navigation_mode__struct.hpp"
#include "rosidl_typesupport_cpp/identifier.hpp"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_c/type_support_map.h"
#include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
#include "rosidl_typesupport_cpp/visibility_control.h"
#include "rosidl_typesupport_interface/macros.h"

namespace shared_interfaces
{

namespace srv
{

namespace rosidl_typesupport_cpp
{

typedef struct _NavigationMode_Request_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _NavigationMode_Request_type_support_ids_t;

static const _NavigationMode_Request_type_support_ids_t _NavigationMode_Request_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
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
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, shared_interfaces, srv, NavigationMode_Request)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, shared_interfaces, srv, NavigationMode_Request)),
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
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_NavigationMode_Request_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
  &shared_interfaces__srv__NavigationMode_Request__get_type_hash,
  &shared_interfaces__srv__NavigationMode_Request__get_type_description,
  &shared_interfaces__srv__NavigationMode_Request__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace srv

}  // namespace shared_interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<shared_interfaces::srv::NavigationMode_Request>()
{
  return &::shared_interfaces::srv::rosidl_typesupport_cpp::NavigationMode_Request_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, shared_interfaces, srv, NavigationMode_Request)() {
  return get_message_type_support_handle<shared_interfaces::srv::NavigationMode_Request>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "shared_interfaces/srv/detail/navigation_mode__functions.h"
// already included above
// #include "shared_interfaces/srv/detail/navigation_mode__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace shared_interfaces
{

namespace srv
{

namespace rosidl_typesupport_cpp
{

typedef struct _NavigationMode_Response_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _NavigationMode_Response_type_support_ids_t;

static const _NavigationMode_Response_type_support_ids_t _NavigationMode_Response_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
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
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, shared_interfaces, srv, NavigationMode_Response)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, shared_interfaces, srv, NavigationMode_Response)),
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
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_NavigationMode_Response_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
  &shared_interfaces__srv__NavigationMode_Response__get_type_hash,
  &shared_interfaces__srv__NavigationMode_Response__get_type_description,
  &shared_interfaces__srv__NavigationMode_Response__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace srv

}  // namespace shared_interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<shared_interfaces::srv::NavigationMode_Response>()
{
  return &::shared_interfaces::srv::rosidl_typesupport_cpp::NavigationMode_Response_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, shared_interfaces, srv, NavigationMode_Response)() {
  return get_message_type_support_handle<shared_interfaces::srv::NavigationMode_Response>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "shared_interfaces/srv/detail/navigation_mode__functions.h"
// already included above
// #include "shared_interfaces/srv/detail/navigation_mode__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace shared_interfaces
{

namespace srv
{

namespace rosidl_typesupport_cpp
{

typedef struct _NavigationMode_Event_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _NavigationMode_Event_type_support_ids_t;

static const _NavigationMode_Event_type_support_ids_t _NavigationMode_Event_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
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
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, shared_interfaces, srv, NavigationMode_Event)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, shared_interfaces, srv, NavigationMode_Event)),
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
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_NavigationMode_Event_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
  &shared_interfaces__srv__NavigationMode_Event__get_type_hash,
  &shared_interfaces__srv__NavigationMode_Event__get_type_description,
  &shared_interfaces__srv__NavigationMode_Event__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace srv

}  // namespace shared_interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<shared_interfaces::srv::NavigationMode_Event>()
{
  return &::shared_interfaces::srv::rosidl_typesupport_cpp::NavigationMode_Event_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, shared_interfaces, srv, NavigationMode_Event)() {
  return get_message_type_support_handle<shared_interfaces::srv::NavigationMode_Event>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
#include "rosidl_runtime_c/service_type_support_struct.h"
#include "rosidl_typesupport_cpp/service_type_support.hpp"
// already included above
// #include "shared_interfaces/srv/detail/navigation_mode__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
#include "rosidl_typesupport_cpp/service_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace shared_interfaces
{

namespace srv
{

namespace rosidl_typesupport_cpp
{

typedef struct _NavigationMode_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _NavigationMode_type_support_ids_t;

static const _NavigationMode_type_support_ids_t _NavigationMode_service_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
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
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, shared_interfaces, srv, NavigationMode)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, shared_interfaces, srv, NavigationMode)),
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
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_NavigationMode_service_typesupport_map),
  ::rosidl_typesupport_cpp::get_service_typesupport_handle_function,
  ::rosidl_typesupport_cpp::get_message_type_support_handle<shared_interfaces::srv::NavigationMode_Request>(),
  ::rosidl_typesupport_cpp::get_message_type_support_handle<shared_interfaces::srv::NavigationMode_Response>(),
  ::rosidl_typesupport_cpp::get_message_type_support_handle<shared_interfaces::srv::NavigationMode_Event>(),
  &::rosidl_typesupport_cpp::service_create_event_message<shared_interfaces::srv::NavigationMode>,
  &::rosidl_typesupport_cpp::service_destroy_event_message<shared_interfaces::srv::NavigationMode>,
  &shared_interfaces__srv__NavigationMode__get_type_hash,
  &shared_interfaces__srv__NavigationMode__get_type_description,
  &shared_interfaces__srv__NavigationMode__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace srv

}  // namespace shared_interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_service_type_support_t *
get_service_type_support_handle<shared_interfaces::srv::NavigationMode>()
{
  return &::shared_interfaces::srv::rosidl_typesupport_cpp::NavigationMode_service_type_support_handle;
}

}  // namespace rosidl_typesupport_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_cpp, shared_interfaces, srv, NavigationMode)() {
  return ::rosidl_typesupport_cpp::get_service_type_support_handle<shared_interfaces::srv::NavigationMode>();
}

#ifdef __cplusplus
}
#endif
