#include <iostream>
#include <numeric>
#include <memory>

template<auto x>
struct foo { };

int main()
{
	[[maybe_unused]] foo<42> f1;    // foo<int>
	[[maybe_unused]] foo<42.0> f2;  // foo<double>
}

