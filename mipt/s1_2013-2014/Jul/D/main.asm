global main

extern exit
extern printf
extern scanf

section .text
main:

push N
push strin
call scanf

mov ecx, 0

mov ebx, 0 ; ebx - counter
.Loop:
push dword a
push strin
call scanf
add ecx, dword [a]
inc ebx
cmp dword [N], ebx
jg .Loop

push ecx
push strout
call printf

push 0
call exit

section .data
strin: db "%d", 0
strout: db "%d", 0xA, 0

section .bss
N resd 1
a resd 1
