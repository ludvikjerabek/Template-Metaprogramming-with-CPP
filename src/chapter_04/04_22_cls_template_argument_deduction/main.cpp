#include <iostream>

namespace std {
template<typename T>
pair(T&&, char const*) -> pair<T, std::string>;

template<typename T>
pair(char const*, T&&) -> pair<std::string, T>;

pair(char const*, char const*) -> pair<std::string, std::string>;
}

int main()
{
	// Page 159 with see above std template changes
	std::pair p1{1, "one"};       // std::pair<int, std::string>
	std::pair p2{"two", 2};       // std::pair<std::string, int>
	std::pair p3{"3", "three"};   // std::pair<std::string, std::string>
}

