global main

extern exit
extern printf
extern scanf

section .text
main:
push msg1
call printf
push 0
call exit

section .data
msg1: db "test", 0
