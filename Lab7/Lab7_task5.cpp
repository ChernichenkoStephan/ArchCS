/*

Задание 5. Опишите вставку либо функцию, инициализирующую массив заданной
длины 𝑁 первыми 𝑁 элементами последовательности из задания 3 лабораторной работы Л6.

*/

#include <iostream>

#ifdef __cplusplus
extern "C" void fibonaci(int* array, int size);
#else
void fibonaci(int* array, int size);
#endif

static void print_array(int* arr, int number_of_elements);

int main()
{
  int n = 10;
  int array[10];
  fibonaci(array, n);
  print_array(array, n);
  return 0;
}

static void print_array(int* arr, int number_of_elements) {
	for (int i = 0; i < number_of_elements; i++) {
		std::cout << arr[i] << " ";
	}
  std::cout << '\n';
}
