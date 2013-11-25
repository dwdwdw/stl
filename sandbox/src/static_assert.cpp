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

int
main()
{
  static_assert(std::is_same<int, int>::value, "not the same type");
  return 0;
}
