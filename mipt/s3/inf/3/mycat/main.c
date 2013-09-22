#include <sys/types.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

#define BUFSIZE 1024

int main(int argc, char** argv)
{
    int fd;
    size_t size;
    char string[BUFSIZE];

    if(argc == 1)
    {
        printf("Usage: %s filename\n", argv[0]);
        return(1);
    }

    if((fd = open(argv[1], O_RDONLY)) < 0)
    {
        printf("Can't open file %s\n", argv[1]);
        return(1);
    }

    while((size = read(fd, string, BUFSIZE)) > 0)
        write(1, string, size);

    if(close(fd) < 0){
        printf("Can\'t close file %s\n", argv[1]);
    }

    return 0;
}
