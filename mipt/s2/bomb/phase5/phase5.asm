global main

extern exit
extern printf
extern scanf

section .text

explode_bomb:
push ebp
mov ebp,esp

push dword text
call printf
push 0
call exit


 de9:	push   ebp
 dea:	mov    ebp,esp
 dec:	push   esi
 ded:	push   ebx
 dee:	sub    esp,0x20
 df1:	lea    eax,[ebp-0x10]
 df4:	mov    DWORD [esp+0x8],eax
 df8:	lea    eax,[ebp-0xc]
 dfb:	mov    DWORD [esp+0x4],eax
 dff:	mov    DWORD [esp+0x0],format
 e0d:	call   scanf
 e12:	cmp    eax,0x1
 e15:	jg     e1c
 e17:	call   explode_bomb
 e1c:	mov    eax,DWORD [ebp-0xc]
 e1f:	and    eax,0xf
 e22:	mov    DWORD [ebp-0xc],eax
 e25:	cmp    eax,0xf
 e28:	je     e53
 e2a:	mov    ecx,0x0
 e2f:	mov    edx,0x0
 e34:	mov    ebx,array
 e39:	add    edx,0x1
 e3c:	mov    eax,DWORD [ebx+eax*4]
 e3f:	add    ecx,eax
 e41:	cmp    eax,0xf
 e44:	jne    e39
 e46:	mov    DWORD [ebp-0xc],eax
 e49:	cmp    edx,0xf
 e4c:	jne    e53
 e4e:	cmp    DWORD [ebp-0x10],ecx
 e51:	je     e58
 e53:	call   explode_bomb
 e58:	add    esp,0x20
 e5b:	pop    ebx
 e5c:	pop    esi
 e5d:	pop    ebp
 e5e:	ret    


main:
call de9

push dword textok
call printf

push 0
call exit

section .data
text: db "expl", 0xA, 0
textok: db "OK", 0xA, 0
format: db "%d %d", 0
array: dw 0xa, 0, 2, 0, 0xe, 0, 7, 0, 8, 0, 0xc, 0, 0xf, 0, 0xb, 0, 0, 0, 4, 0, 1, 0, 0xd, 0, 3, 0, 9, 0, 6, 0, 5, 0

section .bss
a resd 10
b resd 1
