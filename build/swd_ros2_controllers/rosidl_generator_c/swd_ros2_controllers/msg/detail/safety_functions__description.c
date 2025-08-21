// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from swd_ros2_controllers:msg/SafetyFunctions.idl
// generated code does not contain a copyright notice

#include "swd_ros2_controllers/msg/detail/safety_functions__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_swd_ros2_controllers
const rosidl_type_hash_t *
swd_ros2_controllers__msg__SafetyFunctions__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x45, 0xcb, 0x98, 0x67, 0x74, 0xa9, 0x59, 0x90,
      0x80, 0xe1, 0x8e, 0xd9, 0x64, 0xfd, 0x97, 0x06,
      0x4a, 0xf2, 0xb5, 0xf0, 0x20, 0xda, 0x07, 0xcd,
      0x3e, 0x6e, 0x0e, 0xff, 0x2a, 0x73, 0x5a, 0x5b,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types
#include "builtin_interfaces/msg/detail/time__functions.h"
#include "std_msgs/msg/detail/header__functions.h"

// Hashes for external referenced types
#ifndef NDEBUG
static const rosidl_type_hash_t builtin_interfaces__msg__Time__EXPECTED_HASH = {1, {
    0xb1, 0x06, 0x23, 0x5e, 0x25, 0xa4, 0xc5, 0xed,
    0x35, 0x09, 0x8a, 0xa0, 0xa6, 0x1a, 0x3e, 0xe9,
    0xc9, 0xb1, 0x8d, 0x19, 0x7f, 0x39, 0x8b, 0x0e,
    0x42, 0x06, 0xce, 0xa9, 0xac, 0xf9, 0xc1, 0x97,
  }};
static const rosidl_type_hash_t std_msgs__msg__Header__EXPECTED_HASH = {1, {
    0xf4, 0x9f, 0xb3, 0xae, 0x2c, 0xf0, 0x70, 0xf7,
    0x93, 0x64, 0x5f, 0xf7, 0x49, 0x68, 0x3a, 0xc6,
    0xb0, 0x62, 0x03, 0xe4, 0x1c, 0x89, 0x1e, 0x17,
    0x70, 0x1b, 0x1c, 0xb5, 0x97, 0xce, 0x6a, 0x01,
  }};
#endif

static char swd_ros2_controllers__msg__SafetyFunctions__TYPE_NAME[] = "swd_ros2_controllers/msg/SafetyFunctions";
static char builtin_interfaces__msg__Time__TYPE_NAME[] = "builtin_interfaces/msg/Time";
static char std_msgs__msg__Header__TYPE_NAME[] = "std_msgs/msg/Header";

// Define type names, field names, and default values
static char swd_ros2_controllers__msg__SafetyFunctions__FIELD_NAME__header[] = "header";
static char swd_ros2_controllers__msg__SafetyFunctions__FIELD_NAME__safe_torque_off[] = "safe_torque_off";
static char swd_ros2_controllers__msg__SafetyFunctions__FIELD_NAME__safe_brake_control[] = "safe_brake_control";
static char swd_ros2_controllers__msg__SafetyFunctions__FIELD_NAME__safety_limited_speed_1[] = "safety_limited_speed_1";
static char swd_ros2_controllers__msg__SafetyFunctions__FIELD_NAME__safety_limited_speed_2[] = "safety_limited_speed_2";
static char swd_ros2_controllers__msg__SafetyFunctions__FIELD_NAME__safe_direction_indication_forward[] = "safe_direction_indication_forward";
static char swd_ros2_controllers__msg__SafetyFunctions__FIELD_NAME__safe_direction_indication_backward[] = "safe_direction_indication_backward";

static rosidl_runtime_c__type_description__Field swd_ros2_controllers__msg__SafetyFunctions__FIELDS[] = {
  {
    {swd_ros2_controllers__msg__SafetyFunctions__FIELD_NAME__header, 6, 6},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {std_msgs__msg__Header__TYPE_NAME, 19, 19},
    },
    {NULL, 0, 0},
  },
  {
    {swd_ros2_controllers__msg__SafetyFunctions__FIELD_NAME__safe_torque_off, 15, 15},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {swd_ros2_controllers__msg__SafetyFunctions__FIELD_NAME__safe_brake_control, 18, 18},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {swd_ros2_controllers__msg__SafetyFunctions__FIELD_NAME__safety_limited_speed_1, 22, 22},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {swd_ros2_controllers__msg__SafetyFunctions__FIELD_NAME__safety_limited_speed_2, 22, 22},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {swd_ros2_controllers__msg__SafetyFunctions__FIELD_NAME__safe_direction_indication_forward, 33, 33},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {swd_ros2_controllers__msg__SafetyFunctions__FIELD_NAME__safe_direction_indication_backward, 34, 34},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription swd_ros2_controllers__msg__SafetyFunctions__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {builtin_interfaces__msg__Time__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {std_msgs__msg__Header__TYPE_NAME, 19, 19},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
swd_ros2_controllers__msg__SafetyFunctions__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {swd_ros2_controllers__msg__SafetyFunctions__TYPE_NAME, 40, 40},
      {swd_ros2_controllers__msg__SafetyFunctions__FIELDS, 7, 7},
    },
    {swd_ros2_controllers__msg__SafetyFunctions__REFERENCED_TYPE_DESCRIPTIONS, 2, 2},
  };
  if (!constructed) {
    assert(0 == memcmp(&builtin_interfaces__msg__Time__EXPECTED_HASH, builtin_interfaces__msg__Time__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = builtin_interfaces__msg__Time__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&std_msgs__msg__Header__EXPECTED_HASH, std_msgs__msg__Header__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[1].fields = std_msgs__msg__Header__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "# This message provides information about CiA 402-4 CANopen safety drive functions.\n"
  "# True if the safety drive function is enabled.\n"
  "\n"
  "std_msgs/Header header\n"
  "bool safe_torque_off                        # Safe Torque Off (STO)\n"
  "bool safe_brake_control                     # Safe Brake Control (SBC)\n"
  "bool safety_limited_speed_1                 # Safety Limited Speed 1 (SLS_1)\n"
  "bool safety_limited_speed_2                 # Safety Limited Speed 2 (SLS_2)\n"
  "bool safe_direction_indication_forward      # Safe Direction Indication (positive)\n"
  "bool safe_direction_indication_backward     # Safe Direction Indication (negative)\n"
  "\n"
  "# The main safe drive function is the STO whereby the immediately torque-off on the motor may be accompanied by an SBC command to close the brakes. \n"
  "# The SLS functions cause the drive to decelerate (if required) and monitor whether the velocity is held within the defined limits.\n"
  "# The functions SDIp and SDIn enable the motor movement only in the corresponding (positive or negative) direction. ";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
swd_ros2_controllers__msg__SafetyFunctions__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {swd_ros2_controllers__msg__SafetyFunctions__TYPE_NAME, 40, 40},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 1013, 1013},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
swd_ros2_controllers__msg__SafetyFunctions__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[3];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 3, 3};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *swd_ros2_controllers__msg__SafetyFunctions__get_individual_type_description_source(NULL),
    sources[1] = *builtin_interfaces__msg__Time__get_individual_type_description_source(NULL);
    sources[2] = *std_msgs__msg__Header__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}
