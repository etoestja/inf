all: tester
tester:  tester.c
	gcc -m32 -L. tester.c -lbsearch -o tester
clean:
	rm -rf main.o
	rm -rf tester
test: test1
	cat test1 | ./solution

