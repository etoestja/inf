#include <sys/types.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <sys/ipc.h>
#include <errno.h>
#include <sys/sem.h>
#include <unistd.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include "implementation.h"

#define PATHNAME "main.c"
#define NSEMS 1
#define KEY2 1

int eraseQueue;

typedef struct
{
    long mtype;
    int type;
} mymsg;

int msqid;
int semsInitial[NSEMS] = {0};
enum _SEMS {FULL};

#include "semaphores_lib.c"

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
             if(msgctl(msqid, IPC_RMID) < 0)
             {
                 printf("Can't rm queue\n");
                 exit(-1);
             }
             msqid = msgget(key, 0666 | IPC_CREAT);
         }
     }
}

void initWasher()
{
    erase = 1;
    getSemID();
    eraseQueue = 1;
    getMsqID();
}

void initCommon()
{
}

void initCleaner()
{
    erase = 0;
    getSemID();
    eraseQueue = 0;
    getMsqID();
}

int washSend(int dish, int doWash)
{
    struct sembuf buf0;

    buf0.sem_flg = 0;

    buf0.sem_num = FULL;
    buf0.sem_op = -1;

    //fprintf(stderr, "FULL=%d\n", semctl(semid, FULL, GETVAL, 0));

    if(semop(semid, &buf0, 1) < 0)
        printf("send full error\n");

    if(doWash)
        wash(dish, time[dish]);

#ifdef DEBUG
    printf("sending dish[%d]={%d}...\n", *freeSlot, dish);
#endif

    mymsg buf;
    buf.mtype = 1;
    buf.type = dish;
    if(msgsnd(msqid, (struct msgbuf*) &buf, sizeof(int), 0) < 0)
    {
        printf("Can't send message\n");
    }

#ifdef DEBUG
    printf("SEND OK!\n");
#endif
}

int receiveClean()
{
    struct sembuf buf0;

    buf0.sem_flg = 0;

    mymsg buf;
    ssize_t len;
    if((len = msgrcv(msqid, (struct msgbuf *) &buf,
                    sizeof(int), 0, 0)) < sizeof(int))
    {
        printf("Error reading message\n");
        exit(-1);
    }

    int res = buf.type;
    buf0.sem_num = FULL;
    buf0.sem_op = 1;
    if(semop(semid, &buf0, 1) < 0)
        printf("receive /full error\n");

#ifdef DEBUG
    printf("RCV OK!\n");
#endif

    if(res == TMAX)
        cleanedAll();

    clean(res, time[res]);
    return(res);
}
