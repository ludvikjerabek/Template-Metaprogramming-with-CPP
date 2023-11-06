#include <iostream>

int min(int a, int b)
{
	return a<b ? a : b;
}

int min(int a, int b, int c)
{
	return min(a, min(b, c));
}

int min(int a, int b, int c, int d)
{
	return min(a, min(b, min(c, d)));
}

int min(int a, int b, int c, int d, int e)
{
	return min(a, min(b, min(c, min(d, e))));
}

int main()
{
	std::cout << "min(42.0, 7.5) = " << min(42, 7) << std::endl;
	std::cout << "min(1, 5, 3, -4, 9) = " << min(1, 5, 3, -4, 9) << std::endl;
}

