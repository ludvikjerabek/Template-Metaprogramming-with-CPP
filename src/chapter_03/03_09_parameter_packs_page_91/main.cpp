#include <iostream>
#include <array>

template<typename T1, typename T2, typename T3, typename T4>
constexpr auto get_type_sizes()
{
	return std::array<std::size_t, 4>{
			sizeof(T1), sizeof(T2), sizeof(T3), sizeof(T4)
	};
}

int main()
{
	auto result = get_type_sizes<short, int, long, long double>();
	for (auto a : result)
		std::cout << a << std::endl;

}

