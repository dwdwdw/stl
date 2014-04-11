#ifndef TYPE_TRAITS_H
#define TYPE_TRAIT

namespace sandbox
{

template <typename T, T v>
struct integral_constant
{
  typedef T value_type;
  const static T value = v;
};

typedef integral_constant<bool, true> true_type;
typedef integral_constant<bool, false> false_type;

template <typename T>
struct is_function : false_type {};
template <typename RT, typename ... PT>
struct is_function<RT(PT...)> : true_type {};

}

#endif
