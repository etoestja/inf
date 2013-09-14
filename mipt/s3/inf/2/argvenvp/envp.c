#include <stdio.h>

int main(int argc, char** argv, char** envp)
{
    int envc;
    for(envc = 0; envp[envc] != NULL; envc++);

    printf("envc=%d\n", envc);

    int i;
    for(i = 0; i < envc; i++)
        printf("envp[%d]=%s\n", i, envp[i]);

    return(0);
}
