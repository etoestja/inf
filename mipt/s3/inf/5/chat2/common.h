#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>

#define PATHNAME "server.c"
#define KEY2 0
#define MSGLEN 100
#define MAXLEN (100 + sizeof(int))
#define TOSERVER 1
#define MINLEN (3 * sizeof(int))

enum mType{MTEXT, MHELLO, MBYE, MCOMES, MLEAVES};

typedef struct
{
    long mtype;
    int type;
    int sourcePID;
    int destPID;
    char message[MSGLEN];
} msgbuf;
