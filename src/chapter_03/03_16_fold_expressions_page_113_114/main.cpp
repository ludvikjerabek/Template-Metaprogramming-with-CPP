#include <iostream>
#include <vector>

template<typename... T>
int suml(T... args)
{
	return (... + args);
}

template<typename... T>
int sumr(T... args)
{
	return (args + ...);
}

template<typename... T>
void printl(T... args)
{
	(..., (std::cout << args)) << std::endl;
}

template<typename... T>
void printr(T... args)
{
	((std::cout << args), ...) << std::endl;
}

template<typename... T>
void print(T... args)
{
	(std::cout << ... << args) << std::endl;
}

template<typename T, typename... Args>
void push_back_many(std::vector<T>& v, Args&& ... args)
{
	(v.push_back(args), ...);
}

int main()
{
	printl('d', 'o', 'g');  // dog
	printr('d', 'o', 'g');  // dog
	print('d', 'o', 'g');  // dog

	std::vector<int> v;
	push_back_many(v, 1, 2, 3, 4, 5);
	for (auto a : v)
		std::cout << a << std::endl;
}

