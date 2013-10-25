#include <sys/types.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <sys/ipc.h>
#include <errno.h>
#include <sys/sem.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "../lseek.h"

#define MSGLEN  10
#define NAMELEN 10

typedef struct
{
    char text[MSGLEN];
} message;



#define USERS 2
#define FILENAME "messages"
#define MESSAGES 10
#define FILESIZE (MESSAGES * sizeof(message) + (USERS + 1) * sizeof(int))

// for SV
#define PATHNAME "main.c"

#define NSEMS 3

int   semid;
key_t key;
    
int myID, hisID;

int* lastMsg;
message* messages;

void* ptr;

// mutex empty (Nmsg) full (N-Nmsg)
//  1     0             N
int semsInitial[NSEMS] = {1, 0, MESSAGES};

enum _SEMS = {MUTEX, EMPTY, FULL};

void getHisID()
{
    if(myID == 1)
        hisID = 0;
    else hisID = 1;
}

void getKey()
{
    key = ftok(PATHNAME, 0);
}
 
void getSemID()
{
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
    
int fileExists(char* filename)
{
    int fd = open(filename, O_RDONLY);
    close(fd);
    return(fd != -1);
}

void map(char* filename)
{
    int existed = fileExists(filename);
	int fd = open(filename, O_RDWR | O_CREAT, 0666);

    ptr = NULL;

	if(fd == -1)
        return;

    if(!existed)
        ftruncate(fd, FILESIZE);

    ptr = (void*) mmap(NULL, FILESIZE, PROT_WRITE | PROT_READ, MAP_SHARED, fd, 0);

    close(fd);

	if(ptr == MAP_FAILED)
        ptr = NULL;
}

void mapInterpret()
{
    lastMsg = (int*) ptr;
    write
    messages = (message*) (ptr + (sizeof(int) * (USERS + 1)));

}

void initAll()
{
    getKey();
    getSemID();
    map(FILENAME);
    if(ptr != NULL)
        mapInterpret();
    else
    {
        printf("ptr = NULL!\n");
        exit(-1);
    }
}

int main()
{
    message tMsg;
    ssize_t size;

    struct sembuf bufMutex, buf0;
    bufMutex.sem_num = MUTEX;
    bufMutex.sem_op  = -1;
    bufMutex.sem_flg = 0;

    buf0.sem_flg = 0;

    if(fork())
    {
        // stdin > file
        initAll();
        for(;;)
        {
            if((size = read(STDIN_FILENO, tMsg.text, MSGLEN)) > 0)
            {
                //waiting until there is space
                buf0.sem_num = FULL;
                buf0.sem_op = -1;

                if(semop(semid, &buf0, 1) < 0)
                    printf("parent full error\n");

                bufMutex.sem_op = -1;

                if(semop(semid, &bufMutex, 1) < 0)
                    printf("parent mutex error\n");


            }
        }

/*        for(;;)
            if((size = read(STDIN_FILENO, tMsg.text, MSGLEN)) > 0)
            {
                arr[position++] = tMsg;
                write(fdR, 
            }*/
    }
    else
    {
        initAll();
/*        for(;;)
            if((size = read(fdR, buf, BUFSIZE)) > 0)
                write(STDOUT_FILENO, buf, size);*/
    }

}
