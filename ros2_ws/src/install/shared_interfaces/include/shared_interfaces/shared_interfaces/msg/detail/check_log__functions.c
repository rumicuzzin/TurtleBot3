// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from shared_interfaces:msg/CheckLog.idl
// generated code does not contain a copyright notice
#include "shared_interfaces/msg/detail/check_log__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `task_type`
#include "rosidl_runtime_c/string_functions.h"
// Member `pose`
#include "geometry_msgs/msg/detail/pose_stamped__functions.h"

bool
shared_interfaces__msg__CheckLog__init(shared_interfaces__msg__CheckLog * msg)
{
  if (!msg) {
    return false;
  }
  // task_type
  if (!rosidl_runtime_c__String__init(&msg->task_type)) {
    shared_interfaces__msg__CheckLog__fini(msg);
    return false;
  }
  // index
  // pose
  if (!geometry_msgs__msg__PoseStamped__init(&msg->pose)) {
    shared_interfaces__msg__CheckLog__fini(msg);
    return false;
  }
  // complete
  return true;
}

void
shared_interfaces__msg__CheckLog__fini(shared_interfaces__msg__CheckLog * msg)
{
  if (!msg) {
    return;
  }
  // task_type
  rosidl_runtime_c__String__fini(&msg->task_type);
  // index
  // pose
  geometry_msgs__msg__PoseStamped__fini(&msg->pose);
  // complete
}

bool
shared_interfaces__msg__CheckLog__are_equal(const shared_interfaces__msg__CheckLog * lhs, const shared_interfaces__msg__CheckLog * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // task_type
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->task_type), &(rhs->task_type)))
  {
    return false;
  }
  // index
  if (lhs->index != rhs->index) {
    return false;
  }
  // pose
  if (!geometry_msgs__msg__PoseStamped__are_equal(
      &(lhs->pose), &(rhs->pose)))
  {
    return false;
  }
  // complete
  if (lhs->complete != rhs->complete) {
    return false;
  }
  return true;
}

bool
shared_interfaces__msg__CheckLog__copy(
  const shared_interfaces__msg__CheckLog * input,
  shared_interfaces__msg__CheckLog * output)
{
  if (!input || !output) {
    return false;
  }
  // task_type
  if (!rosidl_runtime_c__String__copy(
      &(input->task_type), &(output->task_type)))
  {
    return false;
  }
  // index
  output->index = input->index;
  // pose
  if (!geometry_msgs__msg__PoseStamped__copy(
      &(input->pose), &(output->pose)))
  {
    return false;
  }
  // complete
  output->complete = input->complete;
  return true;
}

shared_interfaces__msg__CheckLog *
shared_interfaces__msg__CheckLog__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  shared_interfaces__msg__CheckLog * msg = (shared_interfaces__msg__CheckLog *)allocator.allocate(sizeof(shared_interfaces__msg__CheckLog), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(shared_interfaces__msg__CheckLog));
  bool success = shared_interfaces__msg__CheckLog__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
shared_interfaces__msg__CheckLog__destroy(shared_interfaces__msg__CheckLog * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    shared_interfaces__msg__CheckLog__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
shared_interfaces__msg__CheckLog__Sequence__init(shared_interfaces__msg__CheckLog__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  shared_interfaces__msg__CheckLog * data = NULL;

  if (size) {
    data = (shared_interfaces__msg__CheckLog *)allocator.zero_allocate(size, sizeof(shared_interfaces__msg__CheckLog), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = shared_interfaces__msg__CheckLog__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        shared_interfaces__msg__CheckLog__fini(&data[i - 1]);
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
shared_interfaces__msg__CheckLog__Sequence__fini(shared_interfaces__msg__CheckLog__Sequence * array)
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
      shared_interfaces__msg__CheckLog__fini(&array->data[i]);
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

shared_interfaces__msg__CheckLog__Sequence *
shared_interfaces__msg__CheckLog__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  shared_interfaces__msg__CheckLog__Sequence * array = (shared_interfaces__msg__CheckLog__Sequence *)allocator.allocate(sizeof(shared_interfaces__msg__CheckLog__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = shared_interfaces__msg__CheckLog__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
shared_interfaces__msg__CheckLog__Sequence__destroy(shared_interfaces__msg__CheckLog__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    shared_interfaces__msg__CheckLog__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
shared_interfaces__msg__CheckLog__Sequence__are_equal(const shared_interfaces__msg__CheckLog__Sequence * lhs, const shared_interfaces__msg__CheckLog__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!shared_interfaces__msg__CheckLog__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
shared_interfaces__msg__CheckLog__Sequence__copy(
  const shared_interfaces__msg__CheckLog__Sequence * input,
  shared_interfaces__msg__CheckLog__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(shared_interfaces__msg__CheckLog);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    shared_interfaces__msg__CheckLog * data =
      (shared_interfaces__msg__CheckLog *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!shared_interfaces__msg__CheckLog__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          shared_interfaces__msg__CheckLog__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!shared_interfaces__msg__CheckLog__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
