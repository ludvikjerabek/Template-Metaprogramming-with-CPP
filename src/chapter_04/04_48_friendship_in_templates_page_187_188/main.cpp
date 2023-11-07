#include <iostream>

template<typename T>
struct connection {
	connection(std::string const& host, int const port)
			:ConnectionString(host+":"+std::to_string(port)) { }
private:
	std::string ConnectionString;
	friend T;
};

struct executor {
  void run()
  {
	  connection<executor> c("localhost", 1234);

	  std::cout << c.ConnectionString << std::endl;
  }
};

int main()
{
	executor e;
	e.run();
}

