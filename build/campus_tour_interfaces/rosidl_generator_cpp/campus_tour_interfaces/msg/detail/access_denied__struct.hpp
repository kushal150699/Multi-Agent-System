// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from campus_tour_interfaces:msg/AccessDenied.idl
// generated code does not contain a copyright notice

#ifndef CAMPUS_TOUR_INTERFACES__MSG__DETAIL__ACCESS_DENIED__STRUCT_HPP_
#define CAMPUS_TOUR_INTERFACES__MSG__DETAIL__ACCESS_DENIED__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__campus_tour_interfaces__msg__AccessDenied __attribute__((deprecated))
#else
# define DEPRECATED__campus_tour_interfaces__msg__AccessDenied __declspec(deprecated)
#endif

namespace campus_tour_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct AccessDenied_
{
  using Type = AccessDenied_<ContainerAllocator>;

  explicit AccessDenied_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->visitor_id = "";
      this->reason = "";
    }
  }

  explicit AccessDenied_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : visitor_id(_alloc),
    reason(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->visitor_id = "";
      this->reason = "";
    }
  }

  // field types and members
  using _visitor_id_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _visitor_id_type visitor_id;
  using _reason_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _reason_type reason;

  // setters for named parameter idiom
  Type & set__visitor_id(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->visitor_id = _arg;
    return *this;
  }
  Type & set__reason(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->reason = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    campus_tour_interfaces::msg::AccessDenied_<ContainerAllocator> *;
  using ConstRawPtr =
    const campus_tour_interfaces::msg::AccessDenied_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<campus_tour_interfaces::msg::AccessDenied_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<campus_tour_interfaces::msg::AccessDenied_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      campus_tour_interfaces::msg::AccessDenied_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<campus_tour_interfaces::msg::AccessDenied_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      campus_tour_interfaces::msg::AccessDenied_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<campus_tour_interfaces::msg::AccessDenied_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<campus_tour_interfaces::msg::AccessDenied_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<campus_tour_interfaces::msg::AccessDenied_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__campus_tour_interfaces__msg__AccessDenied
    std::shared_ptr<campus_tour_interfaces::msg::AccessDenied_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__campus_tour_interfaces__msg__AccessDenied
    std::shared_ptr<campus_tour_interfaces::msg::AccessDenied_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const AccessDenied_ & other) const
  {
    if (this->visitor_id != other.visitor_id) {
      return false;
    }
    if (this->reason != other.reason) {
      return false;
    }
    return true;
  }
  bool operator!=(const AccessDenied_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct AccessDenied_

// alias to use template instance with default allocator
using AccessDenied =
  campus_tour_interfaces::msg::AccessDenied_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace campus_tour_interfaces

#endif  // CAMPUS_TOUR_INTERFACES__MSG__DETAIL__ACCESS_DENIED__STRUCT_HPP_
