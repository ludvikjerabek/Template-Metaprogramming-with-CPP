#include <utility>

template<typename T>
T const& func(T const& ref)
{
	return ref;
}

template<typename T>
decltype(auto) func_caller(T&& ref)
{
	return func(std::forward<T>(ref));
}

int main()
{
	int a = 42;
	decltype(func(a)) r1 = func(a);                 // int const&
	decltype(func_caller(a)) r2 = func_caller(a);   // int const&
}

