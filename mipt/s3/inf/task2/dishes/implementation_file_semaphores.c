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

#define FILENAME "a_file"
#define PATHNAME "main.c"
#define NSEMS 3

int erase;

union semun {
    int              val;    /* Value for SETVAL */
    struct semid_ds *buf;    /* Buffer for IPC_STAT, IPC_SET */
    unsigned short  *array;  /* Array for GETALL, SETALL */
    struct seminfo  *__buf;  /* Buffer for IPC_INFO
                                          (Linux-specific) */
};


int semid;
key_t key;
int* freeSlot;
int* dishes;
void* ptr;
int semsInitial[NSEMS] = {0, 1, 0};
enum _SEMS {EMPTY, MUTEX, FULL};

int fileSize;

int fileLen(char* filename)
{
    return(lseek(open(filename, O_RDONLY), 0, SEEK_END));
}

int fileExists(char* filename)
{
    int fd = open(filename, O_RDONLY);
    close(fd);
    return(fd != -1);
}

void setFileSize()
{
    fileSize = N * sizeof(int) + sizeof(int);
}

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

void map()
{
    setFileSize();
    int existed = fileExists(FILENAME);
    if(existed && fileLen(FILENAME) != fileSize)
        existed = 0;
    int fd = open(FILENAME, O_RDWR | O_CREAT, 0666);

    ptr = NULL;

    if(fd == -1)
        return;

    if(!existed)
        ftruncate(fd, fileSize);

    ptr = (void*) mmap(NULL, fileSize, PROT_WRITE | PROT_READ, MAP_SHARED, fd, 0);

    close(fd);

    if(ptr == MAP_FAILED)
        ptr = NULL;
    if(ptr == NULL)
    {
        printf("Can't map file!\n");
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
        dishes[i] = 0;
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
