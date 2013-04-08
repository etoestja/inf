global main

extern exit

section .text
main:

mov eax, dword [esp + 0x4]
sub eax, 1

push eax
call exit

