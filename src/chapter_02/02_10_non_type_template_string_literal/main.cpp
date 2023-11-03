#include <iostream>
#include <numeric>
#include <memory>

template<size_t N>
struct string_literal {
  constexpr string_literal(const char(& str)[N])
  {
	  std::copy_n(str, N, value);
  }

  char value[N];
};

template<string_literal x>
struct foo { };

int main()
{
	[[maybe_unused]] foo<"42"> f;
}

