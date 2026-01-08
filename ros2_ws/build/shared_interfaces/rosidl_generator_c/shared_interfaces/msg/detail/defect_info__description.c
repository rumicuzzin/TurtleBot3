// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from shared_interfaces:msg/DefectInfo.idl
// generated code does not contain a copyright notice

#include "shared_interfaces/msg/detail/defect_info__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_shared_interfaces
const rosidl_type_hash_t *
shared_interfaces__msg__DefectInfo__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x49, 0xbe, 0xa8, 0xd8, 0xc8, 0xc8, 0xfc, 0x94,
      0x18, 0xbf, 0xb4, 0xda, 0xc5, 0x6e, 0xda, 0x30,
      0xe0, 0xd4, 0x27, 0xf0, 0xe0, 0x9f, 0x71, 0x14,
      0x3d, 0x6d, 0x4e, 0x09, 0x06, 0x7e, 0xef, 0x80,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char shared_interfaces__msg__DefectInfo__TYPE_NAME[] = "shared_interfaces/msg/DefectInfo";

// Define type names, field names, and default values
static char shared_interfaces__msg__DefectInfo__FIELD_NAME__defect_found[] = "defect_found";
static char shared_interfaces__msg__DefectInfo__FIELD_NAME__angle[] = "angle";

static rosidl_runtime_c__type_description__Field shared_interfaces__msg__DefectInfo__FIELDS[] = {
  {
    {shared_interfaces__msg__DefectInfo__FIELD_NAME__defect_found, 12, 12},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {shared_interfaces__msg__DefectInfo__FIELD_NAME__angle, 5, 5},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
shared_interfaces__msg__DefectInfo__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {shared_interfaces__msg__DefectInfo__TYPE_NAME, 32, 32},
      {shared_interfaces__msg__DefectInfo__FIELDS, 2, 2},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "# Custom Message defectInfo\n"
  "# From defectDetector node to Controller node\n"
  "\n"
  "bool defect_found\n"
  "float32 angle";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
shared_interfaces__msg__DefectInfo__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {shared_interfaces__msg__DefectInfo__TYPE_NAME, 32, 32},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 107, 107},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
shared_interfaces__msg__DefectInfo__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *shared_interfaces__msg__DefectInfo__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
