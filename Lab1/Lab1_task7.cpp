#include <iostream>
#include <cstddef>

// clear && g++ -o task9 Lab1_task9.cpp && ./task9

int main(){
  std::cout << "Size of char: "          << sizeof(char) << std::endl;
  std::cout << "Size of bool: "          << sizeof(bool) << std::endl;
  std::cout << "Size of wchar_t: "       << sizeof(wchar_t) << std::endl;
  std::cout << "Size of short: "         << sizeof(short) << std::endl;
  std::cout << "Size of int: "           << sizeof(int) << std::endl;
  std::cout << "Size of long: "          << sizeof(long) << std::endl;
  std::cout << "Size of long long: "     << sizeof(long long) << std::endl;
  std::cout << "Size of float: "         << sizeof(float) << std::endl;
  std::cout << "Size of double: "        << sizeof(double) << std::endl;
  std::cout << "Size of long double: "   << sizeof(long double) << std::endl;
  std::cout << "Size of size_t: "        << sizeof(size_t) << std::endl;
  std::cout << "Size of ptrdiff_t: "     << sizeof(ptrdiff_t) << std::endl;
  std::cout << "Size of void: "          << sizeof(void*) << std::endl;
	return 0;
}
