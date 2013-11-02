#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

int filter(const struct dirent *item)
{
    return(1);
}

int main(int argc, char* argv[])
{
    if(argc < 2)
    {
        printf("Usage: %s path\n", argv[0]);
        return(-1);
    }

    struct dirent **contents;
    int count = scandir(argv[1], &contents, filter, alphasort);

    printf("total %d\n", count);

    if(count < 0)
    {
        printf("scandir failed [%s]\n", argv[1]);
        return(-1);
    }
    if(count == 0)
        return(0);

    int i;
    struct stat info;
    char* path = NULL;
    for(i = 0; i < count; i++)
    {
        path = malloc(sizeof(char) * (strlen(argv[1]) + 1 + strlen(contents[i]->d_name) + 1));
        strcpy(path, argv[1]);
        strcat(path, "/");
        strcat(path, contents[i]->d_name);
        printf("%s, %s\n", contents[i]->d_name, path);
        free(path);
        free(contents[i]);
        path = NULL;
    }

    free(contents);
    
    return(0);
}
