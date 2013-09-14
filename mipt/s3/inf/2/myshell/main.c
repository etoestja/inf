#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#define MAXLEN 1000

char *string;
size_t len1;
int len;

char **args;
int argsc;

void parseLine()
{
    int currentArg = 0, currentChar = 0;
    int sumLen = 0;

    len = strlen(string);

    args = malloc(sizeof(char*) * (len + 1));
    int i;
    for(i = 0; i < len; i++)
        args[i] = malloc(sizeof(char) * len);

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

    argsc = currentArg;

    args[argsc] = NULL;
}

void printArgs()
{
    printf("got %d args:\n", argsc);
    int i;
    for(i = 0; i < argsc; i++)
    {
        printf("args[%d]=%s\n", i, args[i]);
    }
}

void freeAll()
{
    int i;
    for(i = 0; i < len; i++)
        free(args[i]);
    free(args);
}

int main(int argc, char** argv, char** envp)
{
    int cpid;
    int cstatus;
    for(;;)
    {
        printf("myshell $ ");
        getline(&string, &len1, stdin);
//        printf("got line %s", string);
        parseLine();
//        printArgs();

        if(argsc == 1 && !strcmp(args[0], "exit"))
        {
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
        
/*        int res = execle(argv[1], argv[1], 0, envp);

        printf("Can't exec %s, error code=%d\n", argv[1], res);*/
//        free(tName);
        freeAll();
    }
    return(0);
}
