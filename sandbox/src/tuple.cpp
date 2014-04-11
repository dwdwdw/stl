/*=============================================================*
 * Author:      Fenglin Hou.
 * Email:       xdutor@gmail.com.
 * Site:        http://www.dutor.net
 * Created:     @
 * Modified:    @Feb 20 2011
 *=============================================================*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;


template <typename... Rest> struct Tuple;
template <> struct Tuple<> {};

template <typename First, typename ... Rest>
struct Tuple<First, Rest...> : public Tuple<Rest...>
{
  Tuple() : value() {}
  Tuple(First &&first, Rest&&... rest)
    : value(std::forward<First>(first)),
      Tuple<Rest...>(std::forward<Rest>(rest)...)
  {
  }
  First value;
};

template <size_t N, typename TP> struct Tuple_Element;

template <typename T, typename ... Rest>
struct Tuple_Element<0, Tuple<T, Rest...>>
{
  typedef T type;
  typedef Tuple<T, Rest...> TPType;
};

template <size_t N, typename T, typename ... Rest>
struct Tuple_Element<N, Tuple<T, Rest...>>
: public Tuple_Element<N - 1, Tuple<Rest...>>
{
};

template <size_t N, typename ... Rest>
typename Tuple_Element<N, Tuple<Rest...>>::type&
get(Tuple<Rest...> &tp)
{
  typedef typename Tuple_Element<N, Tuple<Rest...>>::TPType type;
  return ((type&)tp).value;
}


int
main()
{
  Tuple<int, string, double> tp(3, "2", 1.1);
  cout<<get<0>(tp)<<endl;
  cout<<get<1>(tp)<<endl;
  cout<<get<2>(tp)<<endl;
  return 0;
}
