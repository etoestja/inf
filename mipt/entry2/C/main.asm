global main

extern exit
extern printf
extern scanf

section .text
main:

push a
push strin
call scanf

push b
push strin
call scanf

mov eax, [a]
mov ebx, [b]
cmp ebx, eax
jg .Greater
push ebx
jmp .End
.Greater:
push eax
.End:
push strout
call printf

push 0
call exit

section .data
strin: db "%d", 0
strout: db "%d", 0xA, 0

section .bss
a resd 1
b resd 1
