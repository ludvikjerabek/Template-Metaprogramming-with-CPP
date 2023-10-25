#include <iostream>
#include <sstream>

template<typename T>
T max(T const a, T const b)
{
	return a>b ? a : b;
}

int main()
{
	max(1, 2);        // OK, compares ints
	max(1.0, 2.0);    // OK, compares doubles
	max<int>(1, 2);
	max<double>(1.0, 2.0);
}