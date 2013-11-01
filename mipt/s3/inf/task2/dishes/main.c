#include <stdio.h>
#include <stdlib.h>

int wPid, cPid;
//w - washer
//c - cleaner
int N;

#define TMAX 1000

#define cleanerFilename "cleaner"
#define washerFilename  "washer"
#define configFilename  "config"

int config[TMAX];
int time[TMAX];

enum action {setConfig, setTime};

#define DEBUG

void printConfig()
{
    fprintf(stderr, "=CONFIG=\n");
    int i;
    for(i = 0; i < TMAX; i++)
    {
        if(config[i] != 0)
            fprintf(stderr, "%d: %d\n", i, config[i]);
    }
}
void printTime()
{
    fprintf(stderr, "=TIME=\n");
    int i;
    for(i = 0; i < TMAX; i++)
    {
        if(time[i] != 0)
            fprintf(stderr, "%d: %d\n", i, time[i]);
    }
}

void initConfig()
{
    int i;
    for(i = 0; i < TMAX; i++)
        config[i] = 0;
}

void parseFile(const char* filename, int action)
{
    FILE* a = fopen(filename, "r");
    if(a == NULL)
    {
        printf("Error! file %s doesn't exist!\n", filename);
        exit(-1);
    }
    int t1, t2;
    if(action == setConfig) initConfig();
    while(fscanf(a, "%d:%d", &t1, &t2) == 2)
    {
        if(t1 < 0 || t1 >= TMAX)
        {
            printf("Type should be in [0,%d) (got %d)\n", TMAX, t1);
            exit(-1);
        }
        if(action == setConfig)
            config[t1] += t2;
        else if(action == setTime)
            time[t1] = t2;
    }
}

int main(int argc, char* argv, char* envp[])
{
    wPid = getpid();
    char* Nstr = getenv("TABLE_LIMIT");
    if(Nstr == NULL)
    {
        printf("Please set TABLE_LIMIT\n");
        exit(-1);
    }
    N = atoi(Nstr);
#ifdef DEBUG
    printf("N=%d\n", N);
#endif
    if(N == 0)
    {
        printf("Please give TABLE_LIMIT positive integer value\n");
    }
    cPid = fork();
    if(cPid < 0)
    {
        printf("Can't fork!\n");
        exit(-1);
    }
    if(cPid)
    {
        // washer
        parseFile(configFilename, setConfig);
        parseFile(washerFilename, setTime);
#ifdef DEBUG
        printConfig();
        printTime();
#endif
        int i, j;
        for(i = 0; i < TMAX; i++)
        {
            for(j = config[i]; j > 0; j--)
            {
                fprintf(stderr, "Washing type %d num %d... ", i, config[i] - j);
                usleep(time[i]);
                fprintf(stderr, "OK\n");
            }
        }

    }
    else
    {
        // cleaner
        parseFile(cleanerFilename, setTime);
#ifdef DEBUG
        printTime();
#endif
    }

}
