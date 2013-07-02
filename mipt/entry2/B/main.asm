global main

extern exit
extern printf
extern scanf

section .text
main:

push N
push strin
call scanf

push K
push strin
call scanf

mov eax, [K]
mov ebx, [N]
sub eax, ebx

push eax
push strout
call printf

push 0
call exit

section .data
strin: db "%d", 0
strout: db "%d", 0xA, 0

section .bss
N resd 1
K resd 1
