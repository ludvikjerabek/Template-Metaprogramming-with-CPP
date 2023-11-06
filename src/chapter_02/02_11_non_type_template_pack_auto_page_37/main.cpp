#include <iostream>
#include <numeric>
#include <memory>

template<auto... x>
struct foo { };

int main()
{
	[[maybe_unused]] foo<42, 42.0, false, 'x'> f;
}

