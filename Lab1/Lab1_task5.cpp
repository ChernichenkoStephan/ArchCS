#include <iostream>
#include <bitset>
#include <cmath>

#define BITE 8

// clear && g++ -w -o task5 Lab1_task5.cpp && ./task5

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

uint32_t _16to32(uint16_t number) {
  uint32_t res = static_cast<uint32_t>(number);
  return res;
}

int main() {

  uint16_t x       = 0x8001;
	uint16_t minus_x = 0x8001 * (-1);

	print_hex_dec_bin<uint16_t>(x, "16 bits");
  print_hex_dec_bin<uint32_t>(_16to32(x), "32 bits");

	print_hex_dec_bin<uint16_t>(minus_x, "16 bits minus");
	print_hex_dec_bin<uint32_t>(_16to32(minus_x), "32 bits minus");

  return 0;
}
