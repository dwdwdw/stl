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
#include <typeinfo>
#include <type_traits>
#include <functional>
#include <tuple>
using namespace std;

template <typename T, typename... Args>
class X
{
public:
  X(Args&&... args) : tp_(args...) {}
  std::tuple<Args...> tp_;
};

template <typename T>
void print(T t)
{
  cout<<t<<endl;
}

template <typename T, typename... Args>
void print(T t, Args&&... args)
{
  cout<<t<<",";
  print(args...);
}

int f(int i) {return i;}
int (*p)(int) = f;


int
main()
{
  cout<<std::is_function<decltype(f)>::value<<endl;
  cout<<std::is_function<std::decay<decltype(f)>::type>::value<<endl;
  cout<<std::is_function<std::decay<decltype(p)>::type>::value<<endl;
  decltype(f) ff;
  cout<<typeid(f).name()<<endl;

  return 0;
}
