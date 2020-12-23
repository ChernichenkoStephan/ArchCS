.globl _main
_main:
   pushq %rbp
   movl $10, %esi
   movl $100, %edx
   callq _foo
   popq %rbp
   xor %eax, %eax
   ret
