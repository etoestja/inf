CFILE=main
TARGET=useless
LIBRARY=parseargs

all: bin/$(TARGET)

lib/lib%.a: lib/%.o
	ar rcs $@ $<

lib/$(LIBRARY).o: lib/$(LIBRARY).c
	gcc -c lib/$(LIBRARY).c -o lib/$(LIBRARY).o

clean:
	rm -rf *.deb
	rm -rf lib/$(LIBRARY).o
	rm -rf lib/lib$(LIBRARY).a
	rm -rf bin/*
	rm -rf $(TARGET)
	rm -rf *.tgz

bin/$(TARGET): src/$(CFILE.c) lib/lib$(LIBRARY).a
	gcc -I ./lib -L./lib -l$(LIBRARY) -o bin/$(TARGET) src/$(CFILE).c

install:
	cp bin/$(TARGET) /usr/bin

deb-install:
	sudo checkinstall --maintainer=etoestja@yandex.ru --nodoc -y
