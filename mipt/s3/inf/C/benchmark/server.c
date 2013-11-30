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

client* clients;
void* ptr;

int main(int argc, char* argv[])
{
    int listenPort;
    int blockSize;

    if(argc <= 2)
    {
        printf("Usage: %s port blocksize\n", argv[0]);
        return(-1);
    }
    else
    {
        listenPort = atoi(argv[1]);
        blockSize = atoi(argv[2]);
    }

    int nport = htons((u_short) listenPort);
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

    initSMS("server.c", 0);
    initMPD("clients");
    initMSQ("server.c", 1);

    const int addrLen = sizeof(clntAddr);
    pid_t pid;

    int i;
    struct sembuf sbuf;

    if(!fork())
    {
        unsigned long long tDataLen, tDuration;
        for(;;)
        {
            for(i = 0; i < CLIENTSMAX; i++)
            {
                sbuf.sem_num = MUTEX;
                sbuf.sem_op = -1;
                sbuf.sem_flg = 0;

                //if(semop(semid, &sbuf, 1) < 0)
                //    fprintf(stderr, "stats <mutex> error!\n", i);

                tDataLen = clients[i].dataLen;
                tDuration = clients[i].duration;

                sbuf.sem_num = MUTEX;
                sbuf.sem_op = 1;
                sbuf.sem_flg = 0;

                //if(semop(semid, &sbuf, 1) < 0)
                //    fprintf(stderr, "stats </mutex> error!\n", i);

                if(tDuration > 0)
                    printf("%lfMB/s\t", tDataLen * 1.0 / tDuration);
            }
            sleep(1);
        }
    }

    size_t size;

    for(i = 0; ; i++)
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

            char* buf = malloc(blockSize);
            sbuf.sem_num = FULL;
            sbuf.sem_op = -1;
            sbuf.sem_flg = 0;

            if(semop(semid, &sbuf, 1) < 0)
                fprintf(stderr, "client %d init <full> error!\n", i);

            for(;;)
            {
                if(recv(clientSocket, buf, blockSize, 0) != blockSize)
                {
                    fprintf(stderr, "Client %d send wrong message\n", i);
                    return(-1);
                }

                sbuf.sem_num = MUTEX;
                sbuf.sem_op = -1;
                sbuf.sem_flg = 0;

                if(semop(semid, &sbuf, 1) < 0)
                    fprintf(stderr, "client %d fread <mutex> error!\n", i);

                clients[i].dataLen += blockSize;
                clients[i].duration += 1;

                sbuf.sem_op = 1;
                if(semop(semid, &sbuf, 1) < 0)
                    fprintf(stderr, "client %d fread </mutex> error!\n", i);
            }

            close(clientSocket);
            return(0);
        }
        close(clientSocket);
    }
}
