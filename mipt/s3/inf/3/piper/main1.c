#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "parseargs.h"

#define MAXLEN 1000

char *string = NULL;
size_t len1;
int len;

#define PROGN 2

char **args[PROGN];
int argsc[PROGN];
int strLen[PROGN];

#define DEBUG

int rpid[PROGN];

int main(int argc, char** argv, char** envp)
{
    int i;
    int myPipe[2];
    if(pipe(myPipe) < 0)
    {
        printf("Error creating pipe!\n");
        return(1);
    }

    for(i = 0; i < PROGN; i++)
    {
        getline(&string, &len1, stdin);
        strLen[i] = strlen(string);

        mallocArgs(&args[i], strLen[i]);
        parseArgs(string, strLen[i], args[i], &(argsc[i]));

#ifdef DEBUG
        printf("i=%d\n", i);
        printArgs(args[i], argsc[i]);
#endif
        free(string);
        string = NULL;
    }
    if(argsc[0] > 0 && argsc[1] > 0)
    {
        if(!fork())
        {
            dup2(myPipe[1], 1); //source
            close(myPipe[0]);
            freeArgs(&args[1], &argsc[1], strLen[1]);

            execvpe(args[0][0], args[0], envp);

            printf("Error opening %s\n", args[0][0]);
            freeArgs(&args[0], &argsc[0], strLen[0]);
            close(myPipe[1]);
        }
        else
        {
            dup2(myPipe[0], 0); //destination
            close(myPipe[1]);
            freeArgs(&args[0], &argsc[0], strLen[0]);

            execvpe(args[1][0], args[1], envp);

            printf("Error opening %s\n", args[1][0]);
            freeArgs(&args[1], &argsc[1], strLen[1]);
            close(myPipe[0]);
        }
    }
    else
    {
        printf("Wrong input\n");
        freeArgs(&args[0], &argsc[0], strLen[0]);
        freeArgs(&args[1], &argsc[1], strLen[1]);
        close(myPipe[0]);
        close(myPipe[1]);
    }

    return(0);
}
