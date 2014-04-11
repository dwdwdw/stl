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
#include "type_traits.h"
using std::cout;
using std::endl;
using namespace sandbox;

int
main(int argc, char **argv)
{
  cout<<is_function<decltype(main)>::value<<endl;
  cout<<is_function<int>::value<<endl;
  return 0;
}

