/*

Задание 3. Задайте с клавиатуры 𝑁 и напечатайте
первые 𝑁 членов последовательности (целой).

Числа Фибоначчи: 𝜙0 = 𝜙1 = 1, 𝜙𝑖+1 = 𝜙𝑖 + 𝜙𝑖−1

prew = 1;
curr = 1
for (size_t i = 0; i < count; i++) {
  curr = next;
  next = curr + prew;
  prew = curr;
}

*/
.data
OUT:
  .asciz "%d\n"
H:
  .asciz "-- Fibonacci numbers --\nEnter n: "
STRO:
  .asciz "You entered: %d\n"
INPUT:
  .asciz "%d"

.text
.globl _main
_main:
  pushq %rbp
  /*
  pushq %rbx
  pushq %r12
  pushq %r13
  pushq %r14
  pushq %r15
  sub $64, %rsp // init
  */
  sub $16, %rsp //; init

  //; Print call
  leaq H(%rip), %rdi
  movb $0, %al
  callq _printf

  //; Scan call
  leaq (%rsp), %rsi
  leaq INPUT(%rip), %rdi
  movb $0, %al
  callq	_scanf
  movl (%rsp), %eax // eax = n

  //; Print call
  movl %eax, %esi
  leaq STRO(%rip), %rdi
  movb $0, %al
  callq _printf

  movq $1, %rbx //; counter
  movq $1, %r12 //; prew r13
  movq $1, %r13 //; curr
  movq $1, %r14 //; next

  begin_iteration:
  movl (%rsp), %eax
  cmp %rax, %rbx
  jg end

  movq %r14, %r13 //; curr = next

  movq %r13, %r15
  addq %r12, %r15 //; curr + prew
  movq %r15, %r14 //; next = curr + prew

  movq %r13, %r12 //; prew = curr

  //; Print call
  movq %r12, %rsi
  leaq OUT(%rip), %rdi
  movb $0, %al
  callq _printf

  /* -- downloading for saving --

 */
  addq $1, %rbx

  jmp begin_iteration

  end:

  add $16, %rsp
  /*
  add $64, %rsp
  popq %r15
  popq %r14
  popq %r13
  popq %r12
  popq %rbx
  */
  popq %rbp
  xor %eax, %eax // end
  ret
