#include <errno.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/ipc.h>
#include "msgqueue.h"
#include <sys/msg.h>
#include <stdio.h>

int eraseQueue;

extern int msqid;

key_t key;

void getMsqID()
{
    /* Create or attach message queue  */
     if((key = ftok(PATHNAME, KEY2)) < 0)
     {
         printf("Can't get key, exiting\n");
         exit(-1);
     }
     if((msqid = msgget(key, 0666 | IPC_CREAT)) < 0)
     {
         if(eraseQueue)
         {
             if(msgctl(msqid, IPC_RMID, NULL) < 0)
             {
                 printf("Can't rm queue\n");
                 exit(-1);
             }
             msqid = msgget(key, 0666 | IPC_CREAT);
         }
     }
}

void initMSQ()
{
    eraseQueue = 1;
    getMsqID();
}
