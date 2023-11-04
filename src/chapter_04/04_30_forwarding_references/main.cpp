#include <iostream>
#include <vector>

struct foo {
  int data;
};

void g(foo& v)
{
	std::cout << "g(foo&)" << std::endl;
}

void g(foo&& v)
{
	std::cout << "g(foo&&)" << std::endl;
}

template<typename T>
void h(T&& v)
{
	g(std::forward<T>(v));
}

int main()
{
	// Page 170
	foo x{42};
	h(x);          // g(foo&)
	h(foo{42});  // g(foo&&)
}

