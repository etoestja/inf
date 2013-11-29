#include "common.h"
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <strings.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include "sems.h"
#include "mmapped.h"
#include "msgqueue.h"

#define MSGN 1000
#define MSGNEWCLIENTTYPE CLIENTSMAX

typedef struct
{
    long mtype;
    char text[MSGN];
    int id;
    int len;
} message;

client* clients;
void* ptr;
int semid, msqid;

void communicateWithClient(int id, int cSocket, int getID)
{
    message tMsg;
    if(getID)
    {
        fprintf(stderr, "Awaiting first packet...\n");
        if(recv(cSocket, &tMsg, sizeof(message), 0) != sizeof(message))
            fprintf(stderr, "can't receive from p2p client!\n");
        id = tMsg.id;
        fprintf(stderr, "set id to %d\n");
    }

    if(fork())
    {
        for(;;)
        {
            if(msgrcv(msqid, &tMsg, sizeof(message), id, 0) != sizeof(message))
            {
                fprintf(stderr, "Comm %d msq rcv err\n", id);
            }

            if(send(cSocket, &tMsg, sizeof(message), 0) < 0)
                fprintf(stderr, "Comm %d can't transmit\n", id);
        }
    }
    else
    {
        message tMsg;
        for(;;)
        {
            if(recv(cSocket, &tMsg, sizeof(message), 0) != sizeof(message))
                fprintf(stderr, "can't receive from p2p client!\n");
            fprintf(stderr, "[%d]: ", id);
            write(STDOUT_FILENO, tMsg.text, tMsg.len);
        }
    }
}

int main(int argc, char* argv[])
{
    char* serverName;
    int myPort;

    pid_t myPID = getpid();

    if(argc <= 1)
    {
        printf("Usage: %s servername myport\n", argv[0]);
        return(-1);
    }
    else
    {
        serverName = argv[1];
        myPort = atoi(argv[1]);
    }

    const int myPIDMLen = 10;

    char* clientsF1 = "clients";
    char* clientsF2 = malloc((myPIDMLen + 1) * sizeof(char));
    sprintf(clientsF2, "%d", myPID);

    char* clientsF = malloc(sizeof(char) * (strlen(clientsF1) + strlen(clientsF2) + 1));
    clientsF[0] = 0;
    strcat(clientsF, clientsF1);
    strcat(clientsF, clientsF2);

    initSMS("client.c", 2 * myPID);
    initMSQ("client.c", 2 * myPID + 1);
    initMPD(clientsF);

    struct hostent *ht;
    if((ht = (struct hostent*) gethostbyname(serverName)) == NULL)
    {
        perror("Can't gethostbyname");
        return(-1);
    }

    struct sockaddr_in servAddr, listenAddr, clntAddr;

    bzero(&servAddr, sizeof(servAddr));
    bcopy(ht->h_addr, &servAddr.sin_addr, ht->h_length);
    servAddr.sin_family = ht->h_addrtype;
    servAddr.sin_port = htons(SERVER_PORT);

    int serverInfoSocket, clientSocket, listenSocket;
    if((serverInfoSocket = socket(AF_INET, SOCK_STREAM, 0)) == -1)
    {
        perror("Can't socket()");
        return(-1);
    }

    if(connect(serverInfoSocket, (struct sockaddr *) &servAddr, sizeof(servAddr)) == -1)
    {
        perror("Can't connect to server");
        return(-1);
    }


    if((listenSocket = socket(AF_INET, SOCK_STREAM, 0)) == -1)
    {
        perror("Can't get socket");
        return(-1);
    }

    int listenPort = htons((u_short) myPort);

    bzero(&listenAddr, sizeof(listenAddr));
    listenAddr.sin_family = AF_INET;
    listenAddr.sin_addr.s_addr = INADDR_ANY;
    listenAddr.sin_port = listenPort;

    if(bind(listenSocket, (struct sockaddr *) &listenAddr, sizeof(listenAddr)) == -1)
    {
        perror("Can't bind");
        return(-1);
    }

    if(listen(listenSocket, CLIENTS_N) == -1)
    {
        perror("Can't listen!");
        return(-1);
    }

    if(fork())
    {
        fprintf(stderr, "Please wait, connecting...\n");
        struct sembuf sbuf;
        sbuf.sem_op = -1;
        sbuf.sem_num = CLIENTREADY;
        sbuf.sem_flg = 0;

        if(semop(semid, &sbuf, 1) < 0)
            fprintf(stderr, "Error waiting!\n");

        message tMsg;
        int i;
        ssize_t size;
        for(;;)
        {
            if((size = read(STDIN_FILENO, tMsg.text, MSGN)) > 0)
            {
                tMsg.len = size;
                sbuf.sem_op = -1;
                sbuf.sem_num = MUTEX;
                sbuf.sem_flg = 0;

                if(semop(semid, &sbuf, 1) < 0)
                    fprintf(stderr, "Transmit msg queue can't mutex!\n");

                for(i = 0; i < CLIENTSMAX; i++)
                {
                    if(clients[i].id != -1)
                    {
                        tMsg.mtype = clients[i].id;
                        if(!msgsnd(msqid, &tMsg, sizeof(message), 0))
                            fprintf(stderr, "Transmit msg queue error\n");
                    }
                }

                sbuf.sem_op = 1;
                sbuf.sem_num = MUTEX;
                sbuf.sem_flg = 0;

                if(semop(semid, &sbuf, 1) < 0)
                    fprintf(stderr, "Transmit msg queue can't /mutex!\n");
            }
        }
    }
    else
    {
        if(!fork())
        {
            client tC;
            int i;
            struct sembuf sbuf;
            for(;;)
            {
                if(recv(serverInfoSocket, &tC, sizeof(client), 0) == sizeof(client))
                {
                    if(tC.action == ADD)
                    {
                        sbuf.sem_num = FULL;
                        sbuf.sem_op = -1;
                        sbuf.sem_flg = 0;

                        if(semop(semid, &sbuf, 1) < 0)
                            fprintf(stderr, "From server full error\n");

                        sbuf.sem_num = MUTEX;
                        sbuf.sem_op = -1;
                        sbuf.sem_flg = 0;

                        if(semop(semid, &sbuf, 1) < 0)
                            fprintf(stderr, "From server mutex error\n");

                        for(i = 0; i < CLIENTSMAX; i++)
                        {
                            if(clients[i].id == -1)
                                break;
                        }


                        assert(i < CLIENTSMAX);

                        clients[i] = tC;

                        sbuf.sem_num = MUTEX;
                        sbuf.sem_op = 1;
                        sbuf.sem_flg = 0;

                        if(semop(semid, &sbuf, 1) < 0)
                            fprintf(stderr, "From server /mutex error\n");

                        if(tC.direction == NEW2NEW)
                        {
                            sbuf.sem_num = CLIENTREADY;
                            sbuf.sem_op = 1;
                            sbuf.sem_flg = 0;

                            if(semop(semid, &sbuf, 1) < 0)
                                fprintf(stderr, "From server clientready error\n");
                        }

                        if(tC.direction == OLD2NEW && !fork())
                        {
                            struct hostent *hta;
                            if((hta = (struct hostent*) gethostbyname(tC.ip)) == NULL)
                                fprintf(stderr, "Can't gethostbyname\n");

                            bzero(&clntAddr, sizeof(clntAddr));
                            bcopy(ht->h_addr, &clntAddr.sin_addr, ht->h_length);
                            servAddr.sin_family = ht->h_addrtype;
                            servAddr.sin_port = htons(tC.port);

                            if((clientSocket = socket(AF_INET, SOCK_STREAM, 0)) == -1)
                                fprintf(stderr, "Can't socket()\n");

                            if(connect(clientSocket, (struct sockaddr *) &clntAddr, sizeof(clntAddr)) == -1)
                                fprintf(stderr, "Can't connect to server\n");

                            
                            message tMsg;
                            tMsg.id = tC.id;

                            if(send(clientSocket, &tMsg, sizeof(message), 0) < 0)
                                fprintf(stderr, "Add %d can't transmit first packet\n", tC.id);
                            communicateWithClient(tC.id, clientSocket, 0);
                        }
                    }
                }
            }
        }
        else
        {
            int addrLen = sizeof(clntAddr);
            for(;;)
            {
                bzero(&clntAddr, addrLen);
                if((clientSocket = accept(listenSocket, (struct sockaddr *) &clntAddr, (socklen_t*) (&addrLen))) == -1)
                {
                    perror("Can't accept");
                    return(-1);
                }
                fprintf(stderr, "Accepted client %s\n", inet_ntoa(clntAddr.sin_addr));
                if(!fork())
                {
                    communicateWithClient(0, clientSocket, 1);
                }
            }
        }
    }

    close(serverInfoSocket);
}
