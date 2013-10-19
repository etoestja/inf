#include <sys/types.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "../lseek.h"

#define MSGLEN  10
#define NAMELEN 10

typedef struct
{
    long id;
    int position;
};

typedef struct
{
    char text[MSGLEN];
    char sender[NAMELEN];
} message;

#define FILENAME "messages"
#define MESSAGES 10
#define FILESIZE (MESSAGES * sizeof(message))

int position = 0;
char* arr;

int fileExists(char* filename)
{
    int fd = open(filename, O_RDONLY);
    close(fd);
    return(fd != -1);
}

char* map(char* filename)
{
    int existed = fileExists(filename);
	int fd = open(filename, O_RDWR | O_CREAT, 0666);

	if(fd == -1)
        return(NULL);

    if(!existed)
        ftruncate(fd, FILESIZE);

    char* ptr = (char*) mmap(NULL, FILESIZE, PROT_WRITE | PROT_READ, MAP_SHARED, fd, 0);

    close(fd);

	if(ptr == MAP_FAILED)
        return(NULL);

    return(ptr);
}

int main()
{
    arr = map(FILENAME);
    message tMsg;

    if(fork())
        for(;;)
            if((size = read(STDIN_FILENO, tMsg.text, MSGLEN)) > 0)
            {
                arr[position++] = tMsg;
                write(fdR, 
            }
    else
        for(;;)
            if((size = read(fdR, buf, BUFSIZE)) > 0)
                write(STDOUT_FILENO, buf, size);

}
