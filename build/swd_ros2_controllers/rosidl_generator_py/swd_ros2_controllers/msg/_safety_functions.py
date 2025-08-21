# generated from rosidl_generator_py/resource/_idl.py.em
# with input from swd_ros2_controllers:msg/SafetyFunctions.idl
# generated code does not contain a copyright notice

# This is being done at the module level and not on the instance level to avoid looking
# for the same variable multiple times on each instance. This variable is not supposed to
# change during runtime so it makes sense to only look for it once.
from os import getenv

ros_python_check_fields = getenv('ROS_PYTHON_CHECK_FIELDS', default='')


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_SafetyFunctions(type):
    """Metaclass of message 'SafetyFunctions'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('swd_ros2_controllers')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'swd_ros2_controllers.msg.SafetyFunctions')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__safety_functions
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__safety_functions
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__safety_functions
            cls._TYPE_SUPPORT = module.type_support_msg__msg__safety_functions
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__safety_functions

            from std_msgs.msg import Header
            if Header.__class__._TYPE_SUPPORT is None:
                Header.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class SafetyFunctions(metaclass=Metaclass_SafetyFunctions):
    """Message class 'SafetyFunctions'."""

    __slots__ = [
        '_header',
        '_safe_torque_off',
        '_safe_brake_control',
        '_safety_limited_speed_1',
        '_safety_limited_speed_2',
        '_safe_direction_indication_forward',
        '_safe_direction_indication_backward',
        '_check_fields',
    ]

    _fields_and_field_types = {
        'header': 'std_msgs/Header',
        'safe_torque_off': 'boolean',
        'safe_brake_control': 'boolean',
        'safety_limited_speed_1': 'boolean',
        'safety_limited_speed_2': 'boolean',
        'safe_direction_indication_forward': 'boolean',
        'safe_direction_indication_backward': 'boolean',
    }

    # This attribute is used to store an rosidl_parser.definition variable
    # related to the data type of each of the components the message.
    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['std_msgs', 'msg'], 'Header'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        if 'check_fields' in kwargs:
            self._check_fields = kwargs['check_fields']
        else:
            self._check_fields = ros_python_check_fields == '1'
        if self._check_fields:
            assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
                'Invalid arguments passed to constructor: %s' % \
                ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from std_msgs.msg import Header
        self.header = kwargs.get('header', Header())
        self.safe_torque_off = kwargs.get('safe_torque_off', bool())
        self.safe_brake_control = kwargs.get('safe_brake_control', bool())
        self.safety_limited_speed_1 = kwargs.get('safety_limited_speed_1', bool())
        self.safety_limited_speed_2 = kwargs.get('safety_limited_speed_2', bool())
        self.safe_direction_indication_forward = kwargs.get('safe_direction_indication_forward', bool())
        self.safe_direction_indication_backward = kwargs.get('safe_direction_indication_backward', bool())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.get_fields_and_field_types().keys(), self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    if self._check_fields:
                        assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.header != other.header:
            return False
        if self.safe_torque_off != other.safe_torque_off:
            return False
        if self.safe_brake_control != other.safe_brake_control:
            return False
        if self.safety_limited_speed_1 != other.safety_limited_speed_1:
            return False
        if self.safety_limited_speed_2 != other.safety_limited_speed_2:
            return False
        if self.safe_direction_indication_forward != other.safe_direction_indication_forward:
            return False
        if self.safe_direction_indication_backward != other.safe_direction_indication_backward:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def header(self):
        """Message field 'header'."""
        return self._header

    @header.setter
    def header(self, value):
        if self._check_fields:
            from std_msgs.msg import Header
            assert \
                isinstance(value, Header), \
                "The 'header' field must be a sub message of type 'Header'"
        self._header = value

    @builtins.property
    def safe_torque_off(self):
        """Message field 'safe_torque_off'."""
        return self._safe_torque_off

    @safe_torque_off.setter
    def safe_torque_off(self, value):
        if self._check_fields:
            assert \
                isinstance(value, bool), \
                "The 'safe_torque_off' field must be of type 'bool'"
        self._safe_torque_off = value

    @builtins.property
    def safe_brake_control(self):
        """Message field 'safe_brake_control'."""
        return self._safe_brake_control

    @safe_brake_control.setter
    def safe_brake_control(self, value):
        if self._check_fields:
            assert \
                isinstance(value, bool), \
                "The 'safe_brake_control' field must be of type 'bool'"
        self._safe_brake_control = value

    @builtins.property
    def safety_limited_speed_1(self):
        """Message field 'safety_limited_speed_1'."""
        return self._safety_limited_speed_1

    @safety_limited_speed_1.setter
    def safety_limited_speed_1(self, value):
        if self._check_fields:
            assert \
                isinstance(value, bool), \
                "The 'safety_limited_speed_1' field must be of type 'bool'"
        self._safety_limited_speed_1 = value

    @builtins.property
    def safety_limited_speed_2(self):
        """Message field 'safety_limited_speed_2'."""
        return self._safety_limited_speed_2

    @safety_limited_speed_2.setter
    def safety_limited_speed_2(self, value):
        if self._check_fields:
            assert \
                isinstance(value, bool), \
                "The 'safety_limited_speed_2' field must be of type 'bool'"
        self._safety_limited_speed_2 = value

    @builtins.property
    def safe_direction_indication_forward(self):
        """Message field 'safe_direction_indication_forward'."""
        return self._safe_direction_indication_forward

    @safe_direction_indication_forward.setter
    def safe_direction_indication_forward(self, value):
        if self._check_fields:
            assert \
                isinstance(value, bool), \
                "The 'safe_direction_indication_forward' field must be of type 'bool'"
        self._safe_direction_indication_forward = value

    @builtins.property
    def safe_direction_indication_backward(self):
        """Message field 'safe_direction_indication_backward'."""
        return self._safe_direction_indication_backward

    @safe_direction_indication_backward.setter
    def safe_direction_indication_backward(self, value):
        if self._check_fields:
            assert \
                isinstance(value, bool), \
                "The 'safe_direction_indication_backward' field must be of type 'bool'"
        self._safe_direction_indication_backward = value
