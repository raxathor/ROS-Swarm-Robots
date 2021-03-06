// generated from rosidl_typesupport_connext_cpp/resource/idl__dds_connext__type_support.cpp.em
// with input from turtlesim:msg/Pose.idl
// generated code does not contain a copyright notice

#include <limits>
#include <stdexcept>

#include "turtlesim/msg/pose__rosidl_typesupport_connext_cpp.hpp"
#include "rcutils/types/uint8_array.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_connext_cpp/identifier.hpp"
#include "rosidl_typesupport_connext_cpp/message_type_support.h"
#include "rosidl_typesupport_connext_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_connext_cpp/wstring_conversion.hpp"

// forward declaration of message dependencies and their conversion functions


namespace turtlesim
{

namespace msg
{

namespace typesupport_connext_cpp
{


DDS_TypeCode *
get_type_code__Pose()
{
  return turtlesim::msg::dds_::Pose_TypeSupport::get_typecode();
}

bool
convert_ros_message_to_dds(
  const turtlesim::msg::Pose & ros_message,
  turtlesim::msg::dds_::Pose_ & dds_message)
{
  // member.name x
  dds_message.x_ =
    ros_message.x;

  // member.name y
  dds_message.y_ =
    ros_message.y;

  // member.name theta
  dds_message.theta_ =
    ros_message.theta;

  // member.name linear_velocity
  dds_message.linear_velocity_ =
    ros_message.linear_velocity;

  // member.name angular_velocity
  dds_message.angular_velocity_ =
    ros_message.angular_velocity;

  return true;
}

bool
convert_dds_message_to_ros(
  const turtlesim::msg::dds_::Pose_ & dds_message,
  turtlesim::msg::Pose & ros_message)
{
  // member.name x
  ros_message.x =
    dds_message.x_;

  // member.name y
  ros_message.y =
    dds_message.y_;

  // member.name theta
  ros_message.theta =
    dds_message.theta_;

  // member.name linear_velocity
  ros_message.linear_velocity =
    dds_message.linear_velocity_;

  // member.name angular_velocity
  ros_message.angular_velocity =
    dds_message.angular_velocity_;

  return true;
}

bool
to_cdr_stream__Pose(
  const void * untyped_ros_message,
  rcutils_uint8_array_t * cdr_stream)
{
  if (!cdr_stream) {
    return false;
  }
  if (!untyped_ros_message) {
    return false;
  }

  // cast the untyped to the known ros message
  const turtlesim::msg::Pose & ros_message =
    *(const turtlesim::msg::Pose *)untyped_ros_message;

  // create a respective connext dds type
  turtlesim::msg::dds_::Pose_ * dds_message = turtlesim::msg::dds_::Pose_TypeSupport::create_data();
  if (!dds_message) {
    return false;
  }

  // convert ros to dds
  if (!convert_ros_message_to_dds(ros_message, *dds_message)) {
    return false;
  }

  // call the serialize function for the first time to get the expected length of the message
  unsigned int expected_length;
  if (turtlesim::msg::dds_::Pose_Plugin_serialize_to_cdr_buffer(
      NULL,
      &expected_length,
      dds_message) != RTI_TRUE)
  {
    fprintf(stderr, "failed to call turtlesim::msg::dds_::Pose_Plugin_serialize_to_cdr_buffer()\n");
    return false;
  }
  if (expected_length > (std::numeric_limits<unsigned int>::max)()) {
    fprintf(stderr, "expected_length, unexpectedly larger than max unsigned int\n");
    return false;
  }
  if (cdr_stream->buffer_capacity < expected_length) {
    uint8_t * new_buffer = static_cast<uint8_t *>(cdr_stream->allocator.allocate(expected_length, cdr_stream->allocator.state));
    if (NULL == new_buffer) {
      fprintf(stderr, "failed to allocate memory for cdr data\n");
      return false;
    }
    cdr_stream->allocator.deallocate(cdr_stream->buffer, cdr_stream->allocator.state);
    cdr_stream->buffer = new_buffer;
    cdr_stream->buffer_capacity = expected_length;
  }
  // call the function again and fill the buffer this time
  unsigned int buffer_length_uint = static_cast<unsigned int>(expected_length);
  if (turtlesim::msg::dds_::Pose_Plugin_serialize_to_cdr_buffer(
      reinterpret_cast<char *>(cdr_stream->buffer),
      &buffer_length_uint,
      dds_message) != RTI_TRUE)
  {
    cdr_stream->buffer_length = 0;
    return false;
  }
  cdr_stream->buffer_length = expected_length;
  if (turtlesim::msg::dds_::Pose_TypeSupport::delete_data(dds_message) != DDS_RETCODE_OK) {
    return false;
  }
  return true;
}

bool
to_message__Pose(
  const rcutils_uint8_array_t * cdr_stream,
  void * untyped_ros_message)
{
  if (!cdr_stream) {
    return false;
  }
  if (!cdr_stream->buffer) {
    fprintf(stderr, "cdr stream doesn't contain data\n");
  }
  if (!untyped_ros_message) {
    return false;
  }

  turtlesim::msg::dds_::Pose_ * dds_message =
    turtlesim::msg::dds_::Pose_TypeSupport::create_data();
  if (cdr_stream->buffer_length > (std::numeric_limits<unsigned int>::max)()) {
    fprintf(stderr, "cdr_stream->buffer_length, unexpectedly larger than max unsigned int\n");
    return false;
  }
  if (turtlesim::msg::dds_::Pose_Plugin_deserialize_from_cdr_buffer(
      dds_message,
      reinterpret_cast<char *>(cdr_stream->buffer),
      static_cast<unsigned int>(cdr_stream->buffer_length)) != RTI_TRUE)
  {
    fprintf(stderr, "deserialize from cdr buffer failed\n");
    return false;
  }

  turtlesim::msg::Pose & ros_message =
    *(turtlesim::msg::Pose *)untyped_ros_message;
  bool success = convert_dds_message_to_ros(*dds_message, ros_message);
  if (turtlesim::msg::dds_::Pose_TypeSupport::delete_data(dds_message) != DDS_RETCODE_OK) {
    return false;
  }
  return success;
}

static message_type_support_callbacks_t _Pose__callbacks = {
  "turtlesim::msg",
  "Pose",
  &get_type_code__Pose,
  nullptr,
  nullptr,
  &to_cdr_stream__Pose,
  &to_message__Pose
};

static rosidl_message_type_support_t _Pose__handle = {
  rosidl_typesupport_connext_cpp::typesupport_identifier,
  &_Pose__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_connext_cpp

}  // namespace msg

}  // namespace turtlesim


namespace rosidl_typesupport_connext_cpp
{

template<>
ROSIDL_TYPESUPPORT_CONNEXT_CPP_EXPORT_turtlesim
const rosidl_message_type_support_t *
get_message_type_support_handle<turtlesim::msg::Pose>()
{
  return &turtlesim::msg::typesupport_connext_cpp::_Pose__handle;
}

}  // namespace rosidl_typesupport_connext_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
  rosidl_typesupport_connext_cpp,
  turtlesim, msg,
  Pose)()
{
  return &turtlesim::msg::typesupport_connext_cpp::_Pose__handle;
}

#ifdef __cplusplus
}
#endif
