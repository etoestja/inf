CFILE=main
TARGET=myshell
LIBRARY=myfifo

all: myshell
$(TARGET): lib$(LIBRARY).a $(CFILE).c
	gcc -L. $(CFILE).c -l$(LIBRARY) -o $(TARGET)
lib%.a: %.o
	ar rcs $@ $<
$(LIBRARY).o: $(LIBRARY).c
	gcc -c $(LIBRARY).c
clean:
	rm -rf *~
	rm -rf $(LIBRARY).o
	rm -rf lib$(LIBRARY).a
	rm -rf $(TARGET)
