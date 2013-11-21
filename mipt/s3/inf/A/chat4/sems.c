#include <sys/types.h>
#include <sys/stat.h>
#include <sys/ipc.h>
#include <errno.h>
#include <sys/sem.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "common.h"
#include "sems.h"

extern int semid;
key_t key;
    
int semsInitial[NSEMS] = {1, MSGMAX};

//           m for 0  m for 1 mutex N-msgs
//              0       0       1     N
enum _SEMS {MUTEX, FULL};

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
