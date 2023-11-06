#include <iostream>
#include <numeric>

template<typename T>
struct is_floating_point {
  constexpr static bool value = false;
};

template<>
struct is_floating_point<float> {
  constexpr static bool value = true;
};

template<>
struct is_floating_point<double> {
  constexpr static bool value = true;
};

template<>
struct is_floating_point<long double> {
  constexpr static bool value = true;
};

template<typename T>
inline constexpr bool is_floating_point_v = is_floating_point<T>::value;

int main()
{
	{
		std::cout << is_floating_point<int>::value << std::endl;
		std::cout << is_floating_point<float>::value << std::endl;
		std::cout << is_floating_point<double>::value << std::endl;
		std::cout << is_floating_point<long double>::value << std::endl;
		std::cout << is_floating_point<std::string>::value << std::endl;
	}
	// Ease of use since :: is a pain
	{
		std::cout << is_floating_point_v<int> << std::endl;
		std::cout << is_floating_point_v<float> << std::endl;
		std::cout << is_floating_point_v<double> << std::endl;
		std::cout << is_floating_point_v<long double> << std::endl;
		std::cout << is_floating_point_v<std::string> << std::endl;
	}
}

