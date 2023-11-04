#include <iostream>

template<typename T, T i>
void process(double arr[i])
{
	using index_type = T;
	std::cout << "processing " << i << " doubles" << std::endl;
	std::cout << "index type is " << typeid(T).name() << std::endl;
}

int main()
{
	double arr[5]{};
	//process(arr);           // error
	process<int, 5>(arr);   // OK
}

