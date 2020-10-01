#include <iostream>
#include <cmath>
#include <bitset>

// clear && g++ -o task1 Lab1_task1.cpp && ./task1

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

	int16_t x = pow(-2, 15);
	int16_t y = pow(2, 15);

  print_hex_dec_bin<int16_t>(x, "-2^15"); //происходит переполнение
  std::cout << "\n\n\n";
	print_hex_dec_bin<int16_t>(y, "2^15"); //происходит переполнение

	return 0;

}
