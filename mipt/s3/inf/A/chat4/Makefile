CFLAGS=-m32
all: server client
client: sems.o common.o client.o
	gcc $(CFLAGS) common.o client.o -o $@
server: sems.o common.o server.o
	gcc $(CFLAGS) common.o server.o sems.o -o $@
.o: common.h
	gcc $(CFLAGS) $<.c -o $@
clean:
	rm -rf *.o
	rm -rf server client
	rm -rf *~
