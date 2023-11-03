#include <iostream>

template<typename... Ts, typename... Us>
constexpr auto multipacks(Ts... args1, Us... args2)
{
	std::cout << sizeof...(args1) << ','
			  << sizeof...(args2) << std::endl;
}

int main()
{
	multipacks<int>(1, 2, 3, 4, 5, 6);                    // 1,5
	multipacks<int, int, int>(1, 2, 3, 4, 5, 6);          // 3,3
	multipacks<int, int, int, int>(1, 2, 3, 4, 5, 6);     // 4,2
	multipacks<int, int, int, int, int, int>(1, 2, 3, 4, 5, 6); // 6,0

	multipacks<int, int>(1, 2, 4.0, 5.0, 6.0);            // 2,3
	multipacks<int, int, int>(1, 2, 3, 4.0, 5.0, 6.0);    // 3,3
}

