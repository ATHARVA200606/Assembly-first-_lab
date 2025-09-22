section .data
    num1 db 40
    num2 db 5
    quotient db 0
    remainder db 0

section .text
global _start
_start:
    mov al, [num1]
    mov bl, [num2]
    xor ah, ah      ; clear AH for 8-bit division
    div bl          ; AL = quotient, AH = remainder
    mov [quotient], al
    mov [remainder], ah

    mov eax, 1
    xor ebx, ebx
    int 0x80

