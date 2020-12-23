#include <iostream>

/*

Задание 2. Реализуйте задание лабораторной работы Л3
(см. раздел Л3.1, задание 1) как ассемблерную вставку
в программу на C++.

*/

int main()
{
  int x = 1;
  int y = 0;

  std::cout << "Enter x: " << '\n';
  std::cin >> x;

  asm(
    "mov %[X], %%eax\n\t"
    "imul $3, %%eax\n\t"
    "add $1, %%eax\n\t"
    "mov %%eax, %[Y]\n\t"
    :[Y]"=m"(y)
    :[X]"m"(x)
    : "cc", "eax"
  );

  std::cout << "y = x * 3 + 1 = " << y <<'\n';

  return 0;
}

// перемножить 2 байта получить слово
