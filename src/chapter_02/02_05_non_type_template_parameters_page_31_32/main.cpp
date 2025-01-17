#include <iostream>
#include <numeric>

template<typename T, size_t S>
class buffer {
	T data_[S];
public:
	constexpr T const* data() const { return data_; }

	constexpr T& operator[](size_t const index)
	{
		return data_[index];
	}

	constexpr T const& operator[](size_t const index) const
	{
		return data_[index];
	}
};

template<typename T, size_t S>
buffer<T, S> make_buffer()
{
	return {};
}

int main()
{
	{
		buffer<int, 10> b1;
		buffer<int, 2*5> b2;

		std::cout << std::is_same_v<buffer<int, 10>, buffer<int, 2*5>> << std::endl;
		std::cout << std::is_same_v<decltype(b1), decltype(b2)> << std::endl;

		static_assert(std::is_same_v<decltype(b1), decltype(b2)>);

		buffer<int, 3*5> b3;
		std::cout << std::is_same_v<decltype(b1), decltype(b3)> << std::endl;

		static_assert(!std::is_same_v<decltype(b1), decltype(b3)>);
	}
	// Note the other samples were missing from the source, the following was part of the original.
	{
		buffer<int, 10> b1;
		b1[0] = 42;
		std::cout << b1[0] << std::endl;
		auto b2 = make_buffer<int, 10>();
	}
}

