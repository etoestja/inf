global main

extern exit
extern printf
extern scanf

section .text

main:
mov dword [esp], 0x12345678
cmp byte [esp], 0x01
je llittle
push sbig
jmp lend
llittle:
push slittle
lend:

call printf

push 0
call exit

section .data
sbig: db "Big-endian", 0xA, 0
slittle: db "Little-endian", 0xA, 0

section .bss
a resd 1
b resd 1
