section .data
    num1 db 0x1A
    num2 db 0x2B
    result db 0

section .text
global _start
_start:
    mov al, [num1]
    mov bl, [num2]
    add al, bl

    mov ah, 0
    mov bl, 10
    div bl
    add al, '0'
    mov [result], al
    mov al, ah
    add al, '0'
    mov [result+1], al

    mov eax, 4
    mov ebx, 1
    mov ecx, result
    mov edx, 2
    int 0x80

    mov eax, 1
    xor ebx, ebx
    int 0x80
