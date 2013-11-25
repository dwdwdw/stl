/*=============================================================*
 * Author:      Fenglin Hou.
 * Email:       Gdutor@gmail.com.
 * Site:        http://www.dutor.net
 * Created:     @
 * Modified:    @Feb 20 2011
 *=============================================================*/
#include <iostream>
#include <string>
#include <vector>
#include <typeinfo>
#include <type_traits>
#include <functional>
#include <tuple>
using namespace std;

template <typename T, typename... Args>
class X
{
public:
  X(T &&t, Args&&... args) : tp_(t, args...) {}
  std::tuple<T, Args...> tp_;
};

void print()
{
  cout<<endl;
}

template <typename T, typename... Args>
void print(T t, Args&&... args)
{
  cout<<t<<" ";
  print(args...);
}

template <typename Tuple, size_t N>
struct TuplePrinter {
  static void print(const Tuple &tp)
  {
    TuplePrinter<Tuple, N - 1>::print(tp);
    cout<<get<N-1>(tp);
  }
};

template <typename Tuple>
struct TuplePrinter<Tuple, 1> {
  static void print(const Tuple &tp)
  {
    cout<<get<0>(tp);
  }
};

template <typename ... Args>
void print_tuple(const std::tuple<Args...> &tp)
{
  TuplePrinter<decltype(tp), sizeof...(Args)>::print(tp);
  cout<<endl;
}

int
main()
{
  std::string *p = (string*) new char[sizeof(string)];
  new(p)string(10, '*');
  cout<<*p<<endl;
  cout<<"=============== "<<"variadic function template"<< " =============="<<endl;
  print("Hello,", 123, ",", "World!");
  cout<<"=============== "<<"variadic template class"<< " =============="<<endl;
  X<string, int, string, string> x("Hello,", 123, ",", "World!");
  print_tuple(x.tp_);
  return 0;
}
