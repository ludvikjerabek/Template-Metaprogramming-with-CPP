#include <iostream>

template<unsigned int N>
inline constexpr unsigned int factorial = N*factorial<N-1>;

template<>
inline constexpr unsigned int factorial<0> = 1;

int main()
{
	std::cout << factorial<0> << std::endl;
	std::cout << factorial<1> << std::endl;
	std::cout << factorial<2> << std::endl;
	std::cout << factorial<3> << std::endl;
	std::cout << factorial<4> << std::endl;
	std::cout << factorial<5> << std::endl;
	std::cout << factorial<12> << std::endl;
}

