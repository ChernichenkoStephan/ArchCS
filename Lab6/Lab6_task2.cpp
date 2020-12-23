/*

Задание 2. Вычислите для заданного вещественного 𝑥
𝑦(𝑥) = 0, x <= 0.8
𝑦(𝑥) = x - 0.8, x > 0.8

*/


#include "iostream"

void foo(double x)
{
  double y = 1.0, a = 0.8;

  std::cout << "x = "<< x << '\n';

  asm __volatile__ (  
    "fldl %[A]\n"             // a
    "fldl %[X]\n"             // x, a
    "fsub \n\t"               // x - a
    "ftst\n"                  // if (y > 0)
    "fnstsw\n"                // Saving the current value of the SR register to the receiver
    "sahf\n"                  // Flags loading
    "jbe false \n\t"           // {
    "fstpl %[Y]\n"            // y = x - a
    "jmp end \n\t"             // }
    "false: \n\t"              // {
    "movq $0, %[Y] \n\t"      // y = 0
    "end: \n\t"               // }
    : [Y]"=rm"(y)
    : [A]"rm"(a), [X]"rm"(x)
    : "cc"
  );

  std::cout << "y(x) = " << x << " - 0.8 = " << y << '\n';
  std::cout << "---------------\n" << '\n';

}


int main()
{

foo(0.9);
foo(0.8);
foo(0.7);

  return 0;
}

/*
asm __volatile__ (  
  "fldl %[A]\n"             // a
  "fldl %[X]\n"             // x, a
  "fcomi\n"                 // if (x <= 0.8)
  "fnstsw\n"                // Saving the current value of the SR register to the receiver
  "sahf\n"                  // Flags loading
  "jbe true \n\t"            // {
  "fsub \n\t"               // x - a
  "fstpl %[Y]\n"            // y = x - a
  "jmp end \n\t"             // }
  "true: \n\t"               // {
  "movq $0, %[Y] \n\t"      // y = 0
  "end: \n\t"               // }
  : [Y]"=rm"(y)
  : [A]"rm"(a), [X]"rm"(x) // : [A]"r"(0.8), [X]"rm"(x) ?
  : "cc", "eax"
  );
*/
