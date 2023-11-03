#include <iostream>

template<typename T>
struct parser;             // [1] template declaration

void handle(double value)  // [2] handle(double) definition
{
	std::cout << "Processing a double: " << value << std::endl;
}

template<typename T>
struct parser              // [3] template definition
{
  void parse()
  {
	  handle(42);          // [4] non-dependent name
  }
};

void handle(int value)     // [5] handle(int) definition
{
	std::cout << "Processing an int: " << value << std::endl;
}

int main()
{
	parser<int> p;       // [6] template instantiation
	p.parse();
}

