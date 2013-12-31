global main

extern exit
extern printf
extern scanf

section .text
main:
push dword a
push dword formatin
call scanf

mov eax, dword [a]
cdq
mov ebx, 0x14
idiv ebx

cmp edx, 0
je .endPlusOne
add eax, 1
.endPlusOne:

push eax
push dword formatout
call printf

push dword 0
call exit

section .data
formatin: db "%d", 0
formatout: db "%d", 0

section .bss
a resd 1
