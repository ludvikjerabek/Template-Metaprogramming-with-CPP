#include <iostream>

template<size_t N>
struct ncube {
  static constexpr size_t dimensions = N;
};

template<size_t N>
void process(ncube<N-1> cube)
{
	std::cout << "Cube Dimensions: " << cube.dimensions << std::endl;
}

int main()
{
	ncube<5> cube;
	// process(cube); // error
	process<6>(cube); // OK
}

