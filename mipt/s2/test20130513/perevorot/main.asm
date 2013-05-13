global main

extern exit
extern printf
extern scanf

section .text

main:

push dword N
push sinf
call scanf

;eax - temp
;ebx - current index
mov ebx, 0
.inLoop:
lea eax, [arr + 4 * ebx]
push eax
push sinf
call scanf
inc ebx
cmp dword [N], ebx
jg .inLoop

;ebx - index + 1
mov ebx, [N]
.outLoop:
lea eax, [arr + 4 * ebx - 4]
push dword [eax]
push souf
call printf
dec ebx
cmp ebx, 0
jg .outLoop

push dword 0
call exit

section .data
sinf: db "%d", 0
souf: db "%d ", 0
section .bss
N resd 1
arr resd 1000000
