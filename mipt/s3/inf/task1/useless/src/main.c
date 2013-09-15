#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "parseargs.c"

#define FILENAME_MAXLEN 1000
#define NAMEARGS_MAXLEN 1000
#define MAXPROGS 1000

int main(int argc, char** argv, char** envp)
{
    if(argc == 1)
    {
        printf("Usage: %s filename\n", argv[0]);
        printf(" filename - instructions file to open\n");
        printf("  format: lines with <delay> <progname> <args>\n");
        return(1);
    }
    else
    {
        FILE *fd = fopen(argv[1], "r");

        if(!fd)
        {
            printf("Error opening %s\n", argv[1]);
            return(1);
        }

        char *string = NULL, **args;
        int cpid, cstatus, time, strLen, argsc;
        size_t len1;

        while(getline(&string, &len1, fd) != -1)
        {
            strLen = strlen(string);
            mallocArgs(&args, strLen);
            parseArgs(string, strLen, args, &argsc);
//            printArgs(args, argsc);

            if(argsc >= 2)
            {
                if(cpid = fork())
                {
                }
                else
                {
                    if(sscanf(args[0], "%d", &time) < 1 || time < 0)
                    {
                        printf("Invalid time format at string %s\n", string);
                        printf(" line format: <delay> <progname> <args>\n");
                        return(1);
                    }
                    sleep(time);

                    //cannot freeargs because of exec!
//                    freeArgs(&args, &argsc, strLen);
//                    free(string);
//                    string = NULL;

                    fclose(fd);
                    cstatus = execvpe(args[1], args + 1, envp);
                    if(cstatus != 0)
                        printf("Error opening at line \"%s\"\n", string);
                    return(0);
                }
            }
            else
            {
                printf("Invalid file format at string %s\n", string);
                printf(" line format: <delay> <progname> <args>\n");
            }

            freeArgs(&args, &argsc, strLen);
            free(string);
            string = NULL;
        }

        if(string != NULL) free(string);
        string = NULL;

        fclose(fd);
    }
}
