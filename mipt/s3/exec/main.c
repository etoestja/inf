#include <stdio.h>
#include <unistd.h>

int main()
{
    char* argv[] = { NULL };
    char* envp[] = { NULL };

    printf("exec\n");
    execve("/bin/bash", argv, envp);
    printf("/exec\n");
    return(0);
}
