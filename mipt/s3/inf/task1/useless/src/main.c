#include <stdio.h>
#include <unistd.h>

typedef struct
{
    int delay;
    char* nameArgs;
} program;

int programCmp(const void *a, const void *b)
{
    return(((program*) a)->delay > ((program*) b)->delay);
}

#define FILENAME_MAXLEN 1000
#define MAXPROGS 1000
char filename[FILENAME_MAXLEN];

void parseFile()
{
    FILE *fd = fopen(filename, "r");
    
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
