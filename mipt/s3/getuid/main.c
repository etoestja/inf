#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>


int main()
{
    printf("%d %d\n", getuid(), getgid());
    return(0);
}
