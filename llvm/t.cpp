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
#include <type_traits>
#include <typeinfo>
#include <unistd.h>
#include <thread>
using namespace std;

//template <typename T>
class X
{
public:
  X() {cout<<"default"<<endl;};
  X(int i) {cout<<"i"<<endl;}
  X(const int &i, const int &j) {cout<<"const i, const j"<<endl;}
  X(int &&i, int &&j) {cout<<"&&i, &&j"<<endl;}
  explicit X(const X &x) {cout<<"copy"<<endl;}
  X(X &&x) {cout<<"move"<<endl;}
};

X getX() {
  cout<<"getX"<<endl;
  return X();
}

//template class X<int>;

template <typename It>
auto find3(It beg, It end) -> decltype(*beg)
{
  for ( ; beg != end && *beg != 3; ++beg ) {
  }
  return *beg;
}

//template <typename T>
//void foo(T &t) {
  //cout<<"cref"<<endl;
//}
template <typename T>
void foo(T &&t) {
  T tt;
  cout<<"rvalue"<<endl;
}

template <typename T>
T bar() { return T(); }

template <typename T>
struct rm_ref { typedef T type; };
template <typename T>
struct rm_ref<T&> { typedef T type; };
template <typename T>
struct rm_ref<T&&> { typedef T type; };

template <typename T>
using rm_ref_t = typename rm_ref<T>::type;

template <typename T>
class Y
{
public:
  template <typename U>
  Y(U&& u) :t_(std::forward<U>(u)) {
  }

private:
  T t_;
};

template <typename T, typename... A>
T* makeT(A&&... arg)
{
  return new T(std::forward<A>(arg)...);
}

std::function<int()> make_lambda(int init)
{
  return [init]() mutable { return init++; };
}

void ff(const X &x) {
  cout<<(long)&x<<endl;
}

int
main()
{
  vector<int> v = {1,2,3,4,5};
  //rm_ref_t<int> i;
  //rm_ref_t<int&> j;
  //rm_ref_t<int&&> k;

  int i, j;
  makeT<X>();
  makeT<X>(0, 1);
  makeT<X>(i, j);

  X x;
  cout<<(long)&x<<endl;
  (std::bind(ff, std::ref(x)))();
  //t1.join();
  //int i = 2;
  //foo(i);
  //foo(3);
  //foo(bar<int>());
  return 0;
}
