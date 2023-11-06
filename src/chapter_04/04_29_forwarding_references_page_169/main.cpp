#include <iostream>

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
void h(T& v)
{
	g(v);
}

template<typename T>
void h(T&& v)
{
	g(v);
}

int main()
{
	// Page 169
	foo x{42};
	h(x);          // g(foo&)
	h(foo{42});  // g(foo&)
}

