// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from shared_interfaces:msg/DefectInfo.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "shared_interfaces/msg/defect_info.h"


#ifndef SHARED_INTERFACES__MSG__DETAIL__DEFECT_INFO__STRUCT_H_
#define SHARED_INTERFACES__MSG__DETAIL__DEFECT_INFO__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Constants defined in the message

/// Struct defined in msg/DefectInfo in the package shared_interfaces.
/**
  * Custom Message defectInfo
  * From defectDetector node to Controller node
 */
typedef struct shared_interfaces__msg__DefectInfo
{
  bool defect_found;
  float angle;
} shared_interfaces__msg__DefectInfo;

// Struct for a sequence of shared_interfaces__msg__DefectInfo.
typedef struct shared_interfaces__msg__DefectInfo__Sequence
{
  shared_interfaces__msg__DefectInfo * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} shared_interfaces__msg__DefectInfo__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // SHARED_INTERFACES__MSG__DETAIL__DEFECT_INFO__STRUCT_H_
