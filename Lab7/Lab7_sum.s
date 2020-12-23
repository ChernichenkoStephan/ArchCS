/*

Задание 2. Обработайте массив целых чисел 𝛼[ ]
(выделение памяти и заполнение массива может быть выполнено на языке высокого уровня).
3 Найти сумму элементов массива

*/

.globl _sum
_sum:
  pushq %rbp
  sub $16, %rsp
  pushq %rsi
  pushq %rdi

  xorq %r12, %r12 // temp_array
  xorq %r13, %r13 // temp_size
  xorq %r14, %r14 // i
  xorq %r15, %r15 // res

  movq %rdi, %r12 // array
	movq %rsi, %r13 // size

  begin_iteration:
  cmp %r13, %r14
  jge end_loop

  movq (%r12, %r14, 4), %rsi
  addq %rsi, %r15

  incq %r14
  jmp begin_iteration
  end_loop:

  movq %r15, %rax // return

  popq %rdi
  popq %rsi
  add $16, %rsp
  popq %rbp
  ret
