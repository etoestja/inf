all: program
	echo done

program: cudacode.o
	gcc -std=c99 -L/usr/local/cuda/lib64 -I/usr/local/cuda/include  -lcuda -lcudart main.c kernel.o 

cudacode.o:
	nvcc -c kernel.cu 

clean: 
	rm -rf *.o a.out