#include <iostream>
#include <sstream>

template<typename T>
T max(T const a, T const b)
{
	return a>b ? a : b;
}

int main()
{
	std::cout << max(1, 2) << std::endl;
	std::cout << max(1.1, 2.2) << std::endl;
	std::cout << max<int>(1, 2) << std::endl;
	std::cout << max<double>(1.1, 2.2) << std::endl;
}