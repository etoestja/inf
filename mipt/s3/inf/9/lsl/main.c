#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
    if(argc < 2)
    {
        printf("Usage: %s path\n", argv[0]);
        return(-1);
    }

    DIR* dir = opendir(argv[1]);

    if(dir == NULL)
    {
        printf("opendir failed [%s]\n", argv[1]);
        return(-1);
    }

    int count = 0;

    struct dirent* directory;
    while(readdir(dir) != NULL)
        count++;

    printf("total %d\n", count);

    rewinddir(dir);

    while((directory = readdir(dir)) != NULL)
    {
        printf("%s ", directory->d_name);
        printf("\n");
    }
    
    if(closedir(dir) < 0)
    {
        printf("closedir failed [%s]\n", argv[1]);
        return(-1);
    }

    return(0);
}
