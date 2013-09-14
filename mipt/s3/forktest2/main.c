#include <stdio.h>
#include <unistd.h>

int main()
{
    printf("started\tPID=%d\tPPID=%d\n", getpid(), getppid());

    int res = fork();
    printf("%s\tPID=%d\tPPID=%d\n", res ? "parent" : "child",
        getpid(), getppid());
    return(0);
}
