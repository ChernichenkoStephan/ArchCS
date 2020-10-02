#include <iostream>
#include <bitset>
#include <iomanip>

// clear && g++ -o task4 Lab1_task4.cpp && ./task4

#define BITE 8
#define LENGTH sizeof(uint16_t) * BITE


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
            << "\n=====================================\n" << std::endl;
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

template<typename T>
void print_equasion(T arg1, T arg2, T res, std::string symbol) {
	std::cout << std::bitset<sizeof(T) * BITE>(arg1) << symbol + "\n"
						<< std::bitset<sizeof(T) * BITE>(arg2) << std::endl
						<< std::bitset<sizeof(T) * BITE>(res) << std::endl;
}

template<typename T>
void print_equasion(T arg, T res, std::string symbol) {
	std::cout << std::bitset<sizeof(T) * BITE>(arg) << symbol + "\n"
						<< std::bitset<sizeof(T) * BITE>(res) << std::endl;
}

template<typename T>
void print_functions(T x1, T y1, T x2, T y2) {

	print_equasion<T>(x1, y1, conjunction<T>(x1, y1), "&");
	print_hex_dec_bin<T>(conjunction<T>(x1, y1), "first uint16_t conjunction result");
	print_equasion<T>(x2, y2, conjunction<T>(x2, y2), "&");
	print_hex_dec_bin<T>(conjunction<T>(x2, y2), "second uint16_t conjunction result");
	std::cout << "\n" << '\n';

	print_equasion<T>(x1, y1, disjunction<T>(x1, y1), "|");
	print_hex_dec_bin<T>(disjunction<T>(x1, y1), "first uint16_t disjunction result");
	print_equasion<T>(x2, y2, disjunction<T>(x2, y2), "|");
	print_hex_dec_bin<T>(disjunction<T>(x2, y2), "second uint16_t disjunction result");
	std::cout << "\n" << '\n';

	print_equasion<T>(x1, y1, XOR<T>(x1, y1), " XOR");
	print_hex_dec_bin<T>(XOR<T>(x1, y1), "first uint16_t XOR result");
	print_equasion<T>(x2, y2, XOR<T>(x2, y2), " XOR");
	print_hex_dec_bin<T>(XOR<T>(x2, y2), "second uint16_t XOR result");
	std::cout << "\n" << '\n';

	print_equasion<T>(x1, denial<T>(x1), " ~");
	print_hex_dec_bin<T>(denial<T>(x1), "first uint16_t denial result");
	print_equasion<T>(x2, denial<T>(x2), " ~");
	print_hex_dec_bin<T>(denial<T>(x2), "second uint16_t denial result");
	std::cout << "\n" << '\n';

	print_equasion<T>(x1, right<T>(x1, 1), " >>");
	print_hex_dec_bin<T>(right<T>(x1, 1), "first uint16_t right 1 result");
	print_equasion<T>(x2, right<T>(x2, 1), " >>");
	print_hex_dec_bin<T>(right<T>(x2, 1), "second uint16_t right 1 result");
	std::cout << "\n" << '\n';

	print_equasion<T>(x1, left<T>(x1, 1), " <<");
	print_hex_dec_bin<T>(left<T>(x1, 1), "first uint16_t left 1 result");
	print_equasion<T>(x2, left<T>(x2, 1), " <<");
	print_hex_dec_bin<T>(left<T>(x2, 1), "second uint16_t left 1 result");
	std::cout << "\n" << '\n';
}

int main() {

	system("clear");

	std::cout << "//////////////////////// Unsigned ////////////////////////" << '\n';
	{
		uint16_t x1 = 0x9211;
		uint16_t y1 = 0x0004;

		uint16_t x2 = 0x0009;
		uint16_t y2 = 0x0013;

		print_functions<uint16_t>(x1,  y1, x2,  y2);
	}

	std::cout << "//////////////////////// Signed ////////////////////////" << '\n';
	{
		int16_t x1 = 0x9211;
		int16_t y1 = 0x0004;

		int16_t x2 = 0x0009;
		int16_t y2 = 0x0013;

		print_functions<uint16_t>(x1,  y1, x2,  y2);
	}

  return 0;
}
