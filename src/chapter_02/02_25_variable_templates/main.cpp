#include <iostream>

constexpr double PI = 3.1415926535897932385L;

template<typename T>
T sphere_volume(T const r)
{
	return static_cast<T>(4*PI*r*r*r/3);
}

int main()
{
	float v1 = sphere_volume(42.0f);
	double v2 = sphere_volume(42.0);
	std::cout << " Float: " << v1 << std::endl;
	std::cout << "Double: " << v2 << std::endl;
}

