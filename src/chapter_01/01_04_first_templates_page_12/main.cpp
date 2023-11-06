#include <iostream>

template<typename T>
constexpr T NewLine = T('\n')

int main()
{
	std::wstring test = L"demo";
	test += NewLine<wchar_t>;
	std::wcout << test;
}