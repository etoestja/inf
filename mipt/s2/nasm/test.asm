global main

extern exit
extern printf
extern scanf

section .text

main:

je l1
jne l2

l1:
l2:


section .data
msg1: db "%d%d", 0
msg2: db "%d", 0xA, 0

section .bss
a resd 1
b resd 1
