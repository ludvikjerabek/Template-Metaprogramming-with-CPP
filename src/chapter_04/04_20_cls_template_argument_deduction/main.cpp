#include <iostream>
#include <thread>

template<typename T>
struct point_t {
	point_t(T vx, T vy)
			:x(vx), y(vy) { }

private:
	T x;
	T y;
};

int main()
{
	auto p = new point_t(1, 2);

	std::mutex mt;

	auto l = std::lock_guard(mt);

	// stream_t<42> s; // C++20
}

