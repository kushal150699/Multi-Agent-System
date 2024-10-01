// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from campus_tour_interfaces:msg/NavigationPath.idl
// generated code does not contain a copyright notice

#ifndef CAMPUS_TOUR_INTERFACES__MSG__DETAIL__NAVIGATION_PATH__STRUCT_HPP_
#define CAMPUS_TOUR_INTERFACES__MSG__DETAIL__NAVIGATION_PATH__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__campus_tour_interfaces__msg__NavigationPath __attribute__((deprecated))
#else
# define DEPRECATED__campus_tour_interfaces__msg__NavigationPath __declspec(deprecated)
#endif

namespace campus_tour_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct NavigationPath_
{
  using Type = NavigationPath_<ContainerAllocator>;

  explicit NavigationPath_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->visitor_id = "";
      this->host_id = "";
    }
  }

  explicit NavigationPath_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : visitor_id(_alloc),
    host_id(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->visitor_id = "";
      this->host_id = "";
    }
  }

  // field types and members
  using _visitor_id_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _visitor_id_type visitor_id;
  using _host_id_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _host_id_type host_id;
  using _path_type =
    std::vector<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>>>;
  _path_type path;

  // setters for named parameter idiom
  Type & set__visitor_id(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->visitor_id = _arg;
    return *this;
  }
  Type & set__host_id(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->host_id = _arg;
    return *this;
  }
  Type & set__path(
    const std::vector<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>>> & _arg)
  {
    this->path = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    campus_tour_interfaces::msg::NavigationPath_<ContainerAllocator> *;
  using ConstRawPtr =
    const campus_tour_interfaces::msg::NavigationPath_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<campus_tour_interfaces::msg::NavigationPath_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<campus_tour_interfaces::msg::NavigationPath_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      campus_tour_interfaces::msg::NavigationPath_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<campus_tour_interfaces::msg::NavigationPath_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      campus_tour_interfaces::msg::NavigationPath_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<campus_tour_interfaces::msg::NavigationPath_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<campus_tour_interfaces::msg::NavigationPath_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<campus_tour_interfaces::msg::NavigationPath_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__campus_tour_interfaces__msg__NavigationPath
    std::shared_ptr<campus_tour_interfaces::msg::NavigationPath_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__campus_tour_interfaces__msg__NavigationPath
    std::shared_ptr<campus_tour_interfaces::msg::NavigationPath_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const NavigationPath_ & other) const
  {
    if (this->visitor_id != other.visitor_id) {
      return false;
    }
    if (this->host_id != other.host_id) {
      return false;
    }
    if (this->path != other.path) {
      return false;
    }
    return true;
  }
  bool operator!=(const NavigationPath_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct NavigationPath_

// alias to use template instance with default allocator
using NavigationPath =
  campus_tour_interfaces::msg::NavigationPath_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace campus_tour_interfaces

#endif  // CAMPUS_TOUR_INTERFACES__MSG__DETAIL__NAVIGATION_PATH__STRUCT_HPP_
