#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#define BUFSIZE 10

int main(int argc, char** argv)
{
    int fdW, fdR;
    size_t size;
    char *nameW, *nameR;

    if(argc < 3)
    {
        printf("Usage: %s pipeWrite pipeRead\n", argv[0]);
        return(-1);
    }

    nameW = argv[1];
    nameR = argv[2];

    umask(0);

    if(mknod(nameW, S_IFIFO | 0666, 0) < 0 && errno != EEXIST)
    {
        printf("Can\'t create write FIFO\n");
        exit(-1);
    }

    if(mknod(nameR, S_IFIFO | 0666, 0) < 0 && errno != EEXIST)
    {
        printf("Can\'t create read FIFO\n");
        exit(-1);
    }

    if((fdW = open(nameW, O_RDWR | O_NONBLOCK | O_NDELAY)) < 0){
        printf("Can\'t open FIFO for writing\n");
        exit(-1);
    }

    if((fdR = open(nameR, O_RDWR | O_NONBLOCK | O_NDELAY)) < 0){
        printf("Can\'t open FIFO for reading\n");
        exit(-1);
    }

    char buf[BUFSIZE];

    if(fork())
    {
        for(;;)
        {
            if((size = read(STDIN_FILENO, buf, BUFSIZE)) > 0)
            {
                write(fdW, buf, size);
            }
        }
    }
    else
    {
        for(;;)
        {
            if((size = read(fdR, buf, BUFSIZE)) > 0)
            {
                write(STDOUT_FILENO, buf, size);
            }
        }
    }

    close(fdW);
    close(fdR);

    return 0;
}
