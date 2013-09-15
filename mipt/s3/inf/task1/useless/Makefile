CFILE=main
TARGET=useless
LIBRARY=parseargs

all: bin/$(TARGET)

lib/lib%.a: lib/%.o
	ar rcs $@ $<

lib/$(LIBRARY).o: lib/$(LIBRARY).c
	gcc -m32 -c lib/$(LIBRARY).c -o lib/$(LIBRARY).o

clean:
	rm -rf *.deb
	rm -rf lib/$(LIBRARY).o
	rm -rf lib/lib$(LIBRARY).a
	rm -rf bin/*
	rm -rf $(TARGET)

bin/$(TARGET): src/$(CFILE.c) lib/lib$(LIBRARY).a
	gcc -m32 -I ./lib -L./lib -l$(LIBRARY) -o bin/$(TARGET) src/$(CFILE).c

install:
	cp bin/$(NAME) /usr/bin
