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

struct timeb oldTime;

int main(int argc, char* argv[])
{
    char* serverName;
    int serverPort;
    int blockSize;

    if(argc <= 3)
    {
        printf("Usage: %s servername port blocksize\n", argv[0]);
        return(-1);
    }
    else
    {
        serverName = argv[1];
        serverPort = atoi(argv[2]);
        blockSize = atoi(argv[2]);
    }

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
    servAddr.sin_port = htons(serverPort);

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

    char *buf = malloc(sizeof(char) * blockSize);


    // parent
    setTime();
    client me;
    me.duration = 0;
    unsigned long long tDiff = 0, tLen = 0;
    long double taSpeed;
    const int T = 10;
    int t = 0;
    for(;;)
    {
        if(send(serverSocket, buf, blockSize, 0) < 0)
            fprintf(stderr, "child send failed!\n");
	tDiff = getTimeDifference();
	tLen += blockSize;

	if(tDiff > DMIN)
	{
		t++;
		me.dataLen += tLen;
		me.duration += tDiff;
		me.lastSpeed = tLen;
		me.lastSpeed /= tDiff;
		me.lastSpeed *= 1000;
		if(me.maxSpeed < me.lastSpeed)
			me.maxSpeed = me.lastSpeed;
		tLen = 0;
		setTime();
		if(t >= T)
		{
			taSpeed = me.dataLen;
    		    	taSpeed /= me.duration;
			taSpeed *= 1000;
	                fprintf(stderr, "curr %llf MB/s\tavg %llf MB/s\tmax %llfMB/s\n", me.lastSpeed / 1024 / 1024, taSpeed / 1024 / 1024, me.maxSpeed / 1024 / 1024);
			t = 0;
		}
	}
    }

    close(serverSocket);
    return(0);
}
