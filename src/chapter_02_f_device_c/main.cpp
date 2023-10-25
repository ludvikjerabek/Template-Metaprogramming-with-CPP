#include <iostream>
#include <numeric>
#include <memory>

struct device {
  virtual void output() = 0;
  virtual ~device() { }
};

template<void (* action)()>
struct smart_device : device {
  void output() override
  {
	  (*action)();
  }
};

void say_hello_in_english()
{
	std::cout << "Hello, world!\n";
}

void say_hello_in_spanish()
{
	std::cout << "Hola mundo!\n";
}

int main()
{
	{
		auto w1 = std::make_unique<smart_device<&say_hello_in_english>>();
		w1->output();

		auto w2 = std::make_unique<smart_device<&say_hello_in_spanish>>();
		w2->output();

		static_assert(!std::is_same_v<decltype(w1), decltype(w2)>);
	}

	{
		std::unique_ptr<device> w1 = std::make_unique<smart_device<&say_hello_in_english>>();
		w1->output();

		std::unique_ptr<device> w2 = std::make_unique<smart_device<&say_hello_in_spanish>>();
		w2->output();

		static_assert(std::is_same_v<decltype(w1), decltype(w2)>);
	}
}

