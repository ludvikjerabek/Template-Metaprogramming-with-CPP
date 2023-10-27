#include <iostream>
#include <numeric>
#include "wrapper.h"

template<typename T>
struct foo {
  static T data;
};

template<typename T> T foo<T>::data = 0;

int main()
{
	wrapper<int> a{0};

	std::cout << a.data << std::endl;
	f();
	g();
}

