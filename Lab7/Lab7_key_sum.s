/*

Задание 4. Реализуйте задание 2 для значений тех элементов массива 𝛽[ ],
ключ которых равен заданному числу 𝜅. Если таких нет, вывести корректное сообщение об этом.

*/
.data
STR:
  .string "key_sum: Elements not found\n"


.text
.globl _key_sum
_key_sum:
  pushq %rbp
  sub $16, %rsp
  pushq %rsi
  pushq %rdi

  xorq %r12, %r12 //; temp_array
  xorq %r13, %r13 //; temp_size
  xorq %r14, %r14 //; i
  xorq %r15, %r15 //; res

  //; %rdx key

  movq %rdi, %r12 //; array
	movq %rsi, %r13 //; size

  begin_iteration:
  cmp %r13, %r14
  jge end_loop

  leaq (%r12, %r14, 8), %rsi //; &arr[i]

  //; if (a[i] == key)
  cmpl (%rsi), %edx
  jne false
  addq 4(%rsi), %r15
  false:

  incq %r14

  jmp begin_iteration
  end_loop:

  movq	%r15, %rax

  cmpl $0 , %eax
  jne false2
  // Print call
  leaq STR(%rip), %rdi
  movb $0, %al
  callq _printf
  xorq %rax, %rax
  false2:

  popq %rdi
  popq %rsi
  add $16, %rsp
  popq %rbp
  ret


  /*

  //; [key][value]

  //; movl (%ecx, %esi, 4), %eax // A = *(C + 4*si) = C[si]


  //;addq %rax, %r15

  movl	(%rax,%rcx,8), %edx
  addl	-12(%rbp), %edx
  movl	%edx, -12(%rbp)

  //; if (a[i] == key)
  cmpq %rdx , %rsi
  jne false
  addq -4(%esi), %r15
  false:
  */
