section .data
array db '1','2','3','4'
n db 4
sum db 0

section .text
global _start

_start:
    mov esi, array
    mov cl, [n]
    xor bl, bl

loop_start:
    lodsb
    sub al, '0'
    add bl, al
    loop loop_start

    mov [sum], bl

    mov eax, 1
    xor ebx, ebx
    int 0x80
