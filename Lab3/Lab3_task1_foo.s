.globl _foo
_foo:
   movl %edi, %eax
   imul $3, %eax
   add $1, %eax
   ret
