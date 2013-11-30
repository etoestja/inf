#ifndef MSGQUEUE_H
#define MSGQUEUE_H

#include <errno.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include "common.h"

typedef struct
{
    long mtype;
    int position;
    client cl;
} mymsg;

void initMSQ(char* path, int keyP);

#endif
