#include <iostream>
#include <numeric>

template<typename T>
struct foo {
  void f() { }
  void g() { int a = "42"; }
};

int main()
{
	foo<int> a;
	a.f();
	//a.g();
}

