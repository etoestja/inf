global _start

section .text
_start:
mov eax, 3
mov ebx, 0
mov ecx, instring
mov edx, 10
int 0x80

;mov eax, 4
;mov ebx, 1
;mov ecx, instring
;mov edx, 10
;int 0x80
mov ecx, printLoop
jmp printLoop

mov ebx, 0
mov eax, 1
int 0x80

section .data
theString: db "Stierlitz"

section .bss
instring resb 100
