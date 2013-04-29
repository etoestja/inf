.section .text
.global main
.extern printf
.extern exit
main:                       @ Необязательная строка, обозначающая начало программы
	mov r0, #112
	blx exit
