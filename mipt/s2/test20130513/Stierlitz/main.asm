global _start

section .text
_start:

mov eax, 3
mov ebx, 0
mov ecx, a
mov edx, 1
int 0x80

mov ax, [a]
or ax, 0b111
mov [a], ax

mov eax, 4
mov ebx, 1
mov ecx, a
mov edx, 1
int 0x80

mov ebx, 0
mov eax, 1
int 0x80

section .bss
a resb 1
