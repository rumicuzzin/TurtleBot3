// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from shared_interfaces:srv/Detecting.idl
// generated code does not contain a copyright notice

#include "shared_interfaces/srv/detail/detecting__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_shared_interfaces
const rosidl_type_hash_t *
shared_interfaces__srv__Detecting__get_type_hash(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x2e, 0x8f, 0xbf, 0x78, 0x23, 0xba, 0x48, 0x68,
      0x7b, 0x3d, 0x43, 0x7c, 0xb8, 0xef, 0xbb, 0x10,
      0xc9, 0x6e, 0x1c, 0x4c, 0x3d, 0xb9, 0xbb, 0xdc,
      0xf5, 0x16, 0xb9, 0xb4, 0x91, 0x70, 0xd0, 0x87,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_shared_interfaces
const rosidl_type_hash_t *
shared_interfaces__srv__Detecting_Request__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x2b, 0x22, 0xda, 0x9c, 0xfa, 0x9b, 0x78, 0x7f,
      0x03, 0x38, 0x63, 0x51, 0xd8, 0xe7, 0xd1, 0xd9,
      0x2c, 0xb9, 0x5f, 0x77, 0x21, 0x6d, 0x61, 0x49,
      0x19, 0x6b, 0x3c, 0x4d, 0x7e, 0x3c, 0x8d, 0xa6,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_shared_interfaces
const rosidl_type_hash_t *
shared_interfaces__srv__Detecting_Response__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xa5, 0xa2, 0x4c, 0x33, 0x4c, 0x6d, 0xf1, 0x8e,
      0x3c, 0x32, 0x24, 0xae, 0xa5, 0x87, 0x2a, 0x5b,
      0x42, 0x04, 0x60, 0x0d, 0x4e, 0xaa, 0x94, 0xe0,
      0x74, 0x7b, 0xec, 0x9a, 0xf6, 0x5e, 0xe7, 0x0f,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_shared_interfaces
const rosidl_type_hash_t *
shared_interfaces__srv__Detecting_Event__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x0a, 0x15, 0x29, 0x9b, 0xe1, 0x4c, 0x2b, 0x44,
      0xe0, 0xdc, 0x60, 0x81, 0xe8, 0xe9, 0x74, 0x21,
      0x0d, 0x81, 0x42, 0xfc, 0xd4, 0xbf, 0x0a, 0xfa,
      0x46, 0x3b, 0xa3, 0xcd, 0x94, 0x94, 0x30, 0x34,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types
#include "builtin_interfaces/msg/detail/time__functions.h"
#include "service_msgs/msg/detail/service_event_info__functions.h"

// Hashes for external referenced types
#ifndef NDEBUG
static const rosidl_type_hash_t builtin_interfaces__msg__Time__EXPECTED_HASH = {1, {
    0xb1, 0x06, 0x23, 0x5e, 0x25, 0xa4, 0xc5, 0xed,
    0x35, 0x09, 0x8a, 0xa0, 0xa6, 0x1a, 0x3e, 0xe9,
    0xc9, 0xb1, 0x8d, 0x19, 0x7f, 0x39, 0x8b, 0x0e,
    0x42, 0x06, 0xce, 0xa9, 0xac, 0xf9, 0xc1, 0x97,
  }};
static const rosidl_type_hash_t service_msgs__msg__ServiceEventInfo__EXPECTED_HASH = {1, {
    0x41, 0xbc, 0xbb, 0xe0, 0x7a, 0x75, 0xc9, 0xb5,
    0x2b, 0xc9, 0x6b, 0xfd, 0x5c, 0x24, 0xd7, 0xf0,
    0xfc, 0x0a, 0x08, 0xc0, 0xcb, 0x79, 0x21, 0xb3,
    0x37, 0x3c, 0x57, 0x32, 0x34, 0x5a, 0x6f, 0x45,
  }};
#endif

static char shared_interfaces__srv__Detecting__TYPE_NAME[] = "shared_interfaces/srv/Detecting";
static char builtin_interfaces__msg__Time__TYPE_NAME[] = "builtin_interfaces/msg/Time";
static char service_msgs__msg__ServiceEventInfo__TYPE_NAME[] = "service_msgs/msg/ServiceEventInfo";
static char shared_interfaces__srv__Detecting_Event__TYPE_NAME[] = "shared_interfaces/srv/Detecting_Event";
static char shared_interfaces__srv__Detecting_Request__TYPE_NAME[] = "shared_interfaces/srv/Detecting_Request";
static char shared_interfaces__srv__Detecting_Response__TYPE_NAME[] = "shared_interfaces/srv/Detecting_Response";

// Define type names, field names, and default values
static char shared_interfaces__srv__Detecting__FIELD_NAME__request_message[] = "request_message";
static char shared_interfaces__srv__Detecting__FIELD_NAME__response_message[] = "response_message";
static char shared_interfaces__srv__Detecting__FIELD_NAME__event_message[] = "event_message";

static rosidl_runtime_c__type_description__Field shared_interfaces__srv__Detecting__FIELDS[] = {
  {
    {shared_interfaces__srv__Detecting__FIELD_NAME__request_message, 15, 15},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {shared_interfaces__srv__Detecting_Request__TYPE_NAME, 39, 39},
    },
    {NULL, 0, 0},
  },
  {
    {shared_interfaces__srv__Detecting__FIELD_NAME__response_message, 16, 16},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {shared_interfaces__srv__Detecting_Response__TYPE_NAME, 40, 40},
    },
    {NULL, 0, 0},
  },
  {
    {shared_interfaces__srv__Detecting__FIELD_NAME__event_message, 13, 13},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {shared_interfaces__srv__Detecting_Event__TYPE_NAME, 37, 37},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription shared_interfaces__srv__Detecting__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {builtin_interfaces__msg__Time__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    {NULL, 0, 0},
  },
  {
    {shared_interfaces__srv__Detecting_Event__TYPE_NAME, 37, 37},
    {NULL, 0, 0},
  },
  {
    {shared_interfaces__srv__Detecting_Request__TYPE_NAME, 39, 39},
    {NULL, 0, 0},
  },
  {
    {shared_interfaces__srv__Detecting_Response__TYPE_NAME, 40, 40},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
shared_interfaces__srv__Detecting__get_type_description(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {shared_interfaces__srv__Detecting__TYPE_NAME, 31, 31},
      {shared_interfaces__srv__Detecting__FIELDS, 3, 3},
    },
    {shared_interfaces__srv__Detecting__REFERENCED_TYPE_DESCRIPTIONS, 5, 5},
  };
  if (!constructed) {
    assert(0 == memcmp(&builtin_interfaces__msg__Time__EXPECTED_HASH, builtin_interfaces__msg__Time__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = builtin_interfaces__msg__Time__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&service_msgs__msg__ServiceEventInfo__EXPECTED_HASH, service_msgs__msg__ServiceEventInfo__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[1].fields = service_msgs__msg__ServiceEventInfo__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[2].fields = shared_interfaces__srv__Detecting_Event__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[3].fields = shared_interfaces__srv__Detecting_Request__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[4].fields = shared_interfaces__srv__Detecting_Response__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char shared_interfaces__srv__Detecting_Request__FIELD_NAME__marker_type[] = "marker_type";
static char shared_interfaces__srv__Detecting_Request__FIELD_NAME__command[] = "command";

static rosidl_runtime_c__type_description__Field shared_interfaces__srv__Detecting_Request__FIELDS[] = {
  {
    {shared_interfaces__srv__Detecting_Request__FIELD_NAME__marker_type, 11, 11},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {shared_interfaces__srv__Detecting_Request__FIELD_NAME__command, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
shared_interfaces__srv__Detecting_Request__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {shared_interfaces__srv__Detecting_Request__TYPE_NAME, 39, 39},
      {shared_interfaces__srv__Detecting_Request__FIELDS, 2, 2},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char shared_interfaces__srv__Detecting_Response__FIELD_NAME__success[] = "success";

static rosidl_runtime_c__type_description__Field shared_interfaces__srv__Detecting_Response__FIELDS[] = {
  {
    {shared_interfaces__srv__Detecting_Response__FIELD_NAME__success, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
shared_interfaces__srv__Detecting_Response__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {shared_interfaces__srv__Detecting_Response__TYPE_NAME, 40, 40},
      {shared_interfaces__srv__Detecting_Response__FIELDS, 1, 1},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char shared_interfaces__srv__Detecting_Event__FIELD_NAME__info[] = "info";
static char shared_interfaces__srv__Detecting_Event__FIELD_NAME__request[] = "request";
static char shared_interfaces__srv__Detecting_Event__FIELD_NAME__response[] = "response";

static rosidl_runtime_c__type_description__Field shared_interfaces__srv__Detecting_Event__FIELDS[] = {
  {
    {shared_interfaces__srv__Detecting_Event__FIELD_NAME__info, 4, 4},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    },
    {NULL, 0, 0},
  },
  {
    {shared_interfaces__srv__Detecting_Event__FIELD_NAME__request, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE_BOUNDED_SEQUENCE,
      1,
      0,
      {shared_interfaces__srv__Detecting_Request__TYPE_NAME, 39, 39},
    },
    {NULL, 0, 0},
  },
  {
    {shared_interfaces__srv__Detecting_Event__FIELD_NAME__response, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE_BOUNDED_SEQUENCE,
      1,
      0,
      {shared_interfaces__srv__Detecting_Response__TYPE_NAME, 40, 40},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription shared_interfaces__srv__Detecting_Event__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {builtin_interfaces__msg__Time__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    {NULL, 0, 0},
  },
  {
    {shared_interfaces__srv__Detecting_Request__TYPE_NAME, 39, 39},
    {NULL, 0, 0},
  },
  {
    {shared_interfaces__srv__Detecting_Response__TYPE_NAME, 40, 40},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
shared_interfaces__srv__Detecting_Event__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {shared_interfaces__srv__Detecting_Event__TYPE_NAME, 37, 37},
      {shared_interfaces__srv__Detecting_Event__FIELDS, 3, 3},
    },
    {shared_interfaces__srv__Detecting_Event__REFERENCED_TYPE_DESCRIPTIONS, 4, 4},
  };
  if (!constructed) {
    assert(0 == memcmp(&builtin_interfaces__msg__Time__EXPECTED_HASH, builtin_interfaces__msg__Time__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = builtin_interfaces__msg__Time__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&service_msgs__msg__ServiceEventInfo__EXPECTED_HASH, service_msgs__msg__ServiceEventInfo__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[1].fields = service_msgs__msg__ServiceEventInfo__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[2].fields = shared_interfaces__srv__Detecting_Request__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[3].fields = shared_interfaces__srv__Detecting_Response__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "# Service Detecting\n"
  "# Server: DefectDetector\n"
  "# Client: Manager\n"
  "\n"
  "string marker_type # \"defect\" or \"delivery\"\n"
  "string command  # \"start_detecting\" or \"stop_detecting\"\n"
  "---\n"
  "bool success";

static char srv_encoding[] = "srv";
static char implicit_encoding[] = "implicit";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
shared_interfaces__srv__Detecting__get_individual_type_description_source(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {shared_interfaces__srv__Detecting__TYPE_NAME, 31, 31},
    {srv_encoding, 3, 3},
    {toplevel_type_raw_source, 180, 180},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
shared_interfaces__srv__Detecting_Request__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {shared_interfaces__srv__Detecting_Request__TYPE_NAME, 39, 39},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
shared_interfaces__srv__Detecting_Response__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {shared_interfaces__srv__Detecting_Response__TYPE_NAME, 40, 40},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
shared_interfaces__srv__Detecting_Event__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {shared_interfaces__srv__Detecting_Event__TYPE_NAME, 37, 37},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
shared_interfaces__srv__Detecting__get_type_description_sources(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[6];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 6, 6};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *shared_interfaces__srv__Detecting__get_individual_type_description_source(NULL),
    sources[1] = *builtin_interfaces__msg__Time__get_individual_type_description_source(NULL);
    sources[2] = *service_msgs__msg__ServiceEventInfo__get_individual_type_description_source(NULL);
    sources[3] = *shared_interfaces__srv__Detecting_Event__get_individual_type_description_source(NULL);
    sources[4] = *shared_interfaces__srv__Detecting_Request__get_individual_type_description_source(NULL);
    sources[5] = *shared_interfaces__srv__Detecting_Response__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
shared_interfaces__srv__Detecting_Request__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *shared_interfaces__srv__Detecting_Request__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
shared_interfaces__srv__Detecting_Response__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *shared_interfaces__srv__Detecting_Response__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
shared_interfaces__srv__Detecting_Event__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[5];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 5, 5};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *shared_interfaces__srv__Detecting_Event__get_individual_type_description_source(NULL),
    sources[1] = *builtin_interfaces__msg__Time__get_individual_type_description_source(NULL);
    sources[2] = *service_msgs__msg__ServiceEventInfo__get_individual_type_description_source(NULL);
    sources[3] = *shared_interfaces__srv__Detecting_Request__get_individual_type_description_source(NULL);
    sources[4] = *shared_interfaces__srv__Detecting_Response__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}
