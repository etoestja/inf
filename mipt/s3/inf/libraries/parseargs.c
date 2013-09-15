#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "parseargs.h"

#define MAXLEN 1000

void mallocArgs(char*** args, int strLen)
{
    // +1 because of last NULL
    *args = malloc(sizeof(char*) * (strLen + 1));

    int i;
    // no +1 because ptr=NULL
    for(i = 0; i < strLen; i++)
    {
#ifdef DEBUG
        printf("strLen=%d malloc i=%d\n", strLen, i);
#endif
        (*args)[i] = malloc(sizeof(char) * strLen);
    }
}

void parseArgs(char* string, int len, char** args, int* argsc)
{
    int currentArg = 0, currentChar = 0;
    int sumLen = 0;

    int lastLen;

    if(string[len - 1] == '\n')
    {
        string[len - 1] = 0;
        len--;
    }

    while(sumLen < len && sscanf(string + sumLen, "%s%n", args[currentArg], &lastLen))
    {
//        printf("sumLen = %d currentArg=%d lastLen=%d\n", sumLen, currentArg, lastLen);
        sumLen += lastLen;
        currentArg++;
    }

    *argsc = currentArg;

    // free this, because it will be NULLed
    free(args[*argsc]);
    args[*argsc] = NULL;
}

void printArgs(char** args, int argsc)
{
    printf("got %d args:\n", argsc);
    int i;
    for(i = 0; i < argsc; i++)
    {
        printf("args[%d]=%s\n", i, args[i]);
    }
}

void freeArgs(char*** args, int* argsc, int strLen)
{
    int i;
    for(i = 0; i < strLen; i++)
    {
#ifdef DEBUG
        printf("strlen=%d i=%d freeing...\n", strLen, i);
#endif
        free((*args)[i]);
    }
    free(*args);
    *args = NULL;
    *argsc = 0;
}
