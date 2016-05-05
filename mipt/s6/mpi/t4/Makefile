CFLAGS = -lpthread -lrt -lm
CC     = gcc

all: main
main: diff_single.o exact.o main.o constants.o
	$(CC) -o $@ $^
%.o : %.c
	$(CC) -c $(CFLAGS) $< -o $@
clean:
	rm -rf *.o main
