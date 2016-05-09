CFLAGS = -lpthread -lrt -lm
CC     = gcc

all: main
main: diff_single.o exact.o main.o constants.o stderr.o diff_threaded.o diff_threaded_call.o timedist.o
	$(CC) $(CFLAGS) -o $@ $^
%.o : %.c *.h
	$(CC) -c $(CFLAGS) $< -o $@
clean:
	rm -rf *.o main
