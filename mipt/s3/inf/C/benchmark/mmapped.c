#include <sys/types.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <sys/ipc.h>
#include <errno.h>
#include <sys/sem.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "mmapped.h"
#include "common.h"

extern client* clients;

extern void* ptr;

int fileCreatedNow;

int fileExists(char* filename)
{
    int fd = open(filename, O_RDONLY);
    close(fd);
    return(fd != -1);
}

void map(char* filename)
{
    int existed = fileExists(filename);
	int fd = open(filename, O_RDWR | O_CREAT, 0666);

    ptr = NULL;
    fileCreatedNow = 0;

	if(fd == -1)
        return;

    if(!existed)
    {
        ftruncate(fd, FILESIZE);
        fileCreatedNow = 1;
    }

    ptr = (void*) mmap(NULL, FILESIZE, PROT_WRITE | PROT_READ, MAP_SHARED, fd, 0);

    close(fd);

	if(ptr == MAP_FAILED)
        ptr = NULL;
}

void mapInterpret()
{
    clients = (client*) (ptr);
}

void initMPD(char* filename)
{
    map(filename);
    if(ptr != NULL)
        mapInterpret();
    else
    {
        printf("ptr = NULL!\n");
        exit(-1);
    }

    if(fileCreatedNow)
    {
        int i;
        for(i = 0; i < CLIENTSMAX; i++)
        {
            clients[i].duration = 0;
            clients[i].dataLen = 0;
	    clients[i].maxSpeed = 0;
	    clients[i].lastSpeed = 0;
        }
    }
}
