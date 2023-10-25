#include <iostream>
#include <array>
#include <numeric>

template<typename T>
T add(T const a, T const b)
{
	return a+b;
}

class foo {
	int value;
public:
	explicit foo(int const i)
			:value(i)
	{
	}

	explicit operator int() const { return value; }
};

foo operator+(foo const a, foo const b)
{
	return foo((int)a+(int)b);
}

template<typename Input, typename Predicate>
int count_if(Input start, Input end, Predicate p)
{
	int total = 0;
	for (Input i = start; i!=end; i++) {
		if (p(*i))
			total++;
	}
	return total;
}


int main()
{
		auto a1 = add(42, 21);
		auto a2 = add<int>(42, 21);
		auto a3 = add<>(42, 21);

		auto b = add<short>(42, 21);

		//auto d1 = add(41.0, 21); // error
		auto d2 = add<double>(41.0, 21);

		auto f = add(foo(42), foo(41));

		int arr[]{1, 1, 2, 3, 5, 8, 11};
		int odds = count_if(std::begin(arr), std::end(arr),
				[](int const n) { return n%2==1; });
		std::cout << odds << '\n';
}

