#include <iostream>

struct math_constants {
  template<class T>
  static const T PI;
};

template<class T>
const T math_constants::PI = T(3.1415926535897932385L);

template<typename T>
T sphere_volume(T const r)
{
	return 4*math_constants::PI<T>*r*r*r/3;
}

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
	std::cout << is_floating_point<float>::value << std::endl;
	std::cout << is_floating_point_v<float> << std::endl;

	std::cout << is_floating_point<double>::value << std::endl;
	std::cout << is_floating_point_v<double> << std::endl;

	std::cout << is_floating_point<long double>::value << std::endl;
	std::cout << is_floating_point_v<long double> << std::endl;

	std::cout << is_floating_point<int>::value << std::endl;
	std::cout << is_floating_point_v<int> << std::endl;

	std::cout << is_floating_point<char>::value << std::endl;
	std::cout << is_floating_point_v<char> << std::endl;
}

