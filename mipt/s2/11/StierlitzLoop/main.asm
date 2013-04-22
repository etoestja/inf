global _start

section .text
_start:
mov ecx, theString
printLoop:
mov eax, 4
mov ebx, 1
mov edx, 1
int 0x80
inc ecx
cmp byte [ecx], 0
jne printLoop

mov ebx, 0
mov eax, 1
int 0x80

section .data
theString: db "Stierlitz", 0
theLength equ $ - theString
