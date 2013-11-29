#include "common.h"
#include <sys/types.h>
#include <sys/socket.h>
#include <assert.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

    initSMS("server.c", 0);
    initMPD("clients");
    initMSQ("server.c", 1);

    const int addrLen = sizeof(clntAddr);
    pid_t pid;

    char buf[sizeof(client)];
    size_t size;

    mymsg tMsg;

    client tClBuf;

    struct sembuf sbuf, sbuf1;

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

            if(fork())
            {
                for(;;)
                {
                    if(msgrcv(msqid, &tMsg, sizeof(mymsg), i, 0) == sizeof(mymsg))
                    {
                        fprintf(stderr, "Sending data to client %d\n", i);
                        if(send(clientSocket, &(tMsg.cl), sizeof(client), 0) < 0)
                            fprintf(stderr, "client %d error sending about %d\n", i, tMsg.cl.id);
                        fprintf(stderr, "Sending data to client %d finished\n", i);

                    }
                    else
                        fprintf(stderr, "client %d got wrong message\n", i);
                }
            }
            else
            {
                for(;;)
                {
                if(recv(clientSocket, &tClBuf, sizeof(client), 0) != sizeof(client))
                {
                    fprintf(stderr, "Error getting from i=%d\n", i);
                    continue;
                }
                fprintf(stderr, "Got message from i=%d\n", i);

                if(tClBuf.action == ADD)
                {
                    fprintf(stderr, "Adding %d:%d...\n", i, tClBuf.port);
                    tClBuf.id = i;
                    tClBuf.direction = NEW2OLD;
                    strcpy(tClBuf.ip, inet_ntoa(clntAddr.sin_addr));

                    sbuf1.sem_num = FULL;
                    sbuf1.sem_op = -1;
                    sbuf1.sem_flg = 0;

                    if(semop(semid, &sbuf1, 1) < 0)
                        fprintf(stderr, "client %d add <full> error!\n", i);

                    sbuf.sem_num = MUTEX;
                    sbuf.sem_op = -1;
                    sbuf.sem_flg = 0;

                    if(semop(semid, &sbuf, 1) < 0)
                        fprintf(stderr, "client %d init <mutex> error!\n", i);

                    int j;
                    for(j = 0; j < CLIENTSMAX; j++)
                        if(clients[j].port != -1)
                        {
                            fprintf(stderr, "Adding %d, looking at %d\n", i, clients[j].id);
                            tMsg.cl = clients[j];
                            tMsg.cl.direction = OLD2NEW;
                            tMsg.mtype = i;
                            if(msgsnd(msqid, &tMsg, sizeof(mymsg), 0) < 0)
                                fprintf(stderr, "client %d error telling about %d\n", i, tMsg.cl.id);

                            tMsg.cl = tClBuf;
                            tMsg.cl.direction = NEW2OLD;
                            tMsg.mtype = clients[j].id;
                            if(msgsnd(msqid, &tMsg, sizeof(mymsg), 0) < 0)
                                fprintf(stderr, "client %d error telling to %d\n", i, tMsg.cl.id);
                        }


                    for(j = 0; j < CLIENTSMAX; j++)
                    {
                        if(clients[j].port == -1)
                            break;
                    }

                    assert(j < CLIENTSMAX);

                    clients[j] = tClBuf;

                    fprintf(stderr, "Adding %d: got place %d\n", i, j);

                    sbuf.sem_op = 1;
                    if(semop(semid, &sbuf, 1) < 0)
                        fprintf(stderr, "client %d init </mutex> error!\n", i);

                    tMsg.cl = tClBuf;
                    tMsg.cl.direction = NEW2NEW;
                    tMsg.mtype = i;
                    if(msgsnd(msqid, &tMsg, sizeof(mymsg), 0) < 0)
                        fprintf(stderr, "client %d error telling to himself\n", i);
                    fprintf(stderr, "Adding %d finished\n", i);
                }
                }
            }
            return(0);
        }
        close(clientSocket);
    }
}
