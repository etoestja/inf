all: test main
main: integrate.o main.o function.o
	mpicc $^ -o $@
test: integrate.o test.o function.o
%.o : %.c
	mpicc -c $< -o $@
clean:
	rm *.o main test
