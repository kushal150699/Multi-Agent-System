// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from campus_tour_interfaces:msg/OutOfService.idl
// generated code does not contain a copyright notice

#ifndef CAMPUS_TOUR_INTERFACES__MSG__DETAIL__OUT_OF_SERVICE__STRUCT_HPP_
#define CAMPUS_TOUR_INTERFACES__MSG__DETAIL__OUT_OF_SERVICE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__campus_tour_interfaces__msg__OutOfService __attribute__((deprecated))
#else
# define DEPRECATED__campus_tour_interfaces__msg__OutOfService __declspec(deprecated)
#endif

namespace campus_tour_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct OutOfService_
{
  using Type = OutOfService_<ContainerAllocator>;

  explicit OutOfService_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->bi_id = "";
      this->duration = 0l;
    }
  }

  explicit OutOfService_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : bi_id(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->bi_id = "";
      this->duration = 0l;
    }
  }

  // field types and members
  using _bi_id_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _bi_id_type bi_id;
  using _duration_type =
    int32_t;
  _duration_type duration;

  // setters for named parameter idiom
  Type & set__bi_id(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->bi_id = _arg;
    return *this;
  }
  Type & set__duration(
    const int32_t & _arg)
  {
    this->duration = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    campus_tour_interfaces::msg::OutOfService_<ContainerAllocator> *;
  using ConstRawPtr =
    const campus_tour_interfaces::msg::OutOfService_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<campus_tour_interfaces::msg::OutOfService_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<campus_tour_interfaces::msg::OutOfService_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      campus_tour_interfaces::msg::OutOfService_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<campus_tour_interfaces::msg::OutOfService_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      campus_tour_interfaces::msg::OutOfService_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<campus_tour_interfaces::msg::OutOfService_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<campus_tour_interfaces::msg::OutOfService_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<campus_tour_interfaces::msg::OutOfService_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__campus_tour_interfaces__msg__OutOfService
    std::shared_ptr<campus_tour_interfaces::msg::OutOfService_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__campus_tour_interfaces__msg__OutOfService
    std::shared_ptr<campus_tour_interfaces::msg::OutOfService_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const OutOfService_ & other) const
  {
    if (this->bi_id != other.bi_id) {
      return false;
    }
    if (this->duration != other.duration) {
      return false;
    }
    return true;
  }
  bool operator!=(const OutOfService_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct OutOfService_

// alias to use template instance with default allocator
using OutOfService =
  campus_tour_interfaces::msg::OutOfService_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace campus_tour_interfaces

#endif  // CAMPUS_TOUR_INTERFACES__MSG__DETAIL__OUT_OF_SERVICE__STRUCT_HPP_
