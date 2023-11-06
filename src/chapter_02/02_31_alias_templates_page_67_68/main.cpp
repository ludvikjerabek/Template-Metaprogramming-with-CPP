#include <iostream>
#include <vector>

int my_function(int a, char b)
{
	std::cout << "A: " << a << " B: " << b << std::endl;
	return 100;
}

template<typename T>
struct foo {
  using value_type = T;
};

int main()
{
	{
		typedef int index_t;
		typedef std::vector<std::pair<int, std::string>> NameValueList;
		typedef int (* fn_ptr)(int, char);

		index_t a = 100;
		NameValueList list;
		list.push_back(std::pair<int, std::string>({100, "Hello"}));
		fn_ptr f1 = my_function;
		f1(a, 'A');
	}

	{
		using index_t = int;
		using NameValueList = std::vector<std::pair<int, std::string>>;
		using fn_ptr = int(int, char);

		index_t a = 101;
		NameValueList list;
		list.push_back({100, "Hello"});
		fn_ptr* f1 = my_function;
		f1(a, 'B');
	}

	{
		foo<int>::value_type a = 102;
		my_function(a, 'C');
	}

}

