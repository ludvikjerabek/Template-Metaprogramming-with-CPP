#include <iostream>

struct wrapper {
	wrapper(int const v)
			:value(v)
	{
	}
private:
	int value;

	template<typename T>
	friend void print(wrapper const&);

	template<typename T>
	friend
	struct printer;
};

template<typename T>
void print(wrapper const& w)
{
	std::cout << w.value << std::endl;
}

template<typename T>
struct printer {
  void operator()(wrapper const& w)
  {
	  std::cout << w.value << std::endl;
  }
};

int main()
{
	wrapper w{42};
	print<int>(w);
	print<char>(w);
	printer<int>()(w);
	printer<double>()(w);
}

