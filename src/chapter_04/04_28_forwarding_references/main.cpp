#include <iostream>
#include <vector>

int main()
{
	// Page 168
	{
		using lrefint = int&;
		using rrefint = int&&;
		int x = 42;
		lrefint& r1 = x; // type of r1 is int&
		lrefint&& r2 = x; // type of r2 is int&
		rrefint& r3 = x; // type of r3 is int&
		rrefint&& r4 = 1; // type of r4 is int&&
	}

	// Page 169
	{
		int x = 42;
		auto&& rx = x;          // int&
		auto&& rc = 42;         // int&&
		//auto const&& rcx = x;   // error

		std::vector<int> v{42};
		auto&& rv = v[0];       // int&
	}
}

