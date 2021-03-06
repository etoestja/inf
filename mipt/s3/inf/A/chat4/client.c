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

int main(int argc, char* argv[])
{
    char* serverName;

    if(argc <= 1)
    {
        printf("Usage: %s servername\n", argv[0]);
        return(-1);
    }
    else
        serverName = argv[1];

    struct hostent *ht;
    if((ht = (struct hostent*) gethostbyname(serverName)) == NULL)
    {
        perror("Can't gethostbyname");
        return(-1);
    }

    struct sockaddr_in servAddr;

    bzero(&servAddr, sizeof(servAddr));
    bcopy(ht->h_addr, &servAddr.sin_addr, ht->h_length);
    servAddr.sin_family = ht->h_addrtype;
    servAddr.sin_port = htons(SERVER_PORT);

    int serverSocket;
    if((serverSocket = socket(AF_INET, SOCK_STREAM, 0)) == -1)
    {
        perror("Can't socket()");
        return(-1);
    }

    if(connect(serverSocket, (struct sockaddr *) &servAddr, sizeof(servAddr)) == -1)
    {
        perror("Can't connect to server");
        return(-1);
    }

    pid_t cpid = fork();
    if(cpid < 0)
    {
        perror("Can't fork");
        return(-1);
    }

    size_t size;
    char buf[MSGLEN];

    if(cpid == 0)
    {
        // child
        broadcastMessage bm;
        for(;;)
            if((size = recv(serverSocket, &bm, MSGLEN + 3 * sizeof(int), 0)) > 0)
            {
                if(bm.first)
                    fprintf(stderr, "[%d]: ", bm.sender);
                write(STDOUT_FILENO, bm.text, bm.size);
            }
    }
    else
    {
        // parent
        for(;;)
            if((size = read(STDIN_FILENO, buf, MSGLEN)) > 0)
                if(send(serverSocket, buf, size, 0) < 0)
                    printf("child send failed!");
    }

    close(serverSocket);
}
