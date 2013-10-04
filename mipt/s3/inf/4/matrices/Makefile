CFILE=main
TARGET=matricesMul
LIBRARY=matrices

all: $(TARGET)
$(TARGET): lib$(LIBRARY).a $(CFILE).c
	gcc -DMULTPRINT -DMULTTHREADS -pthread -L. $(CFILE).c -l$(LIBRARY) -o $(TARGET)
lib%.a: %.o
	ar rcs $@ $<
$(LIBRARY).o: $(LIBRARY).c
	gcc -pthread -c $(LIBRARY).c
clean:
	rm -rf *~
	rm -rf $(LIBRARY).o
	rm -rf lib$(LIBRARY).a
	rm -rf $(TARGET)
