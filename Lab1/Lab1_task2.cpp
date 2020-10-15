#include <iostream>
#include <bitset>
#include <climits>

// clear && g++ -o task2 Lab1_task2.cpp && ./task2

#define BITE 8

template<typename T>
void print_hex_dec_bin(T number, std::string name) {
	std::cout << "-------------- "<< name <<" --------------" << std::endl
            << "hex: "
            << std::hex
            << number
            << std::endl
            << "dec: "
            << std::dec
            << number
            << std::endl
            << "binary: "
            << std::bitset<sizeof(T) * BITE>(number)
            << "\n=====================================" << std::endl;
}

int main() {

	system("clear");

	std::cout << "Unsigned short maximum value:" << std::endl;
	print_hex_dec_bin<unsigned short>(USHRT_MAX, "USHRT_MAX");

  std::cout << std::endl << "Unsigned integer minimum value:" << std::endl;
	print_hex_dec_bin<unsigned>(0, "0");

  std::cout << std::endl << "Short maximum value:" << std::endl;
	print_hex_dec_bin<short>(SHRT_MAX,"SHRT_MAX");

  std::cout << std::endl << "Integer maximum value:" << std::endl;
	print_hex_dec_bin<int>(INT_MAX, "INT_MAX");

	return 0;
}
