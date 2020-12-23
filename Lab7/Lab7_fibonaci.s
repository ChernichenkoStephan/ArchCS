/*

Задание 5. Опишите вставку либо функцию, инициализирующую массив заданной
длины 𝑁 первыми 𝑁 элементами последовательности из задания 3 лабораторной работы Л6.

*/


.globl _fibonaci
_fibonaci:
  pushq %rbp
  sub $16, %rsp //; 5*8 40
  pushq %rsi
  pushq %rdi
  pushq %rbx
  pushq %rax

  xorq %r12, %r12 // temp_array
  xorq %r13, %r13 // temp_size
  xorq %r14, %r14 // i

  movq %rdi, %r12 // array
	movq %rsi, %r13 // size

  movq $1, %rsi //; prew r12
  movq $1, %rdi //; curr r13
  movq $1, %rbx //; next r14

  begin_iteration:
  cmp %r13, %r14
  jge end_loop

  movq %rbx, %rdi //; curr = next

  movq %rdi, %rax
  addq %rsi, %rax //; curr + prew
  movq %rax, %rbx //; next = curr + prew

  movq %rdi, %rsi //; prew = curr

  movl %esi, (%r12, %r14, 4)

  incq %r14
  jmp begin_iteration
  end_loop:

  popq %rax
  popq %rbx
  popq %rdi
  popq %rsi
  add $16, %rsp
  popq %rbp
  ret
