#include <iostream>
#include <numeric>

template<typename T, typename U = double>
struct foo;

// This order must be maintained, if moved above the previous it will fail.
template<typename T = int, typename U>
struct foo;

template<typename T, typename U>
struct foo {
  T a;
  U b;
};

int main()
{
	foo f1{42, 42.1};
	std::cout << f1.a << ' '
			  << f1.b << '\n';
}

