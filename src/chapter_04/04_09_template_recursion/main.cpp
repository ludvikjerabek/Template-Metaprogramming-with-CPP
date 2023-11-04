#include <iostream>

template<unsigned int N>
struct factorial {
  static constexpr unsigned int value = N*factorial<N-1>::value;
};

template<>
struct factorial<0> {
  static constexpr unsigned int value = 1;
};

int main()
{
	std::cout << factorial<0>::value << std::endl;
	std::cout << factorial<1>::value << std::endl;
	std::cout << factorial<2>::value << std::endl;
	std::cout << factorial<3>::value << std::endl;
	std::cout << factorial<4>::value << std::endl;
	std::cout << factorial<5>::value << std::endl;
	std::cout << factorial<12>::value << std::endl;
}

