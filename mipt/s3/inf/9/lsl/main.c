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

void printIntFill(int a, int b, char* s)
{
    int i;
    int diff = b - digitsN(a);
    for(i = 0; i < diff; i++)
        s[i] = '0';
    sprintf(s + (diff > 0 ? diff : 0), "%d", a);
    if(diff >= 0)
        s[b] = 0;
    else s[digitsN(a)] = 0;
    //printf("%s", s);
}

void itoa(char** dest, int t)
{
    int NN = digitsN(t);
    *dest = malloc(NN + 1);
    if(t == 0)
        (*dest)[0] = 0;
    int d;
    int i = 1;
    while(t)
    {
        d = t % 10;
        (*dest)[NN - i] = '0' + d;
        t /= 10;
        i++;
    }

    (*dest)[NN] = 0;
}

void printDate(struct tm then, char** s1, char** s2, char** s3)
{
    (*s2) = malloc(10);
    (*s3) = malloc(10);
    time_t a = time(NULL);
    struct tm now = *localtime(&a);
    printIntFill(then.tm_mday, 1, (*s2));
    (*s1) = strdup(MONTHS[then.tm_mon]);
    if(now.tm_year != then.tm_year)
    {
        printIntFill(then.tm_year + 1901, 4, *s3);
    }
    else
    {
        printIntFill(then.tm_hour, 2, *s3);
        (*s3)[2] = ':';
        printIntFill(then.tm_min, 2, (*s3) + 3);
    }
    //printf("%s %s %s", (*s1), (*s2), (*s3));
    //no
}

void printPerm(mode_t mode, char** x)
{
    *x = malloc(11); //magic
    if(S_ISDIR(mode))
        (*x)[0] = 'd';
    else if(S_ISREG(mode))
        (*x)[0] = '-';
    else if(S_ISLNK(mode))
        (*x)[0] = 'l';
    else
        (*x)[0] = ' ';

    (*x)[1] = (S_IRUSR & mode ? 'r' : '-');
    (*x)[2] = (S_IWUSR & mode ? 'w' : '-');
    (*x)[3] = (S_IXUSR & mode ? 'x' : '-');

    (*x)[4] = (S_IRGRP & mode ? 'r' : '-');
    (*x)[5] = (S_IWGRP & mode ? 'w' : '-');
    (*x)[6] = (S_IXGRP & mode ? 'x' : '-');

    (*x)[7] = (S_IROTH & mode ? 'r' : '-');
    (*x)[8] = (S_IWOTH & mode ? 'w' : '-');
    (*x)[9] = (S_IXOTH & mode ? 'x' : '-');
    (*x)[10]= 0;
    //printf("%s", *x);
}

char*** array;
int arrayC, arrayR;
int* arrayM;
enum align {L, R};
int arrayAlign[] = {L, R, L, L, R, L, R, R, L};

void arrayCreate2(int P, int Q)
{
    arrayR = P;
    arrayC = Q;
    array = malloc(sizeof(char**) * P);
    int i, j;
    for(i = 0; i < P; i++)
    {
        array[i] = malloc(sizeof(char*) * Q);
        for(j = 0; j < Q; j++)
            array[i][j] = "";
    }
}

void fillSpaces(int N)
{
    int i;
    for(i = 0; i < N; i++)
        printf(" ");
}

void arrayUpd()
{
    int i, j;
    arrayM = malloc(sizeof(int) * arrayC);
    for(i = 0; i < arrayC; i++)
    {
        arrayM[i] = 0;
        for(j = 0; j < arrayR; j++)
        {
            if(arrayM[i] < strlen(array[j][i]))
                arrayM[i] = strlen(array[j][i]);
        }
    }
}

void arrayPrint()
{
    int i, j;
    for(i = 0; i < arrayR; i++)
    {
        if(strlen(array[i][0]) == 0) continue;
        for(j = 0; j < arrayC; j++)
        {
            if(arrayAlign[j] == R && strlen(array[i][j]) < arrayM[j])
                fillSpaces(arrayM[j] - strlen(array[i][j]));
            printf(array[i][j]);
            if(arrayAlign[j] == L && strlen(array[i][j]) < arrayM[j])
                fillSpaces(arrayM[j] - strlen(array[i][j]));
            if(j + 1 < arrayC)
                printf(" ");
        }
        printf("\n");
    }
}

char* getLink(char* x)
{
    struct stat sb;
    char *linkname;
    ssize_t r;

    if (lstat(x, &sb) == -1) {
        perror("lstat");
        exit(EXIT_FAILURE);
    }

    linkname = malloc(sb.st_size + 1);
    if (linkname == NULL) {
        fprintf(stderr, "insufficient memory\n");
        exit(EXIT_FAILURE);
    }

    r = readlink(x, linkname, sb.st_size + 1);

    if (r < 0) {
        perror("lstat");
        exit(EXIT_FAILURE);
    }

    if (r > sb.st_size) {
        fprintf(stderr, "symlink increased in size "
                "between lstat() and readlink()\n");
        exit(EXIT_FAILURE);
    }

    linkname[sb.st_size] = '\0';

    return(linkname);
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

    arrayCreate2(count, 9);
    int j = 0;

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

        printPerm(tStat.st_mode, &(array[j][0]));
        itoa(&(array[j][1]), tStat.st_nlink);
        if(structUser == NULL)
            itoa(&(array[j][2]), tStat.st_uid);
        else
            array[j][2] = strdup(structUser->pw_name);

        if(structGroup == NULL)
            itoa(&(array[j][3]), tStat.st_gid);
        else
            array[j][3] = strdup(structGroup->gr_name);

        //printf("\t%d", tStat.st_size);
        itoa(&(array[j][4]), tStat.st_size);

        localtime_r(&tStat.st_mtime, &cftime);

        printDate(cftime, &(array[j][5]), &(array[j][6]), &(array[j][7]));


        if(S_ISLNK(tStat.st_mode))
        {
            char* ll = getLink(path);
            array[j][8] = malloc(strlen(directory[i].d_name) + strlen(" -> ") + strlen(ll) + 1);
            strcpy(array[j][8], directory[i].d_name);
            strcat(array[j][8], " -> ");
            strcat(array[j][8], ll);
        }
        else
        {
            array[j][8] = strdup(directory[i].d_name);
        }

        j++;
        //free(path);
        path = NULL;
    }

    free(directory);

    printf("total %d\n", totalBlocks);

    arrayUpd();
    arrayPrint();

    if(closedir(dir) < 0)
    {
        printf("closedir failed [%s]\n", argv[1]);
        return(-1);
    }

    return(0);
}

//int main(int argc, char* argv[])
//{
//    arrayCreate2(2, 2);
//    array[0][0] = "abacaba";
//    array[0][1] = "xy";
//    array[1][0] = "xxx";
//    array[1][1] = "dfsfasfasdfasdf";
//    arrayUpd();
//    arrayPrint();
//}
