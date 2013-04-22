global printLoop

section .text
printLoop:
mov eax, 4
mov ebx, 1
mov edx, 1
int 0x80
inc ecx
cmp byte [ecx], 0
jne printLoop
