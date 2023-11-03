#include <iostream>

template<typename T>
T min(T a, T b)
{
#if defined(__clang__) || defined(__GNUC__) || defined(__GNUG__)
	std::cout << __PRETTY_FUNCTION__ << "\n";
#elif defined(_MSC_VER)
	std::cout << __FUNCSIG__ << "\n";
#endif
	return a<b ? a : b;
}

template<typename T, typename... Args>
T min(T a, Args... args)
{
#if defined(__clang__) || defined(__GNUC__) || defined(__GNUG__)
	std::cout << __PRETTY_FUNCTION__ << "\n";
#elif defined(_MSC_VER)
	std::cout << __FUNCSIG__ << "\n";
#endif
	return min(a, min(args...));
}
int main()
{
	std::cout << "min(42.0, 7.5) = " << min(42, 7) << std::endl;
	std::cout << "min(1, 5, 3, -4, 9) = " << min(1, 5, 3, -4, 9) << std::endl;
}

