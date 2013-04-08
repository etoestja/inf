global main

section .text
main:
mov eax, dword [esp + 0x4]
dec eax
ret
