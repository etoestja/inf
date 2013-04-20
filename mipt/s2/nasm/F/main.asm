global main

extern exit
extern printf
extern scanf

section .text
main:
push dword b
push dword a
push dword formatin
call scanf

mov eax, dword [a]
mov edx, dword [b]

cmp eax, edx
js noSwap
mov eax, edx
noSwap:

push eax
push dword formatout
call printf

push dword 0
call exit

section .data
formatin: db "%d%d", 0
formatout: db "%d", 0

section .bss
a resd 1
b resd 1
