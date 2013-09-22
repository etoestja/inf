#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "parseargs.h"

#define MAXLEN 1000

char *string = NULL;
size_t len1;
int len;

char **args;
int argsc;

//#define DEBUG

#define PROGN 2

int main(int argc, char** argv, char** envp)
{
    int cpid, cstatus, strLen, i;
    int myPipe[2];
    if(pipe(myPipe) < 0)
    {
        printf("Error creating pipe!\n");
        return(1);
    }

    for(i = 0; i < PROGN; i++)
    {
        getline(&string, &len1, stdin);
        strLen = strlen(string);

        mallocArgs(&args, strLen);
        parseArgs(string, strLen, args, &argsc);

#ifdef DEBUG
        printArgs(args, argsc);
#endif

        if(argsc >= 1)
        {
            if(!(cpid = fork()))
            {
                dup2(myPipe[!i], !i);
                close(myPipe[i]);
                cstatus = execvpe(args[0], args, envp);
                printf("Error opening %s, code = %d\n", string, cstatus);
                close(myPipe[!i]);
                freeArgs(&args, &argsc, strLen);
                free(string);
                string = NULL;
                return(1);
            }
        }
        else
        {
            printf("Wrong input\n");
            freeArgs(&args, &argsc, strLen);
            free(string);
            return(1);
        }

        freeArgs(&args, &argsc, strLen);
        free(string);
        string = NULL;
    }

    return(0);
}
