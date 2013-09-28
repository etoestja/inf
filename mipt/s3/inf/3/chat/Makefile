CFILE=main
TARGET=chat

all: $(TARGET)
$(TARGET): $(CFILE).c
	gcc -L. $(CFILE).c -o $(TARGET)
lib%.a: %.o
	ar rcs $@ $<
clean:
	rm -rf *~
	rm -rf $(TARGET)
