#include <iostream>
#include <stdarg.h>

template<typename T>
T min(int count, ...)
{
	va_list args;
	va_start(args, count);

	T val = va_arg(args, T);
	for (int i = 1; i<count; i++) {
		T n = va_arg(args, T);
		if (n<val)
			val = n;
	}
	va_end(args);
	return val;
}

int main()
{
	std::cout << "min(42.0, 7.5) = " << min<double>(2, 42.0, 7.5) << std::endl;
	std::cout << "min(1, 5, 3, -4, 9) = " << min<int>(5, 1, 5, 3, -4, 9) << std::endl;
}

