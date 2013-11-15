#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>

const char* MONTHS[] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};

#define BLOCKSIZE_COEFF_D 2

int alphasortQsort(const void* a, const void* b)
{
    //const struct dirent *x = *((const struct dirent**) a);
    //const struct dirent *y = *((const struct dirent**) b);
    //if(S_ISDIR(x->d_type))
    return(alphasort((const struct dirent**) a, (const struct dirent**) b));
}

int digitsN(int a)
{
    if(a == 0)
        return(1);
    int r = 0;
    while(a)
    {
        a /= 10;
        r++;
    }
    return(r);
}

void printIntFill(int a, int b)
{
    int i;
    for(i = 0; i < b - digitsN(a); i++)
        printf("0");
    printf("%d", a);
}

void printDate(struct tm then)
{
    time_t a = time(NULL);
    struct tm now = *localtime(&a);
    printIntFill(then.tm_mday, 2);
    printf(" ");
    printf("%s", MONTHS[then.tm_mon]);
    printf(" ");
    if(now.tm_year != then.tm_year)
    {
        printf("%d", then.tm_year + 1901);
    }
    else
    {
        printIntFill(then.tm_hour, 2);
        printf(":");
        printIntFill(then.tm_min, 2);
    }
    //no
}

void printPerm(mode_t mode)
{
    if(S_ISDIR(mode))
        printf("d");
    else if(S_ISREG(mode))
        printf("-");
    else if(S_ISLNK(mode))
        printf("-");

    printf(S_IRUSR & mode ? "r" : "-");
    printf(S_IWUSR & mode ? "w" : "-");
    printf(S_IXUSR & mode ? "x" : "-");

    printf(S_IRGRP & mode ? "r" : "-");
    printf(S_IWGRP & mode ? "w" : "-");
    printf(S_IXGRP & mode ? "x" : "-");

    printf(S_IROTH & mode ? "r" : "-");
    printf(S_IWOTH & mode ? "w" : "-");
    printf(S_IXOTH & mode ? "x" : "-");
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

    struct dirent* directory = malloc(sizeof(struct dirent) * count), *t;

    rewinddir(dir);

    int i = 0;
    while((t = readdir(dir)) != NULL)
        directory[i++] = *t;

    //qsort(directory, count, sizeof(struct dirent*), alphasortQsort);

    char* path = NULL;

    struct stat tStat;

    int totalBlocks = 0;

    struct passwd *structUser;
    struct group  *structGroup;

    struct tm cftime;

    for(i = 0; i < count; i++)
    {
        if(directory[i].d_name[0] == '.') continue;
        //printf("name=%s, %d ", directory[i].d_name, strlen(directory[i].d_name));
        path = malloc(sizeof(char) * (strlen(argv[1]) + strlen(directory[i].d_name) + 2));
        strcpy(path, argv[1]);
        strcat(path, "/");
        strcat(path, directory[i].d_name);
        lstat(path, &tStat);

        totalBlocks += tStat.st_blocks / BLOCKSIZE_COEFF_D;
        structUser = getpwuid(tStat.st_uid);
        structGroup = getgrgid(tStat.st_gid);

        printPerm(tStat.st_mode);
        printf("\t%d", tStat.st_nlink);
        if(structUser == NULL)
            printf("\t%d", tStat.st_uid);
        else
            printf("\t%s", structUser->pw_name);

        if(structGroup == NULL)
            printf("\t%d", tStat.st_gid);
        else
            printf("\t%s", structGroup->gr_name);

        printf("\t%d", tStat.st_size);

        localtime_r(&tStat.st_mtime, &cftime);
        printf("\t");
        printDate(cftime);

        printf("\t%s", directory[i].d_name);

        printf("\n");
        free(path);
        path = NULL;
    }

    free(directory);

    printf("total %d\n", totalBlocks);

    if(closedir(dir) < 0)
    {
        printf("closedir failed [%s]\n", argv[1]);
        return(-1);
    }

    return(0);
}
