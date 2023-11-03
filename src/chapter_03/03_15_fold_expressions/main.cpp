#include <iostream>

template<typename... T>
int sum(T... args)
{
	return (... + args);
}

template<typename... T>
int sum_from_zero(T... args)
{
	return (0 + ... + args);
}

int main()
{
	//std::cout << sum() << std::endl; // Error
	std::cout << sum(1) << std::endl;
	std::cout << sum(1, 2) << std::endl;
	std::cout << sum(1, 2, 3, 4, 5) << std::endl;

	std::cout << sum_from_zero() << std::endl;
	std::cout << sum_from_zero(1, 2, 3) << std::endl;
}

