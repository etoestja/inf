#include <sys/types.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "lseek.h"

char* map(char* filename, int newsize)
{
	int fd = open(filename, O_RDWR | O_CREAT, 0666);

	if(fd == -1)
        return(NULL);

    int length = 0;

    if(newsize >= 0)
    {
        length = newsize;
        ftruncate(fd, newsize);
    }
    else
        length = fileLen(filename);

    char* ptr = (char*) mmap(NULL, length, PROT_WRITE | PROT_READ, MAP_SHARED, fd, 0);

    close(fd);

	if(ptr == MAP_FAILED)
        return(NULL);

    return(ptr);
}

#define DEBUG

int main(int argc, char** argv)
{
    if(argc < 3)
        return(-1);

    int l = fileLen(argv[1]);
    char* src = map(argv[1], -1);
    char* dest = map(argv[2], l);

#ifdef DEBUG
    printf("LEN = %d\n", l);
    printf("src = %p\n", src);
    printf("dest = %p\n", dest);
#endif

    if(src == NULL || dest == NULL)
    {
        printf("ERROR\n");
        return(-1);
    }

    int i;
    for(i = 0; i < l; i++)
        dest[i] = src[i];

    munmap((void *)src, l);
    munmap((void *)dest, l);
    return(0);
}
