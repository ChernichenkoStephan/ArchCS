/*
Задание 2.
Разработайте программу, целиком написанную на ассемблере, вычисляющую
значение 𝑦(𝑥) для 𝑥 = 13 и выводящую полученное значение на стандартный
вывод с использованием библиотеки libc (в частности, функции printf).
*/

.section __DATA,__data
L_.str:
	.asciz	"y = 3 * 12 + 1 = %d\n"

.section __TEXT,__text
.globl _main
_main:
  pushq %rbp // init

  movl $12, %eax                // eax = y = x
  imul $3, %eax
  add $1, %eax

  movl	%eax, %esi
  leaq	L_.str(%rip), %rdi
	// movb	$0, %al
	callq	_printf

  popq %rbp
	xor %eax, %eax
	ret
  // movl $0x2000001, %eax
  // syscall
