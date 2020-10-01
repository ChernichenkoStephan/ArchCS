#include <iostream>
#include <bitset>
#include <cmath>

// clear && g++ -o task4 Lab1_task4.cpp && ./task4

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


template<typename T>
T conjunction (T _a, T _b) {
  return _a & _b;
};

template<typename T>
T disjunction (T _a, T _b) {
  return _a | _b;
};

template<typename T>
T XOR (T _a, T _b) {
  return _a ^ _b;
};

template<typename T>
T denial (T _a) {
  return ~_a;
};

template<typename T>
T right (T _a, size_t b) {
  return _a >> b;
};

template<typename T>
T left (T _a, size_t b) {
  return _a << b;
};


int main() {

	system("clear");

  {
		uint16_t x1 = 0x9211;
	  uint16_t y1 = 0x0004;

	  uint16_t x2 = 0x0009;
	  uint16_t y2 = 0x0013;

		std::cout << "-------------- Unsigned --------------" << '\n';

		print_hex_dec_bin<uint16_t>(conjunction<uint16_t>(x1, y1), "uint16_t conjunction");
		print_hex_dec_bin<uint16_t>(conjunction<uint16_t>(x2, y2), "uint16_t conjunction");

		print_hex_dec_bin<uint16_t>(disjunction<uint16_t>(x1, y1), "uint16_t disjunction");
		print_hex_dec_bin<uint16_t>(disjunction<uint16_t>(x2, y2), "uint16_t disjunction");

		print_hex_dec_bin<uint16_t>(XOR<uint16_t>(x1, y1), "uint16_t XOR");
		print_hex_dec_bin<uint16_t>(XOR<uint16_t>(x2, y2), "uint16_t XOR");

		print_hex_dec_bin<uint16_t>(denial<uint16_t>(x1), "uint16_t denial");
		print_hex_dec_bin<uint16_t>(denial<uint16_t>(x2), "uint16_t denial");

		print_hex_dec_bin<uint16_t>(right<uint16_t>(x1, 1), "uint16_t right");
		print_hex_dec_bin<uint16_t>(right<uint16_t>(x2, 1), "uint16_t right");

		print_hex_dec_bin<uint16_t>(left<uint16_t>(x1, 1), "uint16_t left");
		print_hex_dec_bin<uint16_t>(left<uint16_t>(x2, 1), "uint16_t left");
	}

	{
		int16_t x1 = 0x9211;
		int16_t y1 = 0x0004;

		int16_t x2 = 0x0009;
		int16_t y2 = 0x0013;

		std::cout << "\n\n\n\n-------------- Signed --------------" << '\n';

		print_hex_dec_bin<int16_t>(conjunction<int16_t>(x1, y1), "int16_t conjunction");
		print_hex_dec_bin<int16_t>(conjunction<int16_t>(x2, y2), "int16_t conjunction");

		print_hex_dec_bin<int16_t>(disjunction<int16_t>(x1, y1), "int16_t disjunction");
		print_hex_dec_bin<int16_t>(disjunction<int16_t>(x2, y2), "int16_t disjunction");

		print_hex_dec_bin<int16_t>(XOR<int16_t>(x1, y1), "int16_t XOR");
		print_hex_dec_bin<int16_t>(XOR<int16_t>(x2, y2), "int16_t XOR");

		print_hex_dec_bin<int16_t>(denial<int16_t>(x1), "int16_t denial");
		print_hex_dec_bin<int16_t>(denial<int16_t>(x2), "int16_t denial");

		print_hex_dec_bin<int16_t>(right<int16_t>(x1, 1), "int16_t right");
		print_hex_dec_bin<int16_t>(right<int16_t>(x2, 1), "int16_t right");

		print_hex_dec_bin<int16_t>(left<int16_t>(x1, 1), "int16_t left");
		print_hex_dec_bin<int16_t>(left<int16_t>(x2, 1), "int16_t left");
	}


  return 0;
}
