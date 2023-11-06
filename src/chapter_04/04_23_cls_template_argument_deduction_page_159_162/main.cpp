#include <iostream>
#include <vector>

template<typename T>
struct range_t {
	template<typename Iter>
	range_t(Iter first, Iter last)
	{
		std::copy(first, last, std::back_inserter(data));
	}
private:
	std::vector<T> data;
};

template<typename Iter>
range_t(Iter first, Iter last) -> range_t<typename std::iterator_traits<Iter>::value_type>;

int main()
{
	// Page 159
	int arr[] = {1, 2, 3, 4, 5};
	range_t r(std::begin(arr), std::end(arr));

	// Page 161
	std::pair<int, std::string> p1{1, "one"};  // [1] OK
	std::pair p2{2, "two"};                    // [2] OK
	//std::pair<> p3{ 3, "three" };                // [3] error
	//std::pair<int> p4{ 4, "four" };              // [4] error

	// Page 161
	std::vector v1{42};      // vector<int>
	std::vector v2{v1, v1};  // vector<vector<int>>
	std::vector v3{v1};      // vector<int>
}

