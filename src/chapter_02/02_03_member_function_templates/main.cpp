#include <iostream>
#include <numeric>

template<typename T>
class composition_t {
public:
	T add(T const a, T const b)
	{
		return a+b;
	}
};

class composition {
public:
	template<typename T>
	T add(T const a, T const b)
	{
		return a+b;
	}
};

int main()
{
	composition_t<int> ct;
	std::cout << ct.add(41, 21) << std::endl;

	composition c;
	std::cout << c.add<int>(41, 21) << std::endl;
}

