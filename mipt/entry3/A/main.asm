global main

section .text
main:
mov eax, 4
mov ebx, 1
mov ecx, theString
mov edx, theLength
int 0x80

mov ebx, 0
mov eax, 1
int 0x80

section .data
theString: db "MIPT", 0xA
theLength equ $ - theString
