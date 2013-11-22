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

extern int* freeSlot;
extern message* messages;

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
    freeSlot = (int*) ptr;
    messages = (message*) (ptr + sizeof(int));

}

void initAll()
{
    getKey();
    getSemID();
    map(FILENAME);
    if(ptr != NULL)
        mapInterpret();
    else
    {
        printf("ptr = NULL!\n");
        exit(-1);
    }

    if(fileCreatedNow)
    {
        *freeSlot = 0;
        int i;
        for(i = 0; i < MESSAGES; i++)
            messages[i].read = 1;
    }
}

void messageCopy(char* dest, char* src, ssize_t size)
{
    ssize_t i;
    for(i = 0; i < size; i++)
        dest[i] = src[i];
}

int messageCmp(char* msg, char* str, ssize_t size)
{
    size--;
    if(strlen(str) != size)
        return(1);
    int i;
    for(i = 0; i < size; i++)
        if(msg[i] != str[i])
            return(1);
    return(0);
}

int messageLastN(char* msg, ssize_t size)
{
    return(msg[size - 1] == '\n');
}
