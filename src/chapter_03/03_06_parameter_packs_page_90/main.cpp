#include <iostream>

template<typename T, typename... Args>
T sum(T a, Args... args)
{
	if constexpr (sizeof...(args)==0)
		return a;
	else
		return a+sum(args...);
}

int main()
{
	std::cout << sum(1, 2, 3, 4, 5) << std::endl;
	std::cout << sum(1) << std::endl;
}

