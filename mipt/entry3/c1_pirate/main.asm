global main

extern exit
extern printf
extern scanf

section .text
main:
push dword K
push dword M
push dword N
push dword formatin
call scanf

mov eax, dword [K]
imul eax, dword [M] ; given number in eax
cdq
idiv dword [N] ; resN in eax
mov dword [resN], eax

;push dword [resN]
;push formatdebug
;call printf

mov eax, dword [K]
cmp eax, dword [resN]
jg .pushYesStr
push noStr
jmp .endPush
.pushYesStr:
push yesStr
.endPush:
call printf

push dword 0
call exit

section .data
formatin: db "%d%d%d", 0
yesStr: db "YES", 0xA, 0
noStr: db "NO", 0xA, 0
;formatdebug: db "%d", 0xA, 0

section .bss
N resd 1
M resd 1
K resd 1
resN resd 1
