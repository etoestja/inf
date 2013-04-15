CFILE=tester
TARGET=tester
LIBRARY=bsearch

all: library
library: lib$(LIBRARY).a
$(TARGET): lib$(LIBRARY).a $(CFILE).c
	gcc -m32 -O2 -L. $(CFILE).c -l$(LIBRARY) -o $(TARGET)
lib%.a: %.o
	ar rcs $@ $<
$(LIBRARY).o: $(LIBRARY).c
	gcc -m32 -O2 -c $(LIBRARY).c
tar:
	tar -cvvf $(LIBRARY).tar $(LIBRARY).h lib$(LIBRARY).a
clean:
	rm -rf *~
	rm -rf $(LIBRARY).o
	rm -rf lib$(LIBRARY).a
	rm -rf $(TARGET)
testrun:
	cat test | ./$(CFILE)

