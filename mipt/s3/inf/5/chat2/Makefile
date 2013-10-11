CFILE=main
CFILE2=server
TARGET=chat
TARGET2=server

all: $(TARGET) $(TARGET2)
$(TARGET2): $(CFILE2).c common.h
	gcc -L. $(CFILE2).c -o $(TARGET2)
$(TARGET): $(CFILE).c common.h
	gcc -L. $(CFILE).c -o $(TARGET)
lib%.a: %.o
	ar rcs $@ $<
clean:
	rm -rf *~
	rm -rf $(TARGET)
	rm -rf $(TARGET2)
