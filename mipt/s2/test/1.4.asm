global main

extern exit
extern printf
extern scanf

section .text

main:

mov eax, 123
lea ecx, [0xffffffff + eax]

push ecx
push msg2
call printf

push dword 0
call exit

section .data
msg1: db "%d%d", 0
msg2: db "%d", 0xA, 0

section .bss
a resd 1
b resd 1
