#include <stdio.h>
#include <unistd.h>

int main(int argc, char** argv, char** envp)
{
    if(argc == 1)
    {
        printf("Usage: %s progname [arg] [arg] ...\n", argv[0]);
        return(1);
    }

    int res = execle(argv[1], argv[1], 0, envp);

    printf("Can't exec %s, error code=%d\n", argv[1], res);
    return(0);
}
