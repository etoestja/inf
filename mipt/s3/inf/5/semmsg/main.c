#include <sys/shm.h>
#include <errno.h>
#include <sys/ipc.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define SEM 1

int main()
{
    key_t  key;
    char pathname[] = "main.c";

    int *array, shmid, new = 1;

    if(smCreate(SEM) < 0)
    {
        printf("Can't create semaphore\n");
        exit(-1);
    }

    if((key = ftok(pathname,1)) < 0){
        printf("Can\'t generate key\n");
        exit(-1);
    }

    if((shmid = shmget(key, 3*sizeof(int), 0666|IPC_CREAT|IPC_EXCL)) < 0)
    {
        if(errno != EEXIST)
        {
            printf("Can\'t create shared memory\n");
            exit(-1);
        }
        else
        {
            if((shmid = shmget(key, 3*sizeof(int), 0)) < 0){
                printf("Can\'t find shared memory\n");
                exit(-1);
    	    }
            new = 0;
        }
    }

    if((array = (int *)shmat(shmid, NULL, 0)) == (int *)(-1))
    {
        printf("Can't attach shared memory\n");
        exit(-1);
    }

    smP(SEM);

    if(new)
    {
#ifdef D1
        array[0] += 1;
#else
        array[1] += 1;
#endif
        array[2] =  1;
    }
    else
    {
        array[2] += 1;
#ifdef D1
        sleep(10);
        array[0] += 1;
#else
        array[1] += 1;
#endif
    }

    smV(SEM);

    printf("Program 1 was spawn %d times, program 2 - %d times, total - %d times\n",
      array[0], array[1], array[2]);

   if(shmdt(array) < 0){
      printf("Can't detach shared memory\n");
      exit(-1);
   }

   return 0;
}
