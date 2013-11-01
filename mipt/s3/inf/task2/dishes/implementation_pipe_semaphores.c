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

int erase;

int myPipe[2];

union semun {
    int              val;    /* Value for SETVAL */
    struct semid_ds *buf;    /* Buffer for IPC_STAT, IPC_SET */
    unsigned short  *array;  /* Array for GETALL, SETALL */
    struct seminfo  *__buf;  /* Buffer for IPC_INFO
                                          (Linux-specific) */
};


int semid;
key_t key;
int semsInitial[NSEMS] = {0};
enum _SEMS {FULL};

void getKey()
{
    key = ftok(PATHNAME, 0);
}

void getSemID()
{
    semsInitial[FULL] = N;
    //printf("initial2=%d\n", semsInitial[2]);
    getKey();
    if((semid = semget(key, NSEMS, 0666 | IPC_CREAT | IPC_EXCL)) < 0)
    {
        if(errno == EEXIST)
        {
            if((semid = semget(key, NSEMS, 0666 | IPC_CREAT)) < 0)
            {
                printf("Can't create semaphore set II\n");
                exit(-1);
            }
        }
        else
        {
            printf("Can\'t create semaphore set I\n");
            exit(-1);
        }
    }
    if(erase)
    {
        //created OK
        int i;
        union semun semopts;

        for(i = 0; i < NSEMS; i++)
        {
            semopts.val = semsInitial[i];
            if(semctl(semid, i, SETVAL, semopts) < 0)
            {
                fprintf(stderr, "Can't semctl!\n");
                exit(-1);
            }
        }
    }
}

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
