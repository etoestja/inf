all: main
main: main.o stderr.o integrate.o int_threaded.o timedist.o
	gcc -lpthread -lm $^ -o $@
%.o : %.c %.h
	gcc -c $< -o $@
clean:
	rm -rf main *.o
