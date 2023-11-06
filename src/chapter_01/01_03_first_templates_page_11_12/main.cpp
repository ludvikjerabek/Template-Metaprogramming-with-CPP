#include <iostream>
#include <string.h>
#include <stdexcept>

template<typename T>
class vector {
public:
	vector()
	{
		arr_ = new T[1];
		capacity_ = 1;
		size_ = 0;
	}
	vector(size_t capacity)
	{
		arr_ = new T[capacity];
		capacity_ = capacity;
		size_ = 0;
	}
	~ vector()
	{
		delete[] arr_;
	}

	void push_back(T data)
	{
		if (size_==capacity_) {
			resize(2*capacity_);
		}
		arr_[size_] = data;
		size_++;
	}
	T at(size_t index)
	{
		if (index<size_)
			return arr_[index];
		else
			throw std::out_of_range("Index is greater than size of vector");
	}
	T operator[](size_t index) const
	{
		if (index<size_)
			return arr_[index];
		else
			throw std::out_of_range("Index is greater than size of vector");
	}
	void pop_back()
	{
		if (size_>0)
			size_--;
	}
	void resize(size_t capacity)
	{
		if (capacity<1) return;
		T* temp = new T[capacity];
		size_t c = (capacity<capacity_) ? capacity : capacity_;
		for (size_t i = 0; i<c; i++) {
			temp[i] = arr_[i];
		}
		delete[] arr_;
		arr_ = temp;
		capacity_ = capacity;
		if (size_>capacity_)
			size_ = capacity_;
	}
	void clear() { size_ = 0; }
	size_t size() { return size_; }
	size_t capacity() { return capacity_; }
private:
	T* arr_;
	size_t capacity_;
	size_t size_;
};

int main()
{
	vector<int> v(10);
	std::cout << "Size: " << v.size() << " Capacity: " << v.capacity() << std::endl;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	std::cout << "Size: " << v.size() << " Capacity: " << v.capacity() << std::endl;
	v.push_back(6);
	v.push_back(7);
	v.push_back(8);
	v.push_back(9);
	v.push_back(10);
	std::cout << "Size: " << v.size() << " Capacity: " << v.capacity() << std::endl;
	v.push_back(11);
	v.push_back(12);
	v.push_back(13);
	v.push_back(14);
	v.push_back(15);
	std::cout << "Size: " << v.size() << " Capacity: " << v.capacity() << std::endl;

	for (size_t i = 0; i<v.size(); i++)
		std::cout << v[i] << std::endl;

	std::cout << "Size: " << v.size() << " Capacity: " << v.capacity() << std::endl;

	while (v.size()>0)
		v.pop_back();

	std::cout << "Size: " << v.size() << " Capacity: " << v.capacity() << std::endl;
}