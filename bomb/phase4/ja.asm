global main

extern exit
extern printf
extern scanf

section .text
main:
mov eax, -1
cmp eax, 0x7
ja Lja
push dword msgNJA
jmp end
Lja:
push dword msgJA
end:

call printf

push 0
call exit

section .data
msgJA: db "JA", 0xA, 0
msgNJA: db "NJA", 0xA, 0

section .bss
a resd 1
b resd 1
