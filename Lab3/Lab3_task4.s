.section __DATA,__data
str:
  .asciz "x = %d;\ny = %d.\n"

/*
  Сonvention
    volitile registers:
      eax, edx, esi, edi, ecx, ebx
    input:
      edi, esi, edx
    output:
      ebx, ecx
*/

.section __TEXT,__text
foo:
   movl	%edx, %eax              // eax = c
   imul %esi, %eax              // eax = c * b
   add  %edi, %eax              // eax = a + c * b
   movl	%eax, %ebx              // output x

   movl	%edx, %eax              // eax = c
   imul %esi, %eax              // eax = c * b
   imul $-1, %eax               // eax = (- 1) * c * b
   add %edi, %eax               // eax = a - c * b
   movl	%eax, %ecx              // output y

   ret // return to coller

.section __TEXT,__text
.globl _main
_main:
  pushq %rbp // init
  pushq %rbx // init

  movl	$5, %edi                // edi = a
  movl	$2, %esi                // esi = b X arg
  movl	$2, %edx                // edx = c Y arg
  // x = 5 + 4 = 9
  // y = 5 - 4 = 1
  callq	foo

  // Print part
  movl %ebx, %esi                // edi = x
  movl %ecx, %edx                // esi = y
  movq %rsp, %rbp
  movq str@GOTPCREL(%rip), %rdi
  movb $0, %al
  popq %rbx // init
  callq _printf
  popq %rbp
  movl $0x2000001, %eax
  syscall
