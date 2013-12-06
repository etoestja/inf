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

void getMsqID(char* path, int keyP)
{
    /* Create or attach message queue  */
     if((key = ftok(path, keyP)) < 0)
     {
         fprintf(stderr, "Can't get key, exiting\n");
         exit(-1);
     }
     if((msqid = msgget(key, 0666 | IPC_CREAT)) >= 0)
     {
         if(eraseQueue)
         {
             if(msgctl(msqid, IPC_RMID, NULL) < 0)
             {
                 fprintf(stderr, "Can't rm queue\n");
                 exit(-1);
             }
             msqid = msgget(key, 0666 | IPC_CREAT);
         }
     }
     else
         fprintf(stderr, "Can't get msqueue!\n");
}

void initMSQ(char* path, int keyP)
{
    eraseQueue = 1;
    getMsqID(path, keyP);
}
