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
	  //init();        // error: identifier not found
	  this->init();

	  std::cout << "parse" << std::endl;
  }
};

int main()
{
	parser<int> p;
	p.parse();
}

