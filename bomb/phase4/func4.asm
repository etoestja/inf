global main

extern exit
extern printf
extern scanf

section .text
ba0: push   ebp
ba1:	mov    ebp,esp
ba3:	sub    esp,0x18
ba6:	mov    dword [ebp-0x8],ebx
ba9:	mov    DWORD [ebp-0x4],esi
bac:	mov    edx,DWORD [ebp+0x8]
baf:	mov    eax,DWORD [ebp+0xc]
bb2:	mov    ebx,DWORD [ebp+0x10]
bb5:	mov    ecx,ebx
bb7:	sub    ecx,eax
bb9:	mov    esi,ecx
bbb:	shr    esi,0x1f
bbe:	lea    ecx,[esi+ecx*1]
bc1:	sar    ecx,1
bc3:	add    ecx,eax
bc5:	cmp    ecx,edx
bc7:	jle    be0
bc9:	sub    ecx,0x1
bcc:	mov    DWORD [esp+0x8],ecx
bd0:	mov    DWORD [esp+0x4],eax
bd4:	mov    DWORD [esp],edx
bd7:	call   ba0
bdc:	add    eax,eax
bde:	jmp    c00
be0:	mov    eax,0x0
be5:	cmp    ecx,edx
be7:	jge    c00
be9:	mov    DWORD [esp+0x8],ebx
bed:	add    ecx,0x1
bf0:	mov    DWORD [esp+0x4],ecx
bf4:	mov    DWORD [esp],edx
bf7:	call   ba0
bfc:	lea    eax,[eax+eax*1+0x1]
c00:	mov    ebx,DWORD [ebp-0x8]
c03:	mov    esi,DWORD [ebp-0x4]
c06:	mov    esp,ebp
c08:	pop    ebp
c09:	ret    

main:
push dword a
push dword format
call scanf

push 14
push 0
push dword [a]
call ba0

push eax
push format
call printf

push 0
call exit

section .data
format: db "%d", 0

section .bss
a resd 1
b resd 1
