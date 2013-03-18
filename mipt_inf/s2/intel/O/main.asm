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
jc lOverflow
mov eax, nostring
jmp lEnd
lOverflow:
mov eax, yesstring
lEnd:

push eax
push dword formatout
call printf

push dword 0
call exit

section .data
formatin: db "%u%u", 0
formatout: db "%s", 0xA, 0
yesstring: db "YES", 0
nostring: db "NO", 0

section .bss
a resd 1
b resd 1
outstring resd 1
