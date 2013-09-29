#include <sys/types.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

#define BUFSIZE 1024

int main(int argc, char** argv)
{
    int fd1, fd2;
    size_t size;
    char string[BUFSIZE];

    if(argc < 3)
        return(1);

    umask(0);
    fd1 = open(argv[1], O_RDONLY);
    fd2 = open(argv[2], O_WRONLY | O_CREAT, 0666);

    while((size = read(fd1, string, BUFSIZE)) > 0)
        write(fd2, string, size);

    close(fd1);
    close(fd2);

    return 0;
}
