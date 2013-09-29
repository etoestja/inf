#include <sys/types.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

#define BUFSIZE 1024

int main()
{
    int fd1, fd2;
    size_t size;
    char string[BUFSIZE];

    fd1 = open("input.dat", O_RDONLY);
    fd2 = open("output.dat", O_WRONLY | O_CREAT);

    while((size = read(fd1, string, BUFSIZE)) > 0)
        write(fd2, string, size);

    close(fd1);
    close(fd2);

    return 0;
}
