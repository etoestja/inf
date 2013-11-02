#include <unistd.h>
#include <stdio.h>

int main(int argc, char* argv[])
{
    if(argc < 2)
    {
        printf("Usage: %s filename\n", argv[0]);
        return(-1);
    }

    if(unlink(argv[1]) < 0)
    {
        printf("unlink failed [%s]\n", argv[1]);
        return(-1);
    }

    return(0);
}
