#include <iostream>
#include <array>
#include <cstring>

template<typename T, size_t S>
std::ostream& pretty_print(std::ostream& os, std::array<T, S> const& arr)
{
	os << '[';
	if (S>0) {
		for (size_t i = 0; i<S-1; ++i)
			os << arr[i] << ',';
		os << arr[S-1];
	}
	os << ']' << std::endl;

	return os;
}

int main()
{
	std::array<int, 8> arr{1, 1, 2, 3, 5, 8, 13, 21};
	pretty_print(std::cout, arr);

	std::array<char, 8> str{};
	std::strcpy(str.data(), "template");
	pretty_print(std::cout, str);
}

