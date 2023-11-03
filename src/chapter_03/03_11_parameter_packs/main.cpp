#include <iostream>

template<typename... Ts, typename... Us>
constexpr auto multipacks(Ts... args1, Us... args2)
{
	static_assert(
			sizeof...(args1)==sizeof...(args2),
			"Packs must be of equal sizes.");
}

int main()
{
	//multipacks<int>(1, 2, 3, 4, 5, 6);                    // error
	multipacks<int, int, int>(1, 2, 3, 4, 5, 6);          // OK
	//multipacks<int, int, int, int>(1, 2, 3, 4, 5, 6);     // error
	//multipacks<int, int, int, int, int, int>(1, 2, 3, 4, 5, 6); // error

	//multipacks<int, int>(1, 2, 4.0, 5.0, 6.0);            // error
	multipacks<int, int, int>(1, 2, 3, 4.0, 5.0, 6.0);    // OK
}

