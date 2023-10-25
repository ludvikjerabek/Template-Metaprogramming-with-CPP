#include <iostream>
#include <numeric>

template<typename T>
class wrapper {
public:
	explicit wrapper(T const v)
			:value(v)
	{
	}
	[[nodiscard]] T const& get() const { return value; }
private:
	T value;
};

template <typename T>
void use_wrapper(wrapper<T>* ptr)
{
	std::cout << ptr->get() << '\n';
}

int main()
{
	wrapper<int> a(42); // wraps an int
	wrapper<float> b(4.2); // wraps an int
	wrapper<char> c('A'); // wraps an int
	use_wrapper(&a);
	use_wrapper(&b);
	use_wrapper(&c);
}

