// generated from rosidl_typesupport_cpp/resource/idl__type_support.cpp.em
// with input from shared_interfaces:srv/Charging.idl
// generated code does not contain a copyright notice

#include "cstddef"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "shared_interfaces/srv/detail/charging__functions.h"
#include "shared_interfaces/srv/detail/charging__struct.hpp"
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

typedef struct _Charging_Request_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _Charging_Request_type_support_ids_t;

static const _Charging_Request_type_support_ids_t _Charging_Request_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _Charging_Request_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _Charging_Request_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _Charging_Request_type_support_symbol_names_t _Charging_Request_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, shared_interfaces, srv, Charging_Request)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, shared_interfaces, srv, Charging_Request)),
  }
};

typedef struct _Charging_Request_type_support_data_t
{
  void * data[2];
} _Charging_Request_type_support_data_t;

static _Charging_Request_type_support_data_t _Charging_Request_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _Charging_Request_message_typesupport_map = {
  2,
  "shared_interfaces",
  &_Charging_Request_message_typesupport_ids.typesupport_identifier[0],
  &_Charging_Request_message_typesupport_symbol_names.symbol_name[0],
  &_Charging_Request_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t Charging_Request_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_Charging_Request_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
  &shared_interfaces__srv__Charging_Request__get_type_hash,
  &shared_interfaces__srv__Charging_Request__get_type_description,
  &shared_interfaces__srv__Charging_Request__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace srv

}  // namespace shared_interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<shared_interfaces::srv::Charging_Request>()
{
  return &::shared_interfaces::srv::rosidl_typesupport_cpp::Charging_Request_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, shared_interfaces, srv, Charging_Request)() {
  return get_message_type_support_handle<shared_interfaces::srv::Charging_Request>();
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
// #include "shared_interfaces/srv/detail/charging__functions.h"
// already included above
// #include "shared_interfaces/srv/detail/charging__struct.hpp"
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

typedef struct _Charging_Response_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _Charging_Response_type_support_ids_t;

static const _Charging_Response_type_support_ids_t _Charging_Response_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _Charging_Response_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _Charging_Response_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _Charging_Response_type_support_symbol_names_t _Charging_Response_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, shared_interfaces, srv, Charging_Response)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, shared_interfaces, srv, Charging_Response)),
  }
};

typedef struct _Charging_Response_type_support_data_t
{
  void * data[2];
} _Charging_Response_type_support_data_t;

static _Charging_Response_type_support_data_t _Charging_Response_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _Charging_Response_message_typesupport_map = {
  2,
  "shared_interfaces",
  &_Charging_Response_message_typesupport_ids.typesupport_identifier[0],
  &_Charging_Response_message_typesupport_symbol_names.symbol_name[0],
  &_Charging_Response_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t Charging_Response_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_Charging_Response_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
  &shared_interfaces__srv__Charging_Response__get_type_hash,
  &shared_interfaces__srv__Charging_Response__get_type_description,
  &shared_interfaces__srv__Charging_Response__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace srv

}  // namespace shared_interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<shared_interfaces::srv::Charging_Response>()
{
  return &::shared_interfaces::srv::rosidl_typesupport_cpp::Charging_Response_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, shared_interfaces, srv, Charging_Response)() {
  return get_message_type_support_handle<shared_interfaces::srv::Charging_Response>();
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
// #include "shared_interfaces/srv/detail/charging__functions.h"
// already included above
// #include "shared_interfaces/srv/detail/charging__struct.hpp"
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

typedef struct _Charging_Event_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _Charging_Event_type_support_ids_t;

static const _Charging_Event_type_support_ids_t _Charging_Event_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _Charging_Event_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _Charging_Event_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _Charging_Event_type_support_symbol_names_t _Charging_Event_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, shared_interfaces, srv, Charging_Event)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, shared_interfaces, srv, Charging_Event)),
  }
};

typedef struct _Charging_Event_type_support_data_t
{
  void * data[2];
} _Charging_Event_type_support_data_t;

static _Charging_Event_type_support_data_t _Charging_Event_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _Charging_Event_message_typesupport_map = {
  2,
  "shared_interfaces",
  &_Charging_Event_message_typesupport_ids.typesupport_identifier[0],
  &_Charging_Event_message_typesupport_symbol_names.symbol_name[0],
  &_Charging_Event_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t Charging_Event_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_Charging_Event_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
  &shared_interfaces__srv__Charging_Event__get_type_hash,
  &shared_interfaces__srv__Charging_Event__get_type_description,
  &shared_interfaces__srv__Charging_Event__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace srv

}  // namespace shared_interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<shared_interfaces::srv::Charging_Event>()
{
  return &::shared_interfaces::srv::rosidl_typesupport_cpp::Charging_Event_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, shared_interfaces, srv, Charging_Event)() {
  return get_message_type_support_handle<shared_interfaces::srv::Charging_Event>();
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
// #include "shared_interfaces/srv/detail/charging__struct.hpp"
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

typedef struct _Charging_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _Charging_type_support_ids_t;

static const _Charging_type_support_ids_t _Charging_service_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _Charging_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _Charging_type_support_symbol_names_t;
#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _Charging_type_support_symbol_names_t _Charging_service_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, shared_interfaces, srv, Charging)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, shared_interfaces, srv, Charging)),
  }
};

typedef struct _Charging_type_support_data_t
{
  void * data[2];
} _Charging_type_support_data_t;

static _Charging_type_support_data_t _Charging_service_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _Charging_service_typesupport_map = {
  2,
  "shared_interfaces",
  &_Charging_service_typesupport_ids.typesupport_identifier[0],
  &_Charging_service_typesupport_symbol_names.symbol_name[0],
  &_Charging_service_typesupport_data.data[0],
};

static const rosidl_service_type_support_t Charging_service_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_Charging_service_typesupport_map),
  ::rosidl_typesupport_cpp::get_service_typesupport_handle_function,
  ::rosidl_typesupport_cpp::get_message_type_support_handle<shared_interfaces::srv::Charging_Request>(),
  ::rosidl_typesupport_cpp::get_message_type_support_handle<shared_interfaces::srv::Charging_Response>(),
  ::rosidl_typesupport_cpp::get_message_type_support_handle<shared_interfaces::srv::Charging_Event>(),
  &::rosidl_typesupport_cpp::service_create_event_message<shared_interfaces::srv::Charging>,
  &::rosidl_typesupport_cpp::service_destroy_event_message<shared_interfaces::srv::Charging>,
  &shared_interfaces__srv__Charging__get_type_hash,
  &shared_interfaces__srv__Charging__get_type_description,
  &shared_interfaces__srv__Charging__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace srv

}  // namespace shared_interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_service_type_support_t *
get_service_type_support_handle<shared_interfaces::srv::Charging>()
{
  return &::shared_interfaces::srv::rosidl_typesupport_cpp::Charging_service_type_support_handle;
}

}  // namespace rosidl_typesupport_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_cpp, shared_interfaces, srv, Charging)() {
  return ::rosidl_typesupport_cpp::get_service_type_support_handle<shared_interfaces::srv::Charging>();
}

#ifdef __cplusplus
}
#endif
