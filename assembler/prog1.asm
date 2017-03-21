section .data
    msg db "Hello World!"
    len equ $-msg
    num dw 15

section .text
    global _start

_start:
    ;mov eax, 3
    ;mov ebx, 1
    ;mov ecx, num
    ;mov edx, 5
    ;int 80h

Loop:
    mov eax, 4
    mov ebx, 1
    mov ecx, num
    mov edx, 1
    int 80h

    dec dword [num]
    jnz Loop

    mov eax, 1
    mov ebx, 0
    int 80h