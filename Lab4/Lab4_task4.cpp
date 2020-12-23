#include <iostream>
#include <bitset>
#define BITE 8

/*

Задание 4. Бонус (+2 балла).
Придумайте и запишите в отчёте:

– маску (т.е. второй операнд бинарной побитовой операции) для преобразования
кодов ASCII [59] цифр ’0’...’9’ в их двоичные эквиваленты
(однобайтовые числа 0...9) с помощью операции AND.
Ответ: 0001111

При этом ASCII-код нуля (шестнадцатеричное число 0x30, что также иногда
записывается как 30/16, однако наиболее предпочтительное и
самодокументирующееся представление ASCII-кода нуля — ’0’)
должен быть преобразован в однобайтовое число 00, ASCII-код единицы
(’1’, шестнадцатеричное число 0x31 или 3116 ) — в 01, и т. д.;

– необходимую операцию и маску для преобразования однобайтовых чисел 0...9
  в их коды ASCII;
  Ответ: преобразование при помощи "OR", маска - 00110000

– маску, которая преобразовывает строчные английские буквы в прописные и
  наоборот с помощью операции XOR.
  Коды ASCII приведены в приложении Б.
  Ответ: 0100000 1011111



Реализуйте преобразования ASCII-кодов цифр в значения и обратно как
ассемблерную вставку в программу на C++.

*/

template<typename T>
void print_hex_dec_bin(T number, std::string name);

int main() {

  char a = -1, ch, b = -1;
  int number;

  std::cout << "Input the first number: ";
  std::cin >> number;

  asm(
    "mov %[NUMBER], %%eax\n\t"
    "or $0x30, %%al\n\t"
    "mov %%al, %[CHAR]\n\t"
    :[CHAR]"=m"(ch)
    :[NUMBER]"g"(number)
  );

  print_hex_dec_bin<char>(ch, "Int to char");

  while (true) {
    std::cout << "Input the second number: ";
    std::cin >> ch;
    if (ch > 48 && ch < 57) {break;}
  }

  asm(
    "movzbl %[CHAR], %%eax\n\t"
    "and $0xF, %%eax\n\t"
    "mov %%eax, %[NUMBER]\n\t"
    :[NUMBER]"=m"(number)
    :[CHAR]"g"(ch)
    :"cc", "eax"
  );

  print_hex_dec_bin<int>(number, "Char to int");

  return 0;

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
