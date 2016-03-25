all: main
main: main.o exact.o config.o
	mpicc -lm $^ -o $@
%.o : %.c
	mpicc -c $< -o $@
clean:
	rm -rf main *.o
