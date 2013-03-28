global main

extern exit
extern printf
extern scanf

section .text

main:

push dword 130
push fout
call printf

push 0
call exit

section .data
fout: db "%u", 0xA, 0

section .bss
a resd 1
b resd 1
