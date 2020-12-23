/*

Задание 2. Обработайте массив целых чисел 𝛼[ ]
(выделение памяти и заполнение массива может быть выполнено на языке высокого уровня).
3 Найти сумму элементов массива

*/

#include <iostream>

#ifdef __cplusplus
extern "C" int sum(int* array, int size);
#else
int sum(int* array, int size);
#endif

static void print_array(int* arr, int number_of_elements);
int* generate_array(int number_of_elements);

int main()
{
  int n = 10;
  int* array = generate_array(n);
  print_array(array, n);
  int sum_of_elements  = sum(array, n);
  std::cout << "\nSum of elements = " << sum_of_elements << '\n';
  print_array(array, n);
  return 0;
}

int* generate_array(int number_of_elements) {

	int* generated_array = new int[number_of_elements];
	if (generated_array != nullptr) {
		for (int i = 0; i < number_of_elements; i++) {
			generated_array[i] = rand() % 100;
		}
	}
	return generated_array;
}


static void print_array(int* arr, int number_of_elements) {
	for (int i = 0; i < number_of_elements; i++) {
		std::cout << arr[i] << " ";
	}
  std::cout << '\n';
}
