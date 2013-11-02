#include <signal.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

// SIGUSR1: parent->child write OK
// SIGUSR2: parent->child read OK
// SIGUSR1: child->parent write OK
// SIGUSR2: child->parent read OK

int readOK = 1;
int fd[2];
pid_t pPid, cPid;

#define BUFSIZE 10
char buf[BUFSIZE];
ssize_t size;

void parentHandler(int nsig)
{
    printf("parent got signal %d\n", nsig);
    if(nsig == SIGUSR2)
    {
        fprintf(stderr, "parent: child read OK\n");
        readOK = 1;
    }
    else if(nsig == SIGUSR1)
    {
        if((size = read(fd[0], buf, BUFSIZE)) > 0)
        {
            write(STDOUT_FILENO, buf, size);
            readOK = 0;
            kill(cPid, SIGUSR2);
        }
    }
}

void childHandler(int nsig)
{
    fprintf(stderr, "child got signal %d\n", nsig);
    if(nsig == SIGUSR2)
    {
        readOK = 1;
        fprintf(stderr, "child: parent read OK\n");
        kill(pPid, SIGUSR2);
    }
    else if(nsig == SIGUSR1)
    {
        while(!readOK) usleep(2);
        if((size = read(fd[0], buf, BUFSIZE)) > 0)
        {
            readOK = 0;
            write(fd[1], buf, size);
            kill(pPid, SIGUSR1);
            kill(pPid, SIGUSR2);
        }
    }
}

int main()
{
    if(pipe(fd) < 0)
    {
        printf("Error: can't create pipe!\n");
        return(-1);
    }

    pPid = getpid();

    if(cPid = fork())
    {
        //parent
        signal(SIGUSR1, parentHandler);
        signal(SIGUSR2, parentHandler);
        for(;;)
        {
            while(!readOK) usleep(2);
            if((size = read(STDIN_FILENO, buf, BUFSIZE)) > 0)
            {
                readOK = 0;
                write(fd[1], buf, size);
                fprintf(stderr, "sending to child %d\n", cPid);
                kill(cPid, SIGUSR1);
            }
        }

    }
    else
    {
        //child
        signal(SIGUSR1, childHandler);
        signal(SIGUSR2, childHandler);
        for(;;);

    }

    return(0);

}

