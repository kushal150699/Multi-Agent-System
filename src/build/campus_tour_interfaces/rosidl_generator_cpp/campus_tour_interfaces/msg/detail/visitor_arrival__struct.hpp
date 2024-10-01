// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from campus_tour_interfaces:msg/VisitorArrival.idl
// generated code does not contain a copyright notice

#ifndef CAMPUS_TOUR_INTERFACES__MSG__DETAIL__VISITOR_ARRIVAL__STRUCT_HPP_
#define CAMPUS_TOUR_INTERFACES__MSG__DETAIL__VISITOR_ARRIVAL__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__campus_tour_interfaces__msg__VisitorArrival __attribute__((deprecated))
#else
# define DEPRECATED__campus_tour_interfaces__msg__VisitorArrival __declspec(deprecated)
#endif

namespace campus_tour_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct VisitorArrival_
{
  using Type = VisitorArrival_<ContainerAllocator>;

  explicit VisitorArrival_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->building_id = "";
      this->host_id = "";
      this->visitor_id = "";
      this->ci_id = "";
      this->visitor_position = "";
    }
  }

  explicit VisitorArrival_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : building_id(_alloc),
    host_id(_alloc),
    visitor_id(_alloc),
    ci_id(_alloc),
    visitor_position(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->building_id = "";
      this->host_id = "";
      this->visitor_id = "";
      this->ci_id = "";
      this->visitor_position = "";
    }
  }

  // field types and members
  using _building_id_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _building_id_type building_id;
  using _host_id_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _host_id_type host_id;
  using _visitor_id_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _visitor_id_type visitor_id;
  using _ci_id_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _ci_id_type ci_id;
  using _visitor_position_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _visitor_position_type visitor_position;

  // setters for named parameter idiom
  Type & set__building_id(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->building_id = _arg;
    return *this;
  }
  Type & set__host_id(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->host_id = _arg;
    return *this;
  }
  Type & set__visitor_id(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->visitor_id = _arg;
    return *this;
  }
  Type & set__ci_id(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->ci_id = _arg;
    return *this;
  }
  Type & set__visitor_position(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->visitor_position = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    campus_tour_interfaces::msg::VisitorArrival_<ContainerAllocator> *;
  using ConstRawPtr =
    const campus_tour_interfaces::msg::VisitorArrival_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<campus_tour_interfaces::msg::VisitorArrival_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<campus_tour_interfaces::msg::VisitorArrival_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      campus_tour_interfaces::msg::VisitorArrival_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<campus_tour_interfaces::msg::VisitorArrival_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      campus_tour_interfaces::msg::VisitorArrival_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<campus_tour_interfaces::msg::VisitorArrival_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<campus_tour_interfaces::msg::VisitorArrival_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<campus_tour_interfaces::msg::VisitorArrival_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__campus_tour_interfaces__msg__VisitorArrival
    std::shared_ptr<campus_tour_interfaces::msg::VisitorArrival_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__campus_tour_interfaces__msg__VisitorArrival
    std::shared_ptr<campus_tour_interfaces::msg::VisitorArrival_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const VisitorArrival_ & other) const
  {
    if (this->building_id != other.building_id) {
      return false;
    }
    if (this->host_id != other.host_id) {
      return false;
    }
    if (this->visitor_id != other.visitor_id) {
      return false;
    }
    if (this->ci_id != other.ci_id) {
      return false;
    }
    if (this->visitor_position != other.visitor_position) {
      return false;
    }
    return true;
  }
  bool operator!=(const VisitorArrival_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct VisitorArrival_

// alias to use template instance with default allocator
using VisitorArrival =
  campus_tour_interfaces::msg::VisitorArrival_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace campus_tour_interfaces

#endif  // CAMPUS_TOUR_INTERFACES__MSG__DETAIL__VISITOR_ARRIVAL__STRUCT_HPP_
