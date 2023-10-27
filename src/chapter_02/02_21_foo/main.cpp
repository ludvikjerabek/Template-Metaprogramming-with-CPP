#include <iostream>

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

int main()
{
	func(foo<int>{});
	func(foo<double>{});
}

