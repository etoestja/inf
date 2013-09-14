#include <stdio.h>
#include <unistd.h>

int main()
{
    printf("fork=\t%d\t%d\t%d\t%d\n", fork(), getuid(), getgid(), getpid(), getppid());
    return(0);
}
