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

#define MSGN 1000

typedef struct
{
    char text[MSGN];
    int len;
} message;

extern client* clients;
extern void* ptr;
int semid, msqid;

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

    int serverInfoSocket, clientSocket[CLIENTSMAX], listenSocket, rxSocket;
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
        sbuf.sem_id = CLIENTREADY;
        sbuf.sem_flg = 0;

        if(semop(semid, &sbuf, 1) < 0)
            fprintf(stderr, "Error waiting!\n");

        message tMsg;
        if((size = read(STDIN_FILENO, tMsg.text, MSGN)) > 0)
        {

        }
    }
    else
    {
        if(!fork())
        {
            for(;;)
            {
                else
                {
                    for(;;)
                    {
                        bzero(&clntAddr, addrLen);
                        if((rxSocket = accept(listenSocket, (struct sockaddr *) &clntAddr, (socklen_t*) (&addrLen))) == -1)
                        {
                            perror("Can't accept");
                            return(-1);
                        }
                        fprintf(stderr, "Accepted client %s\n", inet_ntoa(clntAddr.sin_addr));
                        if(!fork())
                        {
                            for(;;)
                            {
                                message tMsg;
                                if(recv(rxSocket, &tMsg, sizeof(message), 0) != sizeof(message))
                                    fprintf("can't receive from p2p client!\n");
                                fprintf(stderr, "[%d]: ", tMsg.id);
                                write(STDOUT_FILENO, tMsg.text, tMsg.len);
                            }
                            return(0);
                        }
                    }
                }
            }

            close(serverInfoSocket);
        }
