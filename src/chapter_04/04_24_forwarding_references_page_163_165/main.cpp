#include <iostream>
#include <vector>

struct foo {
  int data;
};

void f(foo& v)
{
	std::cout << "f(foo&)" << std::endl;
}

void g(foo& v)
{
	std::cout << "g(foo&)" << std::endl;
}

void g(foo&& v)
{
	std::cout << "g(foo&&)" << std::endl;
}

void h(foo&& v)
{
	std::cout << "h(foo&&)" << std::endl;
}

int main()
{
	// Page 163
	{
		foo x = {42};   // x is l-value
		foo& rx = x;      // rx is l-value

		f(x);             // f(foo&)
		f(rx);            // f(foo&)
		//f(foo{ 42 });     // error, a non-const reference may only be bound to an lvalue
	}

	// Page 164
	{
		foo x = {42};   // x is l-value
		foo& rx = x;      // rx is l-value

		g(x);             // g(foo&)
		g(rx);            // g(foo&)
		g(foo{42});     // g(foo&&)
	}

	// Page 164
	{
		foo x = {42};   // x is l-value
		foo& rx = x;      // rx is l-value

		//h(x);             // error, cannot bind an lvalue to an rvalue reference
		//h(rx);         // error
		h(foo{42});  // h(foo&&)
		h(std::move(x));  // h(foo&7)
	}

	// Page 165
	{
		foo x = {42};   // x is l-value
		foo& rx = x;      // rx is l-value

		g(x);             // g(foo&)
		g(rx);            // g(foo&)
		g(foo{42});     // g(foo&&)
	}

	// Page 165
	{
		foo x = {42};   // x is l-value
		foo& rx = x;      // rx is l-value

		g(x);             // g(foo&)
		g(rx);            // g(foo&)
		g(foo{42});     // g(foo&&)
	}
}

