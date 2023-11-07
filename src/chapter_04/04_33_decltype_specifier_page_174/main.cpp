struct foo {
  int a = 0;
  volatile int b = 0;
  const int c = 42;
};

int main()
{
	foo f;
	foo const cf;
	volatile foo* pf = &f;

	[[maybe_unused]] decltype(f.a) e1 = 0;       // int
	[[maybe_unused]] decltype(f.b) e2 = 0;       // int volatile
	[[maybe_unused]] decltype(f.c) e3 = 0;       // int const

	[[maybe_unused]] decltype(cf.a) e4 = 0;      // int
	[[maybe_unused]] decltype(cf.b) e5 = 0;      // int volatile
	[[maybe_unused]] decltype(cf.c) e6 = 0;      // int const

	[[maybe_unused]] decltype(pf->a) e7 = 0;     // int
	[[maybe_unused]] decltype(pf->b) e8 = 0;     // int volatile
	[[maybe_unused]] decltype(pf->c) e9 = 0;     // int const

	[[maybe_unused]] decltype(foo{}.a) e10 = 0;  // int
	[[maybe_unused]] decltype(foo{}.b) e11 = 0;  // int volatile
	[[maybe_unused]] decltype(foo{}.c) e12 = 0;  // int const
}

