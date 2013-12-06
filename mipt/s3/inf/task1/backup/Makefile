CFILE=main
TARGET=backup

all: bin/$(TARGET)

clean:
	rm -rf *.deb
	rm -rf bin/*
	rm -rf *.tgz

bin/$(TARGET): src/$(CFILE.c)
	gcc -o bin/$(TARGET) src/$(CFILE).c

install:
	cp bin/$(TARGET) /usr/bin

deb-install: all
	sudo checkinstall --maintainer=etoestja@yandex.ru --nodoc -y
