global main

extern exit
extern printf
extern scanf

section .text
main:
mov eax, 55
mov ebx, 10
lea edx, [eax + 8 * ebx]

push dword edx
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
