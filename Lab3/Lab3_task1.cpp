#include <stdio.h>

#ifdef __cplusplus
extern "C" int foo(int);
#else
int foo(int);
#endif

int main()
{
  int x = 1;
  int y = foo(x);
  printf("y = 3 * 1 + 1 = %d\n", y);
  return 0;
}
