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

void h(foo& v)
{
	g(std::forward<foo&>(v));
}

void h(foo&& v)
{
	g(std::forward<foo&&>(v));
}

int main()
{
	// Page 165
	foo x{42};
	h(x);          // g(foo&)
	h(foo{42});  // g(foo&&)
}

