global main

extern exit
extern printf

section .text
main:
push dword mytextformat
push dword mytext
call printf

push dword 0
call exit

section .data
mytext: db "Liberté, égalité, fraternité!", 0xA, 0
mytextformat: db "%s", 0

