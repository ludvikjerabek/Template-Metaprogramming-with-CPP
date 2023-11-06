#include <iostream>
#include <array>

template<typename... Ts>
constexpr auto get_type_sizes()
{
	return std::array<std::size_t, sizeof...(Ts)>{sizeof(Ts)...};
}

int main()
{
	auto sizes = get_type_sizes<short, int, long, long long>();
	for (auto const& s : sizes)
		std::cout << s << std::endl;
}

