#include <iostream>
#include <tuple>

template<int... R>
constexpr int Sum = (... + R);

template<int... I>
constexpr auto indexes = std::make_index_sequence<5>();

int main()
{
	std::cout << Sum<1> << std::endl;
	std::cout << Sum<1, 2> << std::endl;
	std::cout << Sum<1, 2, 3, 4, 5> << std::endl;
}

