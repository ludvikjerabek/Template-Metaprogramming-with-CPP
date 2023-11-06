#include <iostream>

// Page 56
template<typename T>
struct foo { };

template<typename T>
void func(foo<T>)
{
	std::cout << "primary template" << std::endl;
}

template<>
void func(foo<int>)
{
	std::cout << "int specialization" << std::endl;
}

// Page 57 - 58
template <typename T, typename U>
void func(T a, U b)
{
	std::cout << "primary template" << std::endl;
}
template <>
void func(int a, int b)
{
	std::cout << "int-int specialization" << std::endl;
}
template <>
void func(int a, double b)
{
	std::cout << "int-double specialization" << std::endl;
}

int main()
{
	// Page 56
	func(foo<int>{});
	func(foo<double>{});

	// Page 57 - 58
	func(1, 2);
	func(1, 2.0);
	func(1.0, 2.0);
}

