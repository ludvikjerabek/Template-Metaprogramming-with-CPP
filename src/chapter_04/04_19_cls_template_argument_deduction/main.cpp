#include <iostream>
#include <vector>

template<typename T>
struct wrapper {
  T data;
};

template<typename T>
constexpr wrapper<T> make_wrapper(T&& data)
{
	return wrapper{data};
}

template<typename T>
wrapper(T) -> wrapper<T>;

template<typename T, typename... Ts, typename Allocator = std::allocator<T>>
auto make_vector(T&& first, Ts&& ... args)
{
	return std::vector<std::decay_t<T>, Allocator>{
			std::forward<T>(first),
			std::forward<Ts>(args)...
	};
}

int main()
{
	std::pair<int, double> p1{42, 42.0};
	std::vector<int> v1{1, 2, 3, 4, 5};
	wrapper<int> w1{42};

	auto p2 = std::make_pair(42, 42.0);
	auto v2 = make_vector(1, 2, 3, 4, 5);
	auto w2 = make_wrapper(42);

	std::pair p3{42, 42.0};
	std::vector v3{1, 2, 3, 4, 5};
	wrapper w3{42};
}

