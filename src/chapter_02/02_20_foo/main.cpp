template<typename>
struct foo { };    // primary template

template<>
struct foo<int>;  // explicit specialization declaration

int main()
{
	[[maybe_unused]] foo<double> a; // OK
	[[maybe_unused]] foo<int>* b;   // OK
	//foo<int> c;    // error, foo<int> incomplete type
}

