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

int semid;

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

    const int addrLen = sizeof(clntAddr);
    pid_t pid;

    char buf[MSGLEN];
    size_t size;

    for(;;)
    {
        bzero(&clntAddr, addrLen);
        if((clientSocket = accept(serverSocket, (struct sockaddr *) &clntAddr, (socklen_t*) (&addrLen))) == -1)
        {
          perror("Can't accept"); 
          return(-1);
        }
        fprintf(stderr, "Accepted client %s\n", inet_ntoa(clntAddr.sin_addr));
        /* Создадим процесс для работы с клиентом */
        if((pid = fork()) == -1)
        {
          perror("Can't fork"); 
          return(-1);
        }
        if(pid == 0)
        {
            close(serverSocket);
            
            while((size = recv(clientSocket, buf, MSGLEN, 0)) > 0)
                write(STDOUT_FILENO, buf, size);

            close(clientSocket);
            return(0);
        }
        close(clientSocket);
    }
}
