#include "common.h"
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <errno.h>
#include <unistd.h>
#include "sems.h"
#include "mmapped.h"
#include "msgqueue.h"

int semid;
int msqid;

int* freeSlot;
int* clientsN;
message* messages;

void* ptr;

int main(int argc, char* argv[])
{
    int nport = htons((u_short) SERVER_PORT);
    int serverSocket, clientSocket;
    if((serverSocket = socket(AF_INET, SOCK_STREAM, 0)) == -1)
    {
        perror("Can't get socket");
        return(-1);
    }

    struct sockaddr_in servAddr, clntAddr;

    bzero(&servAddr, sizeof(servAddr));
    servAddr.sin_family = AF_INET;
    servAddr.sin_addr.s_addr = INADDR_ANY;
    servAddr.sin_port = nport;

    if(bind(serverSocket, (struct sockaddr *) &servAddr, sizeof(servAddr)) == -1)
    {
        perror("Can't bind");
        return(-1);
    }

    if(listen(serverSocket, CLIENTS_N) == -1)
    {
        perror("Can't listen!");
        return(-1);
    }

    initSMS();
    initMPD();
    initMSQ();

    const int addrLen = sizeof(clntAddr);
    pid_t pid;

    char buf[MSGLEN];
    size_t size;

    int i;

    for(i = 1; ; i++)
    {
        bzero(&clntAddr, addrLen);
        if((clientSocket = accept(serverSocket, (struct sockaddr *) &clntAddr, (socklen_t*) (&addrLen))) == -1)
        {
            perror("Can't accept");
            return(-1);
        }
        fprintf(stderr, "Accepted client %s id=%d\n", inet_ntoa(clntAddr.sin_addr), i);

        if((pid = fork()) == -1)
        {
            perror("Can't fork");
            return(-1);
        }

        if(pid == 0)
        {
            close(serverSocket);

            mymsg mbuf;
            struct sembuf sbuf, sbuf1;

            sbuf.sem_num = MUTEX;
            sbuf.sem_flg = 0;
            sbuf.sem_op = -1;

            if(semop(semid, &sbuf, 1) < 0)
                fprintf(stderr, "client %d init <mutex> error!\n", i);

            (*clientsN)++;

            sbuf.sem_op = 1;

            if(semop(semid, &sbuf, 1) < 0)
                fprintf(stderr, "client %d init </mutex> error!\n", i);

            
            if(fork())
            {
                int j;
                int first = 1;
                while((size = recv(clientSocket, buf, MSGLEN, 0)) > 0)
                {
                    fprintf(stderr, "Client %d: ", i);
                    write(STDOUT_FILENO, buf, size);

                    sbuf1.sem_num = FULL;
                    sbuf1.sem_op = -1;
                    sbuf1.sem_flg = 0;
                    if(semop(semid, &sbuf1, 1) < 0)
                        fprintf(stderr, "client %d FULL-- error!", i);


                    sbuf.sem_num = MUTEX;
                    sbuf.sem_op = -1;
                    sbuf.sem_flg = 0;

                    if(semop(semid, &sbuf, 1) < 0)
                        fprintf(stderr, "client %d <mutex> error!", i);

                    messageCopy(messages[*freeSlot].text, buf, size);
                    messages[*freeSlot].size = size;

                    messages[*freeSlot].leftread = *clientsN - 1;
                    messages[*freeSlot].sender = i;
                    messages[*freeSlot].first = first;

                    if(first)
                        first = 0;
                    if(messageLastN(buf, size)) first = 1;

                    mbuf.position = *freeSlot;

                    *freeSlot = (*freeSlot + 1) % MSGMAX;

                    if(*clientsN == 1)
                    {
                        sbuf1.sem_num = FULL;
                        sbuf1.sem_op = 1;
                        sbuf1.sem_flg = 0;
                        if(semop(semid, &sbuf1, 1) < 0)
                            fprintf(stderr, "client %d back FULL++ error!", i);
                    }

                    sbuf.sem_op = 1;
                    sbuf.sem_flg = 0;

                    if(semop(semid, &sbuf, 1) < 0)
                        fprintf(stderr, "client %d </mutex> error!", i);

                    for(j = 1; j <= *clientsN; j++)
                    {
                        if(j != i)
                        {
                            mbuf.mtype = j;
                            if(msgsnd(msqid, &mbuf, sizeof(mbuf), 0) < 0)
                            {
                                fprintf(stderr, "client %d error broadcasting to %d!\n", i, j);
                            }
                        }
                    }
                }
            }
            else
            {
                broadcastMessage bm;
                while(msgrcv(msqid, (mymsg* ) (&mbuf), sizeof(buf), i, 0))
                {
                    sbuf.sem_num = MUTEX;
                    sbuf.sem_op = -1;
                    sbuf.sem_flg = 0;

                    if(semop(semid, &sbuf, 1) < 0)
                        fprintf(stderr, "client %d broadcast <mutex> error!\n", i);

                    messageCopy(bm.text, messages[mbuf.position].text, messages[mbuf.position].size);
                    bm.sender = messages[mbuf.position].sender;
                    bm.size = messages[mbuf.position].size;
                    bm.first = messages[mbuf.position].first;

                    messages[mbuf.position].leftread--;

                    if(messages[mbuf.position].leftread == 0)
                    {
                        sbuf1.sem_num = FULL;
                        sbuf1.sem_op = 1;
                        sbuf1.sem_flg = 0;
                        if(semop(semid, &sbuf1, 1) < 0)
                            fprintf(stderr, "client %d broadcast FULL++ error!\n", i);
                    }

                    sbuf.sem_op = 1;
                    if(semop(semid, &sbuf, 1) < 0)
                        fprintf(stderr, "client %d broadcast </mutex> error!\n", i);

                    send(clientSocket, &bm, bm.size + 3 * sizeof(int), 0);
                }
            }

            //            sbuf.sem_num = MUTEX;
            //            sbuf.sem_flg = 0;
            //            sbuf.sem_op = -1;

            //            if(semop(semid, &sbuf, 1) < 0)
            //                fprintf(stderr, "client %d death <mutex> error!\n", i);

            //            *clientsN--;

            //            sbuf.sem_op = 1;

            //            if(semop(semid, &sbuf, 1) < 0)
            //                fprintf(stderr, "client %d death </mutex> error!\n", i);

            close(clientSocket);
            return(0);
        }
        close(clientSocket);
    }
}
