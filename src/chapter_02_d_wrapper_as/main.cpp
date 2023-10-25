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
	template<typename U>
	U as() const
	{
		return static_cast<U>(value);
	}
private:
	T value;
};

int main()
{
	wrapper<double> a(4.22222); // wraps an int
	wrapper<char> b('A'); // wraps an int
	std::cout << "Original (double): " << a.get() << " as int " << a.as<int>() << std::endl;
	std::cout << "  Original (char): " << b.get() << " as int " << b.as<int>() << std::endl;
}

