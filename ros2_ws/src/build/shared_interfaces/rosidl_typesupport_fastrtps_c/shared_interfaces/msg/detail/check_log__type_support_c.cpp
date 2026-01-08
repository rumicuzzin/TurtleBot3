// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from shared_interfaces:msg/CheckLog.idl
// generated code does not contain a copyright notice
#include "shared_interfaces/msg/detail/check_log__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <cstddef>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/serialization_helpers.hpp"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "shared_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "shared_interfaces/msg/detail/check_log__struct.h"
#include "shared_interfaces/msg/detail/check_log__functions.h"
#include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif

#include "geometry_msgs/msg/detail/pose_stamped__functions.h"  // pose
#include "rosidl_runtime_c/string.h"  // task_type
#include "rosidl_runtime_c/string_functions.h"  // task_type

// forward declare type support functions

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_shared_interfaces
bool cdr_serialize_geometry_msgs__msg__PoseStamped(
  const geometry_msgs__msg__PoseStamped * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_shared_interfaces
bool cdr_deserialize_geometry_msgs__msg__PoseStamped(
  eprosima::fastcdr::Cdr & cdr,
  geometry_msgs__msg__PoseStamped * ros_message);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_shared_interfaces
size_t get_serialized_size_geometry_msgs__msg__PoseStamped(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_shared_interfaces
size_t max_serialized_size_geometry_msgs__msg__PoseStamped(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_shared_interfaces
bool cdr_serialize_key_geometry_msgs__msg__PoseStamped(
  const geometry_msgs__msg__PoseStamped * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_shared_interfaces
size_t get_serialized_size_key_geometry_msgs__msg__PoseStamped(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_shared_interfaces
size_t max_serialized_size_key_geometry_msgs__msg__PoseStamped(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_shared_interfaces
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, geometry_msgs, msg, PoseStamped)();


using _CheckLog__ros_msg_type = shared_interfaces__msg__CheckLog;


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_shared_interfaces
bool cdr_serialize_shared_interfaces__msg__CheckLog(
  const shared_interfaces__msg__CheckLog * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: task_type
  {
    const rosidl_runtime_c__String * str = &ros_message->task_type;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  // Field name: index
  {
    cdr << ros_message->index;
  }

  // Field name: pose
  {
    cdr_serialize_geometry_msgs__msg__PoseStamped(
      &ros_message->pose, cdr);
  }

  // Field name: complete
  {
    cdr << (ros_message->complete ? true : false);
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_shared_interfaces
bool cdr_deserialize_shared_interfaces__msg__CheckLog(
  eprosima::fastcdr::Cdr & cdr,
  shared_interfaces__msg__CheckLog * ros_message)
{
  // Field name: task_type
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->task_type.data) {
      rosidl_runtime_c__String__init(&ros_message->task_type);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->task_type,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'task_type'\n");
      return false;
    }
  }

  // Field name: index
  {
    cdr >> ros_message->index;
  }

  // Field name: pose
  {
    cdr_deserialize_geometry_msgs__msg__PoseStamped(cdr, &ros_message->pose);
  }

  // Field name: complete
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->complete = tmp ? true : false;
  }

  return true;
}  // NOLINT(readability/fn_size)


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_shared_interfaces
size_t get_serialized_size_shared_interfaces__msg__CheckLog(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _CheckLog__ros_msg_type * ros_message = static_cast<const _CheckLog__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: task_type
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->task_type.size + 1);

  // Field name: index
  {
    size_t item_size = sizeof(ros_message->index);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: pose
  current_alignment += get_serialized_size_geometry_msgs__msg__PoseStamped(
    &(ros_message->pose), current_alignment);

  // Field name: complete
  {
    size_t item_size = sizeof(ros_message->complete);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_shared_interfaces
size_t max_serialized_size_shared_interfaces__msg__CheckLog(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;

  // Field name: task_type
  {
    size_t array_size = 1;
    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }

  // Field name: index
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: pose
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_geometry_msgs__msg__PoseStamped(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: complete
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }


  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = shared_interfaces__msg__CheckLog;
    is_plain =
      (
      offsetof(DataType, complete) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_shared_interfaces
bool cdr_serialize_key_shared_interfaces__msg__CheckLog(
  const shared_interfaces__msg__CheckLog * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: task_type
  {
    const rosidl_runtime_c__String * str = &ros_message->task_type;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  // Field name: index
  {
    cdr << ros_message->index;
  }

  // Field name: pose
  {
    cdr_serialize_key_geometry_msgs__msg__PoseStamped(
      &ros_message->pose, cdr);
  }

  // Field name: complete
  {
    cdr << (ros_message->complete ? true : false);
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_shared_interfaces
size_t get_serialized_size_key_shared_interfaces__msg__CheckLog(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _CheckLog__ros_msg_type * ros_message = static_cast<const _CheckLog__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;

  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: task_type
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->task_type.size + 1);

  // Field name: index
  {
    size_t item_size = sizeof(ros_message->index);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: pose
  current_alignment += get_serialized_size_key_geometry_msgs__msg__PoseStamped(
    &(ros_message->pose), current_alignment);

  // Field name: complete
  {
    size_t item_size = sizeof(ros_message->complete);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_shared_interfaces
size_t max_serialized_size_key_shared_interfaces__msg__CheckLog(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;
  // Field name: task_type
  {
    size_t array_size = 1;
    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }

  // Field name: index
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: pose
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_key_geometry_msgs__msg__PoseStamped(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: complete
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = shared_interfaces__msg__CheckLog;
    is_plain =
      (
      offsetof(DataType, complete) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}


static bool _CheckLog__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const shared_interfaces__msg__CheckLog * ros_message = static_cast<const shared_interfaces__msg__CheckLog *>(untyped_ros_message);
  (void)ros_message;
  return cdr_serialize_shared_interfaces__msg__CheckLog(ros_message, cdr);
}

static bool _CheckLog__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  shared_interfaces__msg__CheckLog * ros_message = static_cast<shared_interfaces__msg__CheckLog *>(untyped_ros_message);
  (void)ros_message;
  return cdr_deserialize_shared_interfaces__msg__CheckLog(cdr, ros_message);
}

static uint32_t _CheckLog__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_shared_interfaces__msg__CheckLog(
      untyped_ros_message, 0));
}

static size_t _CheckLog__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_shared_interfaces__msg__CheckLog(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_CheckLog = {
  "shared_interfaces::msg",
  "CheckLog",
  _CheckLog__cdr_serialize,
  _CheckLog__cdr_deserialize,
  _CheckLog__get_serialized_size,
  _CheckLog__max_serialized_size,
  nullptr
};

static rosidl_message_type_support_t _CheckLog__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_CheckLog,
  get_message_typesupport_handle_function,
  &shared_interfaces__msg__CheckLog__get_type_hash,
  &shared_interfaces__msg__CheckLog__get_type_description,
  &shared_interfaces__msg__CheckLog__get_type_description_sources,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, shared_interfaces, msg, CheckLog)() {
  return &_CheckLog__type_support;
}

#if defined(__cplusplus)
}
#endif
