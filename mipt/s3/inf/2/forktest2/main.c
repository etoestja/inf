#include <stdio.h>
#include <unistd.h>

int main()
{
    printf("started\tPID=%d\tPPID=%d\n", getpid(), getppid());

    int res = fork();

    if(res == -1)
    {
        printf("can't fork. exiting...\n");
        return(1);
    }

#ifndef NOWAITPID
    if(res)
    {
        printf("waiting for child...\n");
        waitpid(res, NULL, 0);
        printf("wait ok\n");
    }
#endif

    printf("%s\tPID=%d\tPPID=%d\n", res ? "parent" : "child",
        getpid(), getppid());

    return(0);
}
