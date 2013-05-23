global main

extern exit
extern printf
extern scanf

section .text
main:

mov eip, 0

push 0
call exit

section .data
msg1: db "test", 0
