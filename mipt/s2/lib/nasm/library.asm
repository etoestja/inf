global subroutine

section .text

subroutine:
push ebp
mov ebp, esp
push ebx

mov eax, dword [ebp + 0x8]
mov ebx, dword [ebp + 0xc]

cmp eax, ebx
jg lsigned
sub eax, ebx
jmp lend
lsigned:
add eax, ebx
lend:

pop ebx
pop ebp
ret
