.section .data
str:
	.ascii "asdasdasd\000"	
.section .text
.global main
.extern printf
.extern exit
main:                       @ Необязательная строка, обозначающая начало программы
	movw r0, #:lower16:str
	movt r0, #:upper16:str
	blx printf

	mov r0, #112
	blx exit
