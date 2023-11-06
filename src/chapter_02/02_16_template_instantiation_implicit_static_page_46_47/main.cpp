#include <iostream>
#include <numeric>

// Struct control, code was never used page 46
template <typename T>
struct control
{
};
template <typename T>
struct button : public control<T>
{
};
void show(button<int>* ptr)
{
	control<int>* c = ptr;
}

// This is on page 46-47
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

