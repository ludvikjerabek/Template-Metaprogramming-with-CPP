#include <iostream>
#include <array>
#include <string>
#include <string_view>
#include <vector>
#include <map>
#include <type_traits>
#include <array>
#include <numeric>
#include <algorithm>
#include <functional>
#include <memory>
#include <cstring>



namespace n232 {
template<typename T>
void func(T a)
{
	std::cout << "primary template\n";
}

template<>
void func(int a /*= 0*/) // error: default argument
{
	std::cout << "int specialization\n";
}
}

namespace n233 {
template<typename T>
struct foo {
  static T value;
};

template<typename T> T foo<T>::value = 0;

template<> int foo<int>::value = 42;
}

namespace n234 {
template<typename T, typename U>
void func(T a, U b)
{
	std::cout << "primary template\n";
}

template<>
void func(int a, int b)
{
	std::cout << "int-int specialization\n";
}

template<>
void func(int a, double b)
{
	std::cout << "int-double specialization\n";
}
}

namespace n235 {
template<typename T, int S>
struct collection {
  void operator()()
  {
	  std::cout << "primary template\n";
  }
};

template<typename T>
struct collection<T, 10> {
  void operator()()
  {
	  std::cout << "partial specialization <T, 10>\n";
  }
};

template<int S>
struct collection<int, S> {
  void operator()()
  {
	  std::cout << "partial specialization <int, S>\n";
  }
};

template<typename T, int S>
struct collection<T*, S> {
  void operator()()
  {
	  std::cout << "partial specialization <T*, S>\n";
  }
};
}

namespace n236 {
template<int A, int B>
struct foo { };

template<int A>
struct foo<A, A> { };

//template <int A>
//struct foo<A, A + 1> {}; // error
}

namespace n237 {
template<typename T, size_t S>
std::ostream& pretty_print(std::ostream& os, std::array<T, S> const& arr)
{
	os << '[';
	if (S>0) {
		size_t i = 0;
		for (; i<S-1; ++i)
			os << arr[i] << ',';
		os << arr[S-1];
	}
	os << ']';

	return os;
}
}

namespace n238 {
template<size_t S>
std::ostream& pretty_print(std::ostream& os, std::array<char, S> const& arr)
{
	os << '[';
	for (auto const& e : arr)
		os << e;
	os << ']';

	return os;
}
}

namespace n239 {
constexpr double PI = 3.1415926535897932385L;

template<typename T>
T sphere_volume(T const r)
{
	return static_cast<T>(4*PI*r*r*r/3);
}
}

namespace n240 {
template<typename T>
struct PI {
  static const T value;
};

template<typename T>
const T PI<T>::value = T(3.1415926535897932385L);

template<typename T>
T sphere_volume(T const r)
{
	return 4*PI<T>::value*r*r*r/3;
}
}

namespace n241 {
template<class T>
constexpr T PI = T(3.1415926535897932385L);

template<typename T>
T sphere_volume(T const r)
{
	return 4*PI<T>*r*r*r/3;
}
}

namespace n242 {
struct math_constants {
  template<class T>
  static constexpr T PI = T(3.1415926535897932385L);
};

template<typename T>
T sphere_volume(T const r)
{
	return 4*math_constants::PI<T>*r*r*r/3;
}
}

namespace n243 {
struct math_constants {
  template<class T>
  static const T PI;
};

template<class T>
const T math_constants::PI = T(3.1415926535897932385L);

template<typename T>
T sphere_volume(T const r)
{
	return 4*math_constants::PI<T>*r*r*r/3;
}
}

namespace n244 {
template<typename T>
constexpr T SEPARATOR = '\n';

template<>
constexpr wchar_t SEPARATOR<wchar_t> = L'\n';

template<typename T>
std::basic_ostream<T>& show_parts(std::basic_ostream<T>& s,
		std::basic_string_view<T> const& str)
{
	using size_type = typename std::basic_string_view<T>::size_type;
	size_type start = 0;
	size_type end;
	do {
		end = str.find(SEPARATOR<T>, start);
		s << '[' << str.substr(start, end-start) << ']' << SEPARATOR<T>;
		start = end+1;
	}
	while (end!=std::string::npos);

	return s;
}
}

namespace n245 {
template<typename T>
struct foo {
  typedef T value_type;
};
}

namespace n246 {
template<typename T>
struct foo {
  using value_type = T;
};
}

namespace n247 {
template<typename T>
using customer_addresses_t = std::map<int, std::vector<T>>;

struct delivery_address_t { };
struct invoice_address_t { };

using customer_delivery_addresses_t = customer_addresses_t<delivery_address_t>;
using customer_invoice_addresses_t = customer_addresses_t<invoice_address_t>;
}

namespace n247 {
template<typename T, size_t S>
struct list {
  using type = std::vector<T>;
};

template<typename T>
struct list<T, 1> {
  using type = T;
};

template<typename T, size_t S>
using list_t = typename list<T, S>::type;
}

namespace n248 {

}

int main()
{


	{
		using namespace n231;


	}

	{
		using namespace n232;

		func(42.0);
		func(42);
	}

	{
		using namespace n233;

		foo<double> a, b;
		std::cout << a.value << '\n';
		std::cout << b.value << '\n';

		foo<int> c;
		std::cout << c.value << '\n';

		a.value = 100;
		std::cout << a.value << '\n';
		std::cout << b.value << '\n';
		std::cout << c.value << '\n';
	}

	{
		using namespace n234;

		func(1, 2);
		func(1, 2.0);
		func(1.0, 2.0);
	}

	{
		using namespace n235;

		collection<char, 42>{}();  // primary template
		collection<int, 42>{}();   // partial specialization <int, S>
		collection<char, 10>{}();  // partial specialization <T, 10>
		collection<int*, 20>{}();  // partial specialization <T*, S>

		//collection<int, 10>{}();      // error: collection<T,10> or collection<int,S>
		//collection<char*, 10>{}();    // error: collection<T,10> or collection<T*,S>
	}

	{
		using namespace n237;

		std::array<int, 9> arr{1, 1, 2, 3, 5, 8, 13, 21};
		pretty_print(std::cout, arr);

		std::array<char, 9> str;
		std::strcpy(str.data(), "template");
		pretty_print(std::cout, str);
	}

	{
		using namespace n238;

		std::array<char, 9> str;
		std::strcpy(str.data(), "template");
		pretty_print(std::cout, str);
	}

	{
		using namespace n239;

		float v1 = sphere_volume(42.0f);
		double v2 = sphere_volume(42.0);
	}

	{
		using namespace n240;

		float v1 = sphere_volume(42.0f);
		double v2 = sphere_volume(42.0);
	}

	{
		using namespace n241;

		float v1 = sphere_volume(42.0f);
		double v2 = sphere_volume(42.0);
	}

	{
		using namespace n242;

		float v1 = sphere_volume(42.0f);
		double v2 = sphere_volume(42.0);
	}

	{
		using namespace n244;
		show_parts<char>(std::cout, "one\ntwo\nthree");
		show_parts<wchar_t>(std::wcout, L"one line");
	}

	{
		typedef int index_t;
		typedef std::vector<std::pair<int, std::string>> NameValueList;
		typedef int (* fn_ptr)(int, char);

	}

	{
		using index_t = int;
		using NameValueList = std::vector<std::pair<int, std::string>>;
		using fn_ptr = int(int, char);
	}

	{
		using namespace n247;
		static_assert(std::is_same_v<list_t<int, 1>, int>);
		static_assert(std::is_same_v<list_t<int, 2>, std::vector<int>>);
	}

	{
		int arr[] = {1, 6, 3, 8, 4, 2, 9};
		std::sort(
				std::begin(arr), std::end(arr),
				[](int const a, int const b) { return a>b; });

		int pivot = 5;
		auto count = std::count_if(
				std::begin(arr), std::end(arr),
				[pivot](int const a) { return a>pivot; });

		std::cout << count << '\n';
	}

	{
		auto l1 = [](int a) { return a+a; };           // C++11, regular lambda
		auto l2 = [](auto a) { return a+a; };          // C++14, generic lambda
		auto l3 = []<typename T>(T a) { return a+a; };// C++20, template lambda

		auto v1 = l1(42);                      // OK
		auto v2 = l1(42.0);                   // warning
		//auto v3 = l1(std::string{ "42" });   // error

		auto v5 = l2(42);                    // OK
		auto v6 = l2(42.0);                  // OK
		auto v7 = l2(std::string{"42"});     // OK

		auto v8 = l3(42);                    // OK
		auto v9 = l3(42.0);                  // OK
		auto v10 = l3(std::string{"42"});   // OK
	}

	{
		auto l1 = [](int a, int b) { return a+b; };
		auto l2 = [](auto a, auto b) { return a+b; };
		auto l3 = []<typename T, typename U>(T a, U b) { return a+b; };
		auto l4 = [](auto a, decltype(a) b) { return a+b; };

		auto v1 = l1(42, 1);                      // OK
		auto v2 = l1(42.0, 1.0);                   // warning
		//auto v3 = l1(std::string{ "42" }, '1'); // error

		auto v4 = l2(42, 1);                    // OK
		auto v5 = l2(42.0, 1);                  // OK
		auto v6 = l2(std::string{"42"}, '1'); // OK
		auto v7 = l2(std::string{"42"}, std::string{"1"}); // OK

		auto v8 = l3(42, 1);                    // OK
		auto v9 = l3(42.0, 1);                  // OK
		auto v10 = l3(std::string{"42"}, '1'); // OK
		auto v11 = l3(std::string{"42"}, std::string{"42"}); // OK

		auto v12 = l4(42.0, 1); // OK
		auto v13 = l4(42, 1.0); // warning
		//auto v14 = l4(std::string{ "42" }, '1'); // error
	}

	{
		auto l = []<typename T, size_t N>(std::array<T, N> const& arr) {
		  return std::accumulate(arr.begin(), arr.end(), static_cast<T>(0));
		};

		//auto v1 = l(1); // error
		auto v2 = l(std::array<int, 3>{1, 2, 3});
	}

	{
		auto l = []<typename T>(T a, T b) { return a+b; };

		auto v1 = l(42, 1);        // OK
		//auto v2 = l(42.0, 1);    // error

		auto v4 = l(42.0, 1.0);    // OK
		//auto v5 = l(42, false);    // error

		auto v6 = l(std::string{"42"}, std::string{"1"}); // OK
		//auto v6 = l(std::string{ "42" }, '1');                // error
	}

	{
		std::function<int(int)> factorial;
		factorial = [&factorial](int const n) {
		  if (n<2) return 1;
		  else return n*factorial(n-1);
		};

		std::cout << factorial(5) << '\n';
	}

	{
		auto factorial = [](auto f, int const n) {
		  if (n<2) return 1;
		  else return n*f(f, n-1);
		};

		std::cout << factorial(factorial, 5) << '\n';
	}
}

