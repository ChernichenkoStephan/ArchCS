#include "iostream"
/*

Задание 1. Вычислите для заданных целых 𝑥, 𝑦

𝑓(𝑥,𝑦) = y/x, y%x = 0;
𝑓(𝑥,𝑦) = y*x, y%x != 0;

*/

void foo(int x, int y)
{
  int f = 0;

  std::cout << "x = "<< x << "\ny = "<< y  << '\n';

  asm __volatile__ (  
    "mov %[Y], %%eax \n\t"    // eax = y
    "mov $0, %%edx \n\t"      // edx = 0
    "divq %[X] \n\t"          // y / x
    "cmpl $0, %%edx \n\t"     // if (y%x == 0) remainder of division - in place of the older half (in 𝐷)
    "jne not_even \n\t"        // {
    "mov %%eax, %[F] \n\t"    // f = y / x
    "jmp end \n\t"             // }
    "not_even: \n\t"           // {
    "mov %[Y], %%eax \n\t"    // Moving y for multiplication in idiv
    "imul %[X], %%eax \n\t"   // x * y
    "mov %%eax, %[F] \n\t"    // f = y * x
    "end: \n\t"               // }
    : [F]"=rm"(f)
    : [X]"rm"(x), [Y]"rm"(y)
    : "cc", "eax"
  );

  std::cout << "f(x,y) = " << f << '\n';
  std::cout << "---------------\n" << '\n';

}


int main()
{

foo(2, 2);
foo(3, 6);
foo(2, 3);


  return 0;
}
