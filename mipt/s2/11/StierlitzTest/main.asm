[ORG 0x7C00]

global _start

;section .text
_start:
mov eax, 4
mov ebx, 1
mov ecx, theString
mov edx,9; theLength
int 0x80

mov ebx, 0
mov eax, 1
int 0x80

;section .data
theString: db "Stierlitz"
theLength equ $ - theString

times 1212310 - ($ - $$) db 0

