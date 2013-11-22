#ifndef MSGQUEUE_H
#define MSGQUEUE_H

#include <errno.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#define PATHNAME "server.c"
#define KEY2 1

typedef struct
{
    long mtype;
    int position;
} mymsg;

void initMSQ();

#endif
