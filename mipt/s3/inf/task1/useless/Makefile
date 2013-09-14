NAME=useless
SRC=main.c

all: bin/$(NAME)

bin/$(NAME):
	gcc -o bin/$(NAME) src/$(SRC)

clean:
	rm -rf bin/*

install:
	cp bin/$(NAME) /usr/bin
