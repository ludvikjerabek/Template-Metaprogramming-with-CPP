#include <utility>

template<typename T, typename U>
struct composition {
  using result_type = decltype(std::declval<T>()+std::declval<U>());
};

struct wrapper {
  wrapper(int const v)
		  :value(v) { }

  int value;

  friend wrapper operator+(int const a, wrapper const& w)
  {
	  return wrapper(a+w.value);
  }

  friend wrapper operator+(wrapper const& w, int const a)
  {
	  return wrapper(a+w.value);
  }
};

int main()
{
	static_assert(
			std::is_same_v<
					double,
					composition<int, double>::result_type>);

	static_assert(
			std::is_same_v<
					wrapper,
					composition<int, wrapper>::result_type>);
}

