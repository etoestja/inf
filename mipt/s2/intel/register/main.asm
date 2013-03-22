global main

extern exit
extern printf
extern scanf

section .text
main:
push dword a
push dword format
call scanf

mov eax, dword [a]
shl eax, 16
shr eax, 16

push eax
push dword format
call printf

push dword 0
call exit

section .data
format: db "%u", 0

section .bss
a resd 1
