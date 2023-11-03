#include <iostream>

template<typename T>
struct base_parser {
  using value_type = T;
};

template<typename T>
struct parser : base_parser<T> {
  void parse()
  {
	  //value_type v{}; //syntax error: unexpected token 'identifier', expected ';'
	  //base_parser<T>::value_type v{};
	  typename base_parser<T>::value_type v{};

	  std::cout << "parse" << std::endl;
  }
};

int main()
{
	parser<int> p;
	p.parse();
}

