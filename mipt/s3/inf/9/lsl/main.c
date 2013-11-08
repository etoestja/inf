#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <unistd.h>
#include <stdlib.h>

int alphasortQsort(const void* a, const void* b)
{
    return(alphasort((const struct dirent**) a, (const struct dirent**) b));
}

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

    while(readdir(dir) != NULL)
        count++;

    printf("total %d\n", count);

    struct dirent** directory = malloc(sizeof(struct dirent*) * count);

    rewinddir(dir);

    int i = 0;
    while((directory[i++] = readdir(dir)) != NULL);

    qsort(directory, count, sizeof(struct dirent*), alphasortQsort);

    for(i = 0; i < count; i++)
    {
        printf("%s ", directory[i]->d_name);
        printf("\n");
    }
    
    if(closedir(dir) < 0)
    {
        printf("closedir failed [%s]\n", argv[1]);
        return(-1);
    }

    return(0);
}
