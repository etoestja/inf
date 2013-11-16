#include "common.h"
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <errno.h>

int main(int argc, char* argv[])
{
    int nport = htons((u_short) SERVER_PORT);
    int serverSocket;
    if((serverSocket = socket(AF_INET, SOCK_STREAM, 0)) == -1)
    {
        perror("Can't get socket\n");
        return(-1);
    }

    struct sockaddr_in servAddr, clntAddr;

    bzero(&servAddr, sizeof(servAddr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = nport;


}
