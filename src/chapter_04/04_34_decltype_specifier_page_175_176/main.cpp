struct foo {
  int a = 0;
  volatile int b = 0;
  const int c = 42;
};

int main()
{
	// Page 175
	foo f;
	foo const cf;
	volatile foo* pf = &f;

	int x = 1;
	int volatile y = 2;
	int const z = 3;

	[[maybe_unused]] decltype((f.a)) e1 = x;       // int&
	[[maybe_unused]] decltype((f.b)) e2 = y;       // int volatile&
	[[maybe_unused]] decltype((f.c)) e3 = z;       // int const&

	[[maybe_unused]] decltype((cf.a)) e4 = x;      // int const&
	[[maybe_unused]] decltype((cf.b)) e5 = y;      // int const volatile&
	[[maybe_unused]] decltype((cf.c)) e6 = z;      // int const&

	[[maybe_unused]] decltype((pf->a)) e7 = x;     // int volatile&
	[[maybe_unused]] decltype((pf->b)) e8 = y;     // int volatile&
	[[maybe_unused]] decltype((pf->c)) e9 = z;     // int const volatile&

	[[maybe_unused]] decltype((foo{}.a)) e10 = 0;  // int&&
	[[maybe_unused]] decltype((foo{}.b)) e11 = 0;  // int volatile&&
	[[maybe_unused]] decltype((foo{}.c)) e12 = 0;  // int const&&

	// Page 176
	int a = 0;
	int& ra = a;
	int const c = 42;
	int volatile d = 99;

	[[maybe_unused]] decltype(ra)& e1 = a;          // int&
	[[maybe_unused]] decltype(c) const e2 = 1;      // int const
	[[maybe_unused]] decltype(d) volatile e3 = 1;   // int volatile
}

