#include <iostream>
#include <numeric>

template<typename T>
struct is_floating_point;

template<>
struct is_floating_point<float> {
  constexpr static bool value = true;
};

template<typename T>
struct is_floating_point {
  constexpr static bool value = false;
};

int main()
{
	std::cout << is_floating_point<int>::value << std::endl;
	std::cout << is_floating_point<float>::value << std::endl;
}

