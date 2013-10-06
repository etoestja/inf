CFILE=main
TARGET1=a
TARGET2=b
LIBRARY=semmsg

all: $(TARGET1) $(TARGET2)
$(TARGET1): lib$(LIBRARY).a $(CFILE).c
	gcc -DD1 -pthread -L. $(CFILE).c -l$(LIBRARY) -o $(TARGET1)
$(TARGET2): lib$(LIBRARY).a $(CFILE).c
	gcc -DD2 -pthread -L. $(CFILE).c -l$(LIBRARY) -o $(TARGET2)
lib%.a: %.o
	ar rcs $@ $<
$(LIBRARY).o: $(LIBRARY).c
	gcc -c $(LIBRARY).c
clean:
	rm -rf *~
	rm -rf $(LIBRARY).o
	rm -rf lib$(LIBRARY).a
	rm -rf $(TARGET1)
	rm -rf $(TARGET2)
