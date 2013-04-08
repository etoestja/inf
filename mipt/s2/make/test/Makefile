all: solution
solution: main.o
	gcc -m32 main.o -o solution
main.o: main.asm
	nasm -felf main.asm
clean:
	rm main.o
	rm solution
test:
	cat file | ./solution -verbose
