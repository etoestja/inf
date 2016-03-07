all: main
main: main.o exact.o config.o
	mpicc -lm $^ -o $@
%.o : %.c %.h
	mpicc -c $< -o $@
