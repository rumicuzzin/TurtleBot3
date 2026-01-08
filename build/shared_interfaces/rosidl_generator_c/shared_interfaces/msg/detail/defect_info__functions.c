// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from shared_interfaces:msg/DefectInfo.idl
// generated code does not contain a copyright notice
#include "shared_interfaces/msg/detail/defect_info__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
shared_interfaces__msg__DefectInfo__init(shared_interfaces__msg__DefectInfo * msg)
{
  if (!msg) {
    return false;
  }
  // defect_found
  // angle
  return true;
}

void
shared_interfaces__msg__DefectInfo__fini(shared_interfaces__msg__DefectInfo * msg)
{
  if (!msg) {
    return;
  }
  // defect_found
  // angle
}

bool
shared_interfaces__msg__DefectInfo__are_equal(const shared_interfaces__msg__DefectInfo * lhs, const shared_interfaces__msg__DefectInfo * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // defect_found
  if (lhs->defect_found != rhs->defect_found) {
    return false;
  }
  // angle
  if (lhs->angle != rhs->angle) {
    return false;
  }
  return true;
}

bool
shared_interfaces__msg__DefectInfo__copy(
  const shared_interfaces__msg__DefectInfo * input,
  shared_interfaces__msg__DefectInfo * output)
{
  if (!input || !output) {
    return false;
  }
  // defect_found
  output->defect_found = input->defect_found;
  // angle
  output->angle = input->angle;
  return true;
}

shared_interfaces__msg__DefectInfo *
shared_interfaces__msg__DefectInfo__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  shared_interfaces__msg__DefectInfo * msg = (shared_interfaces__msg__DefectInfo *)allocator.allocate(sizeof(shared_interfaces__msg__DefectInfo), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(shared_interfaces__msg__DefectInfo));
  bool success = shared_interfaces__msg__DefectInfo__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
shared_interfaces__msg__DefectInfo__destroy(shared_interfaces__msg__DefectInfo * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    shared_interfaces__msg__DefectInfo__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
shared_interfaces__msg__DefectInfo__Sequence__init(shared_interfaces__msg__DefectInfo__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  shared_interfaces__msg__DefectInfo * data = NULL;

  if (size) {
    data = (shared_interfaces__msg__DefectInfo *)allocator.zero_allocate(size, sizeof(shared_interfaces__msg__DefectInfo), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = shared_interfaces__msg__DefectInfo__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        shared_interfaces__msg__DefectInfo__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
shared_interfaces__msg__DefectInfo__Sequence__fini(shared_interfaces__msg__DefectInfo__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      shared_interfaces__msg__DefectInfo__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

shared_interfaces__msg__DefectInfo__Sequence *
shared_interfaces__msg__DefectInfo__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  shared_interfaces__msg__DefectInfo__Sequence * array = (shared_interfaces__msg__DefectInfo__Sequence *)allocator.allocate(sizeof(shared_interfaces__msg__DefectInfo__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = shared_interfaces__msg__DefectInfo__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
shared_interfaces__msg__DefectInfo__Sequence__destroy(shared_interfaces__msg__DefectInfo__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    shared_interfaces__msg__DefectInfo__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
shared_interfaces__msg__DefectInfo__Sequence__are_equal(const shared_interfaces__msg__DefectInfo__Sequence * lhs, const shared_interfaces__msg__DefectInfo__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!shared_interfaces__msg__DefectInfo__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
shared_interfaces__msg__DefectInfo__Sequence__copy(
  const shared_interfaces__msg__DefectInfo__Sequence * input,
  shared_interfaces__msg__DefectInfo__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(shared_interfaces__msg__DefectInfo);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    shared_interfaces__msg__DefectInfo * data =
      (shared_interfaces__msg__DefectInfo *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!shared_interfaces__msg__DefectInfo__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          shared_interfaces__msg__DefectInfo__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!shared_interfaces__msg__DefectInfo__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
