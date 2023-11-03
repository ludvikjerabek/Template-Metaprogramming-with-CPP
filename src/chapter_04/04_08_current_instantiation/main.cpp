#include <iostream>

template<typename T>
struct parser {
  parser* p1;          // parser is the CI
  parser<T>* p2;       // parser<T> is the CI
  ::parser<T>* p3;  // ::parser<T> is the CI
  //parser<T*> p4;     // parser<T*> is not the CI

  struct token {
	token* t1;              // token is the CI
	parser<T>::token* t2;   // parser<T>::token is the CI
	//typename parser<T*>::token* t3; // parser<T*>::token is not the CI
  };

  int main()
  {
	  [[maybe_unused]] parser<int> p;
  }

