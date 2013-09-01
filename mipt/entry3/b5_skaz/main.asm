global main

extern exit
extern printf
extern scanf

section .text
main:
push dword a
push dword b
push dword formatin
call scanf

mov eax, dword [a]
sub eax, dword [b]
mov dword [a], eax

push eax
push dword formatout
call printf

push dword 0
call exit

section .data
formatin: db "%d%d", 0
formatout: db "%d", 0xA, 0

section .bss
a resd 1
b resd 1
