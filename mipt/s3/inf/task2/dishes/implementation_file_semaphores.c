#include "implementation.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <sys/ipc.h>
#include <errno.h>
#include <sys/sem.h>
#include <unistd.h>
#define FILENAME "a_file"
#define PATHNAME "main.c"
#define NSEMS 3

int semid;
key_key;
int* freeSlot;
int* dishes;
void* ptr;
int semsInitial[NSEMS] = {0, 1, N};
enum _SEMS {EMPTY, MUTEX, FULL};

int* ptr;
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
    else
    {
        //created OK now
        int i;
        struct sembuf mybuf;
        for(i = 0; i < NSEMS; i++)
        {
            mybuf.sem_num = i;
            mybuf.sem_op  = semsInitial[i];
            mybuf.sem_flg = 0;
            if(semop(semid, &mybuf, 1) < 0){
                printf("Semaphore initialization failed i=%d value=%d semid=%d\n", i, semsInitial[i], semid);
                exit(-1);
            }  

        }

    }
}

void map()
{
    setFileSize();
    int existed = fileExists(FILENAME);
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
    dishes = (int*) (ptr + sizeof(int);
}

void initWasher(char* filename)
{
    getSemID();
    map();
    mapInterpret();
    *freeSlot = 0;
    for(i = 0; i < N; i++)
        dishes[i] = 0;
}

void initCleaner()
{
}

int send(int dish)
{
    struct sembuf bufMutex, buf0;
    bufMutex.sem_num = MUTEX;
    bufMutex.sem_op  = -1;
    bufMutex.sem_flg = 0;

    buf0.sem_flg = 0;
    
    buf0.sem_num = FULL;
    buf0.sem_op = -1;

    if(semop(semid, &buf0, 1) < 0)
        printf("send full error\n");

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
    *freeSlot = (*freeSlot + 1) % MESSAGES;

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

int receive()
{
    
            buf0.sem_num = ((myID == 0) ? EMPTY0 : EMPTY1);
            buf0.sem_op = -1;
            if(semop(semid, &buf0, 1) < 0)
            {
                printf("child empty error\n");
            }

            bufMutex.sem_op = -1;
            if(semop(semid, &bufMutex, 1) < 0)
                printf("child mutex error");

            int i;
            for(i = 0; i < MESSAGES; i++)
            {
                if((messages[i].read == 0) && (messages[i].sender == (hisID)))
                {
#ifdef DEBUG
                    char str[MSGLEN + 1];
                    messageCopy(str, messages[i].text, messages[i].size);
                    str[messages[i].size] = 0;
                    printf("free=%d, messages[%d]={%s}, %d: ", *freeSlot, i, str, messages[i].size);
#endif
                    messages[i].read = 1;
                    write(STDOUT_FILENO, messages[i].text, messages[i].size);
                    if(messageLastN(messages[i].text, messages[i].size))
                        write(STDOUT_FILENO, ">", 1);
                }
            }

            buf0.sem_num = FULL;
            buf0.sem_op = 1;
            if(semop(semid, &buf0, 1) < 0)
                printf("child /full error\n");

            bufMutex.sem_op = 1;
            if(semop(semid, &bufMutex, 1) < 0)
                printf("child /mutex error");

#ifdef DEBUG
            printf("RCV OK!\n");
#endif
}
