#include <iostream>
#include <numeric>

template<typename T>
struct foo {
  static T data;
};

template<typename T> T foo<T>::data = 0;

int main()
{
	foo<int> a;
	foo<double> b;
	foo<double> c;

	std::cout << a.data << std::endl; // 0
	std::cout << b.data << std::endl; // 0
	std::cout << c.data << std::endl; // 0

	b.data = 42;
	std::cout << b.data << std::endl; // 42
	std::cout << c.data << std::endl; // 42
}

