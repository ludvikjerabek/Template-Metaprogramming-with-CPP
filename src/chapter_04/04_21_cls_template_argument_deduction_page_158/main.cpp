#include <iostream>

int main()
{
	// Page 158
	std::pair p1{1, "one"};       // std::pair<int, const char*>
	std::pair p2{"two", 2};       // std::pair<const char*, int>
	std::pair p3{"3", "three"};   // std::pair<const char*, const char*>
}

