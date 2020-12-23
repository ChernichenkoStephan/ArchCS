#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void foo(int floor, int roof)
{
  srand(time(0));

  printf("rand value: %d\n", floor + (rand() % roof));
}
