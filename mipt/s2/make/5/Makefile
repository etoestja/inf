NAME=solution
OBJECT=main.o

all: $(NAME)
$(NAME): $(OBJECT)
	gcc -m32 $(OBJECT) -o $@
%.o: %.asm
	nasm -felf $<
clean:
	rm -rf *.o $(NAME)
