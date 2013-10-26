all: chat3
chat3debug: main.c
	gcc -DDEBUG main.c -o chat3debug
chat3: main.c
	gcc main.c -o chat3
getkey: main.c
	gcc main.c -DGETKEY -o getkey
stop: getkey
	-killall -9 chat3
	-killall -9 chat3debug
	-./chat3_ipcrm
clean: stop
	-rm -rf chat3
	-rm -rf messages
	-rm -rf getkey
	-rm -rf chat3debug
