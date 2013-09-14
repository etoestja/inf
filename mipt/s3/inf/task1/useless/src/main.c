#include <stdio.h>
#include <unistd.h>

#define FILENAME_MAXLEN 1000
#define NAMEARGS_MAXLEN 1000
#define MAXPROGS 1000

typedef struct
{
    int delay;
    char nameArgs[NAMEARGS_MAXLEN];
} program;

program arr[MAXPROGS];

int programCmp(const void *a, const void *b)
{
    return(((program*) a)->delay > ((program*) b)->delay);
}

char filename[FILENAME_MAXLEN];

void parseFile()
{
    FILE *fd = fopen(filename, "r");

    int tTime;
    char [NAMEARGS_MAXLEN]
    while(fscanf(fd, "%d", &tTime))
    {
        printf("got time=%d and prog=%s\n", tTime, );
    }
    
    fclose(fd);
}

void 

int main(int argc, char** argv)
{
    if(argc == 1)
    {
        printf("Usage: %s filename\n", argv[0]);
        printf(" filename - instructions file to open\n");
        printf("  format: lines with <delay> <progname> <args>\n");
    }
}
