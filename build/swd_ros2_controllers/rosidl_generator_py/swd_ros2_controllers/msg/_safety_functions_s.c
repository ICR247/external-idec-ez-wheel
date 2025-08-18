// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from swd_ros2_controllers:msg/SafetyFunctions.idl
// generated code does not contain a copyright notice
#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#include <Python.h>
#include <stdbool.h>
#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-function"
#endif
#include "numpy/ndarrayobject.h"
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif
#include "rosidl_runtime_c/visibility_control.h"
#include "swd_ros2_controllers/msg/detail/safety_functions__struct.h"
#include "swd_ros2_controllers/msg/detail/safety_functions__functions.h"

ROSIDL_GENERATOR_C_IMPORT
bool std_msgs__msg__header__convert_from_py(PyObject * _pymsg, void * _ros_message);
ROSIDL_GENERATOR_C_IMPORT
PyObject * std_msgs__msg__header__convert_to_py(void * raw_ros_message);

ROSIDL_GENERATOR_C_EXPORT
bool swd_ros2_controllers__msg__safety_functions__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[59];
    {
      char * class_name = NULL;
      char * module_name = NULL;
      {
        PyObject * class_attr = PyObject_GetAttrString(_pymsg, "__class__");
        if (class_attr) {
          PyObject * name_attr = PyObject_GetAttrString(class_attr, "__name__");
          if (name_attr) {
            class_name = (char *)PyUnicode_1BYTE_DATA(name_attr);
            Py_DECREF(name_attr);
          }
          PyObject * module_attr = PyObject_GetAttrString(class_attr, "__module__");
          if (module_attr) {
            module_name = (char *)PyUnicode_1BYTE_DATA(module_attr);
            Py_DECREF(module_attr);
          }
          Py_DECREF(class_attr);
        }
      }
      if (!class_name || !module_name) {
        return false;
      }
      snprintf(full_classname_dest, sizeof(full_classname_dest), "%s.%s", module_name, class_name);
    }
    assert(strncmp("swd_ros2_controllers.msg._safety_functions.SafetyFunctions", full_classname_dest, 58) == 0);
  }
  swd_ros2_controllers__msg__SafetyFunctions * ros_message = _ros_message;
  {  // header
    PyObject * field = PyObject_GetAttrString(_pymsg, "header");
    if (!field) {
      return false;
    }
    if (!std_msgs__msg__header__convert_from_py(field, &ros_message->header)) {
      Py_DECREF(field);
      return false;
    }
    Py_DECREF(field);
  }
  {  // safe_torque_off
    PyObject * field = PyObject_GetAttrString(_pymsg, "safe_torque_off");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->safe_torque_off = (Py_True == field);
    Py_DECREF(field);
  }
  {  // safe_brake_control
    PyObject * field = PyObject_GetAttrString(_pymsg, "safe_brake_control");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->safe_brake_control = (Py_True == field);
    Py_DECREF(field);
  }
  {  // safety_limited_speed_1
    PyObject * field = PyObject_GetAttrString(_pymsg, "safety_limited_speed_1");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->safety_limited_speed_1 = (Py_True == field);
    Py_DECREF(field);
  }
  {  // safety_limited_speed_2
    PyObject * field = PyObject_GetAttrString(_pymsg, "safety_limited_speed_2");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->safety_limited_speed_2 = (Py_True == field);
    Py_DECREF(field);
  }
  {  // safe_direction_indication_forward
    PyObject * field = PyObject_GetAttrString(_pymsg, "safe_direction_indication_forward");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->safe_direction_indication_forward = (Py_True == field);
    Py_DECREF(field);
  }
  {  // safe_direction_indication_backward
    PyObject * field = PyObject_GetAttrString(_pymsg, "safe_direction_indication_backward");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->safe_direction_indication_backward = (Py_True == field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * swd_ros2_controllers__msg__safety_functions__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of SafetyFunctions */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("swd_ros2_controllers.msg._safety_functions");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "SafetyFunctions");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  swd_ros2_controllers__msg__SafetyFunctions * ros_message = (swd_ros2_controllers__msg__SafetyFunctions *)raw_ros_message;
  {  // header
    PyObject * field = NULL;
    field = std_msgs__msg__header__convert_to_py(&ros_message->header);
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "header", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // safe_torque_off
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->safe_torque_off ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "safe_torque_off", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // safe_brake_control
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->safe_brake_control ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "safe_brake_control", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // safety_limited_speed_1
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->safety_limited_speed_1 ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "safety_limited_speed_1", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // safety_limited_speed_2
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->safety_limited_speed_2 ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "safety_limited_speed_2", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // safe_direction_indication_forward
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->safe_direction_indication_forward ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "safe_direction_indication_forward", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // safe_direction_indication_backward
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->safe_direction_indication_backward ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "safe_direction_indication_backward", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
