#include <sys/types.h>
#include <sys/shm.h>
#include <errno.h>
#include <sys/sem.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int msqid;
    char pathname[]="main.c";
    key_t  key_mem, key_msg;

    struct mymsgbuf
    {
       long mtype;
    } mybuf, mybufrc;

    mybuf.mtype = 1515;

   int     *array;
   int     shmid;
   int     new = 1;
   int newm = 1;

    /* Create or attach message queue  */
    
    if((key_msg = ftok(pathname,0)) < 0){
      printf("Can\'t generate key\n");
      exit(-1);
    }
    
    if ((msqid = msgget(key_msg, 0666 | IPC_CREAT | IPC_EXCL)) < 0)
    {
        if(errno != EEXIST)
        {
            printf("Can\'t get msqid\n");
            exit(-1);
        }
        else
        {
            msqid = msgget(key_msg, 0666 | IPC_CREAT);
            newm = 0;
        }
    }


   if((key_mem = ftok(pathname,1)) < 0){
     printf("Can\'t generate key\n");
     exit(-1);
   }

   if((shmid = shmget(key_mem, 3*sizeof(int), 0666|IPC_CREAT|IPC_EXCL)) < 0)
   {
      if(errno != EEXIST)
      {
         printf("Can\'t create shared memory\n");
         exit(-1);
      }
      else
      {
         if((shmid = shmget(key_mem, 3*sizeof(int), 0)) < 0){
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


    if(newm)
    {
        printf("sending1\n");
        if(msgsnd(msqid, (struct msgbuf *) &mybuf, 0, 0) < 0)
        {
            printf("Can\'t send message to queue\n");
            msgctl(msqid, IPC_RMID, (struct msqid_ds *) NULL);
            exit(-1);
        }
    }

    printf("receiving\n");

    int len;

    if ((len = msgrcv(msqid, (struct msgbuf *) &mybufrc, 0, 0, 0)) < 0){
        printf("Can\'t receive message from queue\n");
        exit(-1);
    }

    printf("recevived\n");

    if(new)
    {
#ifdef D1
      array[0] += 1;
#else
      array[1] += 1;
#endif
      array[2] =  1;
   } else {
      array[2] += 1;
#ifdef D1
      sleep(10);
      array[0] += 1;
#else
      array[1] += 1;
#endif
   }

    printf("sending\n");
    
    if(msgsnd(msqid, (struct msgbuf *) &mybuf, 0, 0) < 0)
    {
        printf("Can\'t send message to queue\n");
        msgctl(msqid, IPC_RMID, (struct msqid_ds *) NULL);
        exit(-1);
    }
   printf
      ("Program 1 was spawn %d times, program 2 - %d times, total - %d times\n",
      array[0], array[1], array[2]);

   if(shmdt(array) < 0){
      printf("Can't detach shared memory\n");
      exit(-1);
   }

   return 0;
}
