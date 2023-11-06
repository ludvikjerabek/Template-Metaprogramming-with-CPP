#include <iostream>

template<typename T>
struct wrapper {
  T data;
};

int main()
{
	// Page 173
	[[maybe_unused]] decltype(wrapper<double>::data) e1;  // double

	int a = 42;
	// It appears that the reference must be initialized in GCC / Clang
	[[maybe_unused]] decltype(wrapper<char>::data, a) e2 = a; // int&

	std::cout << e2++ << " " << a << std::endl;
}

