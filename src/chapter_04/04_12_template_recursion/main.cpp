#include <iostream>

constexpr unsigned int factorial(unsigned int const n)
{
	return n>1 ? n*factorial(n-1) : 1;
}

template<typename T>
struct wrapper { };

template<int N>
struct manyfold_wrapper {
  using value_type = wrapper<typename manyfold_wrapper<N-1>::value_type>;
};

template<>
struct manyfold_wrapper<0> {
  using value_type = unsigned int;
};

int main()
{
	std::cout << factorial(0) << std::endl;
	std::cout << factorial(1) << std::endl;
	std::cout << factorial(2) << std::endl;
	std::cout << factorial(3) << std::endl;
	std::cout << factorial(4) << std::endl;
	std::cout << factorial(5) << std::endl;

	std::cout << typeid(manyfold_wrapper<0>::value_type).name() << std::endl;
	std::cout << typeid(manyfold_wrapper<1>::value_type).name() << std::endl;
	std::cout << typeid(manyfold_wrapper<2>::value_type).name() << std::endl;
	std::cout << typeid(manyfold_wrapper<3>::value_type).name() << std::endl;
}

