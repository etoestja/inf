all: test

bin: main.cpp
	g++ -o $@ $<
test: bin
	tester ./bin -o
