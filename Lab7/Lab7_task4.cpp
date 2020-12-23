/*

Задание 4. Реализуйте задание 2 для значений тех элементов массива 𝛽[ ],
ключ которых равен заданному числу 𝜅. Если таких нет, вывести корректное сообщение об этом.

*/

#include <iostream>

struct b
{
  int key;
  int value;
};


static void print_array(struct b* arr, int number_of_elements);
struct b* generate_array(int number_of_elements);

#ifdef __cplusplus
extern "C" int key_sum(struct b* array, int size, int key);
#endif


int main()
{
  int n = 10;
  float check_sum = 0;
  struct b* array = generate_array(n);
  print_array(array, n);

  float sum_of_elements  = key_sum(array, n, 1);


  for (size_t i = 0; i < n; i++) {
    if (i % 3 == 0) {
      check_sum += array[i].value;
    }
  }

  print_array(array, n);
  std::cout << "\nSum of elements = " << sum_of_elements
            << "\nCheck sum of elements = " << check_sum << '\n';
  return 0;
}

struct b* generate_array(int number_of_elements) {

	struct b* generated_array = new b[number_of_elements];
	if (generated_array != nullptr) {
		for (int i = 0; i < number_of_elements; i++) {
			if (i % 3 == 0) {
        generated_array[i].key = 1;
      } else {
        generated_array[i].key = 2;
      }
      generated_array[i].value = rand() % 100;
		}
	}
	return generated_array;
}


static void print_array(b* arr, int number_of_elements) {
	for (int i = 0; i < number_of_elements; i++) {
		std::cout << "key: " << arr[i].key << " value: " << arr[i].value << '\n';
	}
  std::cout << '\n';
}
