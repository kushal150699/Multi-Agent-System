# generated from rosidl_generator_py/resource/_idl.py.em
# with input from campus_tour_interfaces:msg/NavigationPath.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_NavigationPath(type):
    """Metaclass of message 'NavigationPath'."""

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
            module = import_type_support('campus_tour_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'campus_tour_interfaces.msg.NavigationPath')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__navigation_path
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__navigation_path
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__navigation_path
            cls._TYPE_SUPPORT = module.type_support_msg__msg__navigation_path
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__navigation_path

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class NavigationPath(metaclass=Metaclass_NavigationPath):
    """Message class 'NavigationPath'."""

    __slots__ = [
        '_visitor_id',
        '_host_id',
        '_path',
    ]

    _fields_and_field_types = {
        'visitor_id': 'string',
        'host_id': 'string',
        'path': 'sequence<string>',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.UnboundedString()),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.visitor_id = kwargs.get('visitor_id', str())
        self.host_id = kwargs.get('host_id', str())
        self.path = kwargs.get('path', [])

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
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
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.visitor_id != other.visitor_id:
            return False
        if self.host_id != other.host_id:
            return False
        if self.path != other.path:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def visitor_id(self):
        """Message field 'visitor_id'."""
        return self._visitor_id

    @visitor_id.setter
    def visitor_id(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'visitor_id' field must be of type 'str'"
        self._visitor_id = value

    @builtins.property
    def host_id(self):
        """Message field 'host_id'."""
        return self._host_id

    @host_id.setter
    def host_id(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'host_id' field must be of type 'str'"
        self._host_id = value

    @builtins.property
    def path(self):
        """Message field 'path'."""
        return self._path

    @path.setter
    def path(self, value):
        if __debug__:
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 all(isinstance(v, str) for v in value) and
                 True), \
                "The 'path' field must be a set or sequence and each value of type 'str'"
        self._path = value
