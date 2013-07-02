global main

extern exit
extern printf
extern scanf

section .text
main:

push N
push strin
call scanf

mov dword [a], 0
.loopa:
mov eax, [a]
lea ecx, [arr + 4 * eax]
push ecx
push strin
call scanf

mov eax, [a]
inc eax
mov [a], eax
cmp eax, [N]
jl .loopa


mov dword [a], 0
.loopb:
mov eax, [a]
lea ecx, [arr + 4 * eax]
push dword [ecx]
push strout
call printf

mov eax, [a]
inc eax
mov [a], eax
cmp eax, [N]
jl .loopb

mov dword [a], 0
.loopc:
mov eax, [a]
lea ecx, [arr + 4 * eax]
push dword [ecx]
push strout
call printf

mov eax, [a]
inc eax
mov [a], eax
cmp eax, [N]
jl .loopc

mov eax, 0
call exit


section .data
strin: db "%d", 0
strout: db "%d ", 0

section .bss
N resd 1
a resd 1
arr resd 1005
