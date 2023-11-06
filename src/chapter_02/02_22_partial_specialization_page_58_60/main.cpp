#include <iostream>

template<typename T, int S>
struct collection {
  void operator()()
  {
	  std::cout << "primary template" << std::endl;
  }
};

template<typename T>
struct collection<T, 10> {
  void operator()()
  {
	  std::cout << "partial specialization <T, 10>" << std::endl;
  }
};

template<int S>
struct collection<int, S> {
  void operator()()
  {
	  std::cout << "partial specialization <int, S>" << std::endl;
  }
};

template<typename T, int S>
struct collection<T*, S> {
  void operator()()
  {
	  std::cout << "partial specialization <T*, S>" << std::endl;
  }
};

int main()
{
	collection<char, 42>{}();  // primary template
	collection<int, 42>{}();   // partial specialization <int, S>
	collection<char, 10>{}();  // partial specialization <T, 10>
	collection<int*, 20>{}();  // partial specialization <T*, S>

	//collection<int, 10>{}();      // error: collection<T,10> or collection<int,S>
	//collection<char*, 10>{}();    // error: collection<T,10> or collection<T*,S>
}

