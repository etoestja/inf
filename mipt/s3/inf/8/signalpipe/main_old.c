#include <signal.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

// SIGUSR1: parent->child
// SIGUSR2: child->parent

void handler(int nsig)
{
    
}

#define BUFSIZE 10

int main()
{
    int fd[2];
    if(pipe(fd) < 0)
    {
        printf("Error: can't create pipe!\n");
        return(-1);
    }
    size = read(fd[0], resstring, 14);
    size = write(fd[1], string, 14);
    signal(SIGUSR1, handler);
t
    char buf[BUFSIZE];

    if(fork())
    {
        //parent
        signal(SIGUSR2, handler);
        if((size = read(STDIN_FILENO, buf, BUFSIZE)) > 0)
            write(fd[1], buf, size);

    }
    else
    {
        //child
        signal(SIGUSR1, handler);
        if((size = read(fdR, buf, BUFSIZE)) > 0)
            write(STDOUT_FILENO, buf, size);
    }
    return(0);

}

