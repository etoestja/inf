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
    
int semsInitial[NSEMS] = {1, CLIENTSMAX, 0};

void initSems();

void initSMS(const char *path, int keyP)
{
    key = ftok(path, keyP);
    if((semid = semget(key, NSEMS, 0666 | IPC_CREAT)) < -1)
    {
        fprintf(stderr, "Can't get sems!\n");
        exit(1);
    }
    initSems();
}
void initSems()
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
