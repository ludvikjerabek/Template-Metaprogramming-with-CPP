#include <iostream>

template<typename T>
T sum(T a)
{
	return a;
}

template<typename T, typename... Args>
T sum(T a, Args... args)
{
	return a+sum(args...);
}

int main()
{
	std::cout << sum(1, 2, 3, 4, 5) << std::endl;
	std::cout << sum(1) << std::endl;
}

