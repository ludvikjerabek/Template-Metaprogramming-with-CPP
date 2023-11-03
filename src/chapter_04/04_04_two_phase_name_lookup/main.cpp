#include <iostream>

template<typename T>
struct base_parser {
  void init()
  {
	  std::cout << "init" << std::endl;
  }
};

template<typename T>
struct parser : base_parser<T> {
  void parse()
  {
	  this->init();

	  std::cout << "parse" << std::endl;
  }
};

template<>
struct base_parser<int> {
  void init()
  {
	  std::cout << "specialized init" << std::endl;
  }
};

int main()
{
	parser<int> p1;
	p1.parse();

	parser<double> p2;
	p2.parse();
}

