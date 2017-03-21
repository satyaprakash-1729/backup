section .text
   global _start        ;must be declared for using gcc
    
_start:                 ;tell linker entry point
   mvi ebx 100
   lxi ehx 12288
   mvi eax 0
L1:
   add [num]
   inx ehx
   dcr ebx
   jnz L1
sta 16384
hlt