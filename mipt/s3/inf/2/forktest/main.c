#include <stdio.h>
#include <unistd.h>

int main()
{
    printf("started PID=%d PPID=%d\n", getpid(), getppid());
    int a, b;
    a = 2;
    b = 3;

    if(fork())
        b = 1;
    printf("PID=%d PPID=%d a=%d b=%d\n", getpid(), getppid(), a, b);
    return(0);
}
