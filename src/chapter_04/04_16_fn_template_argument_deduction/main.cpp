#include <iostream>

template<typename T>
void invoke(void(* pfun)(T, int))
{
	pfun(T{}, 42);
}

template<typename T>
void alpha(T, int) { std::cout << "alpha(T,int)" << std::endl; }

void beta(int, int) { std::cout << "beta(int,int)" << std::endl; }
void beta(short, int) { std::cout << "beta(short,int)" << std::endl; }

void gamma(short, int, long long) { std::cout << "gamma(short,int,long long)" << std::endl; }
void gamma(double, int) { std::cout << "gamma(double,int)" << std::endl; }

int main()
{
	//invoke(&alpha);
	//invoke(&beta);
	invoke(&gamma);
}

