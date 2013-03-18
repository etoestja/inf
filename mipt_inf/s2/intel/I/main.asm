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

fld qword [b]
fld qword [a]

fdivrp

fstp qword [a]

push dword [a+4]
push dword [a]
push dword formatout
call printf

push dword 0
call exit

section .data
formatin: db "%lf%lf", 0
formatout: db "%lf", 0xA, 0

section .bss
a resd 2
b resd 2
