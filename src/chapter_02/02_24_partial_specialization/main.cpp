#include <iostream>
#include <array>
#include <cstring>

template<size_t S>
std::ostream& pretty_print(std::ostream& os, std::array<char, S> const& arr)
{
	os << '[';
	for (auto e : arr)
		os << e;
	os << ']' << std::endl;

	return os;
}

int main()
{
	// Specialized version
	std::array<char, 8> str{};
	std::strcpy(str.data(), "template");
	pretty_print(std::cout, str);

	// Should fail
	// std::array<int, 8> arr{1, 1, 2, 3, 5, 8, 13, 21};
	// pretty_print(std::cout, arr);
}

