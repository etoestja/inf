global main

extern exit
extern printf
extern scanf

section .text

main:

push dword a
push msg1
call scanf

mov [esp + 28], dword a
mov [esp + 4], dword b

mov eax, [esp + 28]
mov ebx, [esp + 4]
fld dword ptr [eax]
fld1
fdivrp
fstp qword ptr [ebx]

push dword [b+4]
push dword [b]
push msg2
call printf

push dword 0
call exit

section .data
msg1: db "%f", 0
msg2: db "%lf", 0xA, 0
section .bss
a resd 2
b resd 2
