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

int myPipe[2];

int semsInitial[NSEMS] = {0};
enum _SEMS {FULL};

#include "semaphores_lib.c"

void initWasher()
{
    erase = 1;
    getSemID();
    close(myPipe[0]);
}

void initCommon()
{
    if(pipe(myPipe) < 0)
    {
        printf("Can't create pipe\n");
        exit(-1);
    }
}

void initCleaner()
{
    erase = 0;
    getSemID();
    close(myPipe[1]);
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

    write(myPipe[1], &dish, sizeof(int));

#ifdef DEBUG
    printf("SEND OK!\n");
#endif
}

int receiveClean()
{
    struct sembuf buf0;

    buf0.sem_flg = 0;

    int res;
    if(read(myPipe[0], &res, sizeof(int)) < sizeof(int))
    {
        printf("Can't read!\n");
    }

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
