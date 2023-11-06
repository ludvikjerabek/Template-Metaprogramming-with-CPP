#include <functional>

bool twice_as(int a, int b)
{
	return a>=b*2;
}

double sum_and_div(int a, int b, double c)
{
	return (a+b)/c;
}

template<typename, typename>
struct func_pair;

template<typename R1, typename... A1, typename R2, typename... A2>
struct func_pair<R1(A1...), R2(A2...)> {
  std::function<R1(A1...)> f;
  std::function<R2(A2...)> g;
};

int main()
{
	func_pair<bool(int, int), double(int, int, double)> funcs{twice_as, sum_and_div};
	funcs.f(42, 12);
	funcs.g(42, 12, 10.0);
}

