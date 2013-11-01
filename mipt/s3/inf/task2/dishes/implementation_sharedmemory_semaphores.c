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

#define KEY2 1
#define PATHNAME "main.c"
#define NSEMS 3

int shmid;

int* freeSlot;
int* dishes;
void* ptr;
int semsInitial[NSEMS] = {0, 1, 0};
enum _SEMS {EMPTY, MUTEX, FULL};

#include "semaphores_lib.c"

int fileSize;

void setFileSize()
{
    fileSize = N * sizeof(int) + sizeof(int);
}

void map()
{
    setFileSize();
    if((key = ftok(PATHNAME, 0)) < 0)
    {
        printf("Can\'t generate key\n");
        exit(-1);
    }

    if((shmid = shmget(key, fileSize, 0666 | IPC_CREAT)) < 0)
    {
        printf("Can't get shmid\n");
        exit(-1);
    }

    if((ptr = (void*)shmat(shmid, NULL, 0)) == ((int *)(-1)))
    {
        printf("Can't attach shared memory\n");
        exit(-1);
    }
}

void mapInterpret()
{
    freeSlot = (int*) ptr;
    dishes = (int*) (ptr + sizeof(int));
}

void initWasher()
{
    erase = 1;
    getSemID();
    map();
    mapInterpret();
    *freeSlot = 0;
    int i;
    for(i = 0; i < N; i++)
        dishes[i] = -1;
}

void initCleaner()
{
    erase = 0;
    getSemID();
    map();
    mapInterpret();
}

int washSend(int dish, int doWash)
{
    struct sembuf bufMutex, buf0;
    bufMutex.sem_num = MUTEX;
    bufMutex.sem_op  = -1;
    bufMutex.sem_flg = 0;

    buf0.sem_flg = 0;

    buf0.sem_num = FULL;
    buf0.sem_op = -1;

    //fprintf(stderr, "FULL=%d\n", semctl(semid, FULL, GETVAL, 0));

    if(semop(semid, &buf0, 1) < 0)
        printf("send full error\n");

    if(doWash)
        wash(dish, time[dish]);

    bufMutex.sem_op = -1;

    if(semop(semid, &bufMutex, 1) < 0)
        printf("send mutex error\n");

#ifdef DEBUG
    printf("sending dish[%d]={%d}...\n", *freeSlot, dish);
#endif

    dishes[*freeSlot] = dish;

#ifdef DEBUG
    printf("freeSlot: %d -> ", *freeSlot);
#endif
    *freeSlot = (*freeSlot + 1) % N;

#ifdef DEBUG
    printf("%d\n", *freeSlot);
#endif

    buf0.sem_num = EMPTY;
    buf0.sem_op = +1;
    if(semop(semid, &buf0, 1) < 0)
    {
        printf("send /empty error\n");
        exit(-1);
    }

    bufMutex.sem_op = 1;

    if(semop(semid, &bufMutex, 1) < 0)
    {
        printf("parent /mutex error\n");
    }
#ifdef DEBUG
    printf("SEND OK!\n");
#endif
}

int receiveClean()
{
    struct sembuf bufMutex, buf0;
    bufMutex.sem_num = MUTEX;
    bufMutex.sem_op  = -1;
    bufMutex.sem_flg = 0;

    buf0.sem_flg = 0;

    buf0.sem_num = EMPTY;
    buf0.sem_op = -1;
    if(semop(semid, &buf0, 1) < 0)
    {
        printf("receive empty error\n");
    }

    bufMutex.sem_op = -1;
    if(semop(semid, &bufMutex, 1) < 0)
        printf("receive mutex error");

    int i;
    int res = TMAX;
    for(i = 0; i < N; i++)
    {
        if(dishes[i] >= 0 && dishes[i] != TMAX)
        {
            res = dishes[i];
            dishes[i] = -1;
            break;
        }
    }

    buf0.sem_num = FULL;
    buf0.sem_op = 1;
    if(semop(semid, &buf0, 1) < 0)
        printf("receive /full error\n");

    bufMutex.sem_op = 1;
    if(semop(semid, &bufMutex, 1) < 0)
        printf("receive /mutex error");

#ifdef DEBUG
    printf("RCV OK!\n");
#endif

    if(res == TMAX)
        cleanedAll();

    clean(res, time[res]);
    return(res);
}

void initCommon()
{

}
