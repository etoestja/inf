global main

extern exit
extern printf
extern scanf

section .text

main:

rdtsc
push dword eax
push fout
call printf

pop ebp
leave
ret

main:
call print_rdtsc
call print_rdtsc

push 0
call exit

section .data
fout: db "%u", 0xA, 0

section .bss
a resd 1
b resd 1
