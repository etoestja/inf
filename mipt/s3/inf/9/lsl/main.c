#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <unistd.h>
#include <string.h>
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

    struct dirent* directory = malloc(sizeof(struct dirent) * count), *t;

    rewinddir(dir);

    int i = 0;
    while((t = readdir(dir)) != NULL)
        directory[i++] = *t;

    //qsort(directory, count, sizeof(struct dirent*), alphasortQsort);

    char* path = NULL;

    for(i = 0; i < count; i++)
    {
        //printf("name=%s, %d ", directory[i].d_name, strlen(directory[i].d_name));
        path = malloc(sizeof(char) * (strlen(argv[1]) + strlen(directory[i].d_name) + 1));
        strcpy(path, argv[1]);
        strcat(path, "/");
        strcat(path, directory[i].d_name);
        printf("%s\n", path);
        free(path);
        path = NULL;
    }

    free(directory);

    if(closedir(dir) < 0)
    {
        printf("closedir failed [%s]\n", argv[1]);
        return(-1);
    }

    return(0);
}
