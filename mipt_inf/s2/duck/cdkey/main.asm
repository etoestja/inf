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
add eax, edx

cmp eax, 42

je tequal
    push string0
    jmp tend
tequal:
    push string1
tend:

call printf

push dword 0
call exit

section .data
formatin: db "%d%d", 0
string1: db "Accepted!", 0xA, 0
string0: db "Wrong key!", 0xA, 0

section .bss
a resd 1
b resd 1
