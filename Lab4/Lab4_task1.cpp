#include <iostream>
#include <bitset>
#define BITE 8
/*

Задание 1. Разработайте и выполните программу, в которой реализуйте при
помощи ассемблерной вставки

В3) Вычитание целых чисел без знака

После команды сложения/вычитания проанализируйте соответствующий флаг
состояния процессора, и, в зависимости от его значения, выведите результат
и строку «Результат верный» (если не было переполнения) или
«Результат неверный» (при переполнении).

*/

template<typename T>
void print_hex_dec_bin(T number, std::string name);

int main()
{

  int baz, bar;

  baz = -2147483640;

  std::cout << "Input the first number: ";
  std::cin >> bar;

  __asm__  __volatile__ goto(
    "mov %[BAZ], %%eax\n\t"
    "mov %[BAR], %%ecx\n\t"
    "sub %%ecx, %%eax\n\t"
    "jo %o[uncorrect]\n\t"
    :: [BAR]"rm"(bar), [BAZ]"rm"(baz)
    : "cc", "eax", "ecx"
    : uncorrect
  );

  __asm__  __volatile__ (
    "mov %%eax, %[baz]\n"
    :[baz]"=rm"(baz)
  );

  print_hex_dec_bin<int>(baz, "-2147483640 minus second");

  return 0;

  uncorrect:
  std::cout << "Overflow happened"<< '\n';

  return 1;
}

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
