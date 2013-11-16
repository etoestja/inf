all: server client
client: common.o client.o
	gcc common.o client.o -o $@
server: common.o server.o
	gcc common.o server.o -o $@
.o:
	gcc $<.c -o $@
