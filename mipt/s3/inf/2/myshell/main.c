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

int main(int argc, char** argv, char** envp)
{
    int cpid, cstatus, strLen;
    for(;;)
    {
        printf("myshell $ ");
        getline(&string, &len1, stdin);
        strLen = strlen(string);

        mallocArgs(&args, strLen);
        parseArgs(string, strLen, args, &argsc);

#ifdef DEBUG
        printArgs(args, argsc);
#endif

        if(argsc == 1 && !strcmp(args[0], "exit"))
        {
            freeArgs(&args, &argsc, strLen);
            free(string);
            string = NULL;
            printf("Bye\n");
            return(0);
        }
        else if(argsc >= 1)
        {
            if(cpid = fork())
            {
                waitpid(cpid, &cstatus, 0);
                if(cstatus != 0)
                {
                    printf("Error opening %s\n", string);
                }
            }
            else
                return(execvpe(args[0], args, envp));
        }

        freeArgs(&args, &argsc, strLen);
        free(string);
        string = NULL;
    }
    return(0);
}
