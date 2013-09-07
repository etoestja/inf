#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>


int main()
{
    printf("%d %d %d %d\n", getuid(), getgid(), getpid(), getppid());
    return(0);
}
