CFLAGS=-m32
all: server client
client: common.o client.o
	gcc $(CFLAGS) common.o client.o -o $@
server: common.o server.o
	gcc $(CFLAGS) common.o server.o -o $@
.o: common.h
	gcc $(CFLAGS) $<.c -o $@
clean:
	rm -rf *.o
	rm -rf server client
	rm -rf *~
