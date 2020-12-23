#include <iostream>

/*

Задание 2. Реализуйте задание лабораторной работы Л3
(см. раздел Л3.1, задание 1) как ассемблерную вставку
в программу на C++.

*/

int main()
{
  int x = 0;
  int y = 0;

  std::cout << "Enter x: " << '\n';
  std::cin >> x;

  asm(
    "imul $3, %[X]\n\t"
    "add $1, %[X]\n\t"
    "mov %[X], %[Y]\n\t"
    :[Y]"=m"(y), [X]"+r"(x)
    :
    :"cc"
  );

  std::cout << "y = x * 3 + 1 = " << y <<'\n';

  return 0;
}
