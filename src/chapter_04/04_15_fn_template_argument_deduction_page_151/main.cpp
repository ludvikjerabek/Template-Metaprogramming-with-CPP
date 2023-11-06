#include <iostream>

template<typename T>
void process(T a = 0, T b = 42)
{
	std::cout << a << "," << b << std::endl;
}

int main()
{
	//process();        // [1] error
	process<int>();   // [2] OK
	process(10);      // [3] OK
}

