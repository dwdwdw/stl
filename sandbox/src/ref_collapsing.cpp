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

template <typename T>
void deduce(T &&t)
{
  cout<<"T:\t";
  cout<<"rvalue reference? "<<std::is_rvalue_reference<T>::value<<"\t";
  cout<<"lvalue reference? "<<std::is_reference<T>::value
                              - std::is_rvalue_reference<T>::value;
  cout<<endl;

  cout<<"t:\t";
  cout<<"rvalue reference? "<<std::is_rvalue_reference<decltype(t)>::value<<"\t";
  cout<<"lvalue reference? "<<std::is_reference<decltype(t)>::value
                              - std::is_rvalue_reference<decltype(t)>::value;
  cout<<endl;
}

template <typename T>
void inter(T &&t)
{
  deduce(std::forward<T>(t));
}

int
main()
{
  int x;
  inter(x);
  inter(10);
  return 0;
}
