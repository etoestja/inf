#include <stdio.h>
#include <unistd.h>
#include <malloc.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <errno.h>
#include <fcntl.h>
#include <utime.h>
#include <sys/types.h>
#include <sys/time.h>

// Print progress?
#define PRINT_PROGRESS

// Print additional information?
//#define DEBUG

// Colorize?
#define USE_COLORS

// for cp()
#define BUFSIZE 1024

#ifdef USE_COLORS
    #include "colors.h"
    #define PATHCOLOR BLUE
    #define ERRORCOLOR RED
    #define OKCOLOR GREEN
    #define SKIPCOLOR YELLOW
#else
    #define PATHCOLOR ""
    #define ERRORCOLOR ""
    #define OKCOLOR ""
    #define SKIPCOLOR ""
    #define RESET ""
#endif

enum _fileType {_DIRECTORY, _FILE};

typedef struct
{
    int exists;
    time_t lastModified;
    time_t lastAccessed;
    int type;
} fileInfo;


void nofprintf(FILE* fstream, ...)
{
    return;
}

const char* extensionGZ = ".gz";

#ifdef DEBUG
    #define dfprintf fprintf
#else
    #define dfprintf nofprintf
#endif

#ifdef PRINT_PROGRESS
    #define pfprintf fprintf
#else
    #define pfprintf nofprintf
#endif

char*** envpGlobal;

int getFileInfo(char* path, fileInfo *res)
{
    res->exists = 0;
    struct stat tStat;

    if(lstat(path, &tStat))
    {
        res->exists = 0;
        return(0);
    }

    res->exists = 1;

    if(S_ISDIR(tStat.st_mode))
        res->type = _DIRECTORY;
    else if(S_ISREG(tStat.st_mode))
        res->type = _FILE;
    else
    {
        res->exists = 0;
        return(0);
    }

    res->lastModified = tStat.st_mtime;
    res->lastAccessed = tStat.st_atime;

    return(0);
}

// don't forget to free!
char* getPathAddItem(char* dir, char* item)
{
    char* res = malloc(sizeof(char) * (strlen(dir)  + strlen(item) + 2));
    strcpy(res, dir);
    if(res[strlen(res) - 1] != '/')
        strcat(res, "/");
    strcat(res, item);
    return(res);
}

int setMATime(char* path, time_t M, time_t A)
{
    struct utimbuf tUtimBuf;
    tUtimBuf.actime  = A;
    tUtimBuf.modtime = M;

    if(utime(path, &tUtimBuf))
    {
        pfprintf(stderr, "utime ");
        return(1);
    }
    return(0);
}

int cp(char* src, char* dest, fileInfo* srcInfo)
{
    int fdSrc  = open(src,  O_RDONLY);

    if(fdSrc < 0)
    {
        pfprintf(stderr, "src ");
        close(fdSrc);
        return(-1);
    }

    int fdDest = open(dest, O_WRONLY | O_CREAT, 0777);

    if(errno == EEXIST)
    {
        //pfprintf(stderr, "REOPEN\n");
        fdDest = open(dest, O_WRONLY, 0777);
    }

    int res = 0;

    if(fdDest >= 0)
    {
        ssize_t size;
        char buf[BUFSIZE];

        while((size = read(fdSrc, (char*) buf, BUFSIZE)) > 0)
        {
            if(write(fdDest, buf, size) != size)
                res = 1;
        }
    }
    else
    {
        pfprintf(stderr, "dest ");
        //fprintf(stderr, "OPNF fdSrc=%d fdDest=%d\n", fdSrc, fdDest);
        res = 1;
    }

    close(fdSrc);
    close(fdDest);

    if(setMATime(dest, srcInfo->lastModified, srcInfo->lastAccessed))
        return(-1);

    return(res);
}

int fileGZ(char* path)
{
//    const char* command = "tar";
//    const char* args[] = {command, "-C", directory, "-czf", fullDestPathGZ, file, NULL};

    const char* command = "gzip";
    const char* args[] = {command, "-f", path, NULL};

    //fprintf(stderr, "cmd=%s -C %s -czf %s %s\n", command, directory, fullDestPathGZ, file);

    pid_t tPID;
    int status;

    if((tPID = fork()))
    {
        if(waitpid(tPID, &status, 0) < 0)
            return(-1);
        if(WIFEXITED(status) && WEXITSTATUS(status) == 0)
            return(0);
        return(-1);
    }
    else
    {
        execvpe(command, args, *envpGlobal);
        return(-1);
    }
    return(-1);
}

int directoryScanBackup(char* src, char* dest)
{
    if(src == NULL || dest == NULL)
        return(-1);
    dfprintf(stderr, "CALLED %s %s\n", src, dest);

    DIR* dir = opendir(src);

    int res = 0;

    if(dir == NULL)
    {
        pfprintf(stderr, PATHCOLOR "%s" RESET ": opendir " ERRORCOLOR "failed" RESET "\n", src);
        return(-1);
    }

    if(mkdir(dest, 0777) && errno != EEXIST)
    {
        pfprintf(stderr, PATHCOLOR "%s" RESET ": mkdir " ERRORCOLOR "failed" RESET " [%s]\n", src, dest);
        closedir(dir);
        return(-1);
    }

    fileInfo infoDir;
    if(getFileInfo(src, &infoDir))
    {
        pfprintf(stderr, PATHCOLOR "%s" RESET ": getFileInfo " ERRORCOLOR "failed" RESET "\n", src);
        closedir(dir);
        return(-1);
    }

    struct dirent *directory;
    char *pathSrc = NULL, *pathDest = NULL, *pathDestGZ = NULL;
    fileInfo infoSrc, /*infoDest,*/ infoDestGZ;

    while((directory = readdir(dir)) != NULL)
    {
        if(directory->d_name[0] == '.') continue;

        pathSrc  = getPathAddItem(src, directory->d_name);
        pathDest = getPathAddItem(dest, directory->d_name);
        pathDestGZ = malloc(sizeof(char) * (strlen(pathDest) + strlen(extensionGZ) + 1));
        strcpy(pathDestGZ, pathDest);
        strcat(pathDestGZ, extensionGZ);

        pfprintf(stderr, PATHCOLOR "%s" RESET ": ", pathSrc);

        if(getFileInfo(pathSrc, &infoSrc))
        {
            pfprintf(stderr, ERRORCOLOR "Can't stat file %s!" RESET "\n", pathSrc);
            res = -1;
            continue;
        }

//        if(getFileInfo(pathDest, &infoDest))
//        {
//            pfprintf(stderr, ERRORCOLOR "Can't stat file %s!" RESET "\n", pathDest);
//            res = -1;
//            continue;
//        }

        if(getFileInfo(pathDestGZ, &infoDestGZ))
        {
            pfprintf(stderr, ERRORCOLOR "Can't stat file %s!" RESET "\n", pathDestGZ);
            res = -1;
            continue;
        }

        if(infoSrc.exists)
        {
            if(infoSrc.type == _DIRECTORY)
            {
                pfprintf(stderr, "opening...\n");
                if(directoryScanBackup(pathSrc, pathDest))
                    res = -1;
            }
            else
            {
                if(!infoDestGZ.exists || infoDestGZ.lastModified < infoSrc.lastModified)
                {
                    pfprintf(stderr, "cp " PATHCOLOR "%s" RESET " ", pathDest);
                    if(cp(pathSrc, pathDest, &infoSrc))
                    {
                        pfprintf(stderr, ERRORCOLOR "error!" RESET "\n");
                        res = -1;
                    }
                    else
                    {
                        pfprintf(stderr, OKCOLOR "OK" RESET " gzip... ");
                        if(fileGZ(pathDest))
                        {
                            pfprintf(stderr, ERRORCOLOR "error!" RESET "\n");
                            res = -1;
                        }
                        else
                        {
                            pfprintf(stderr, OKCOLOR "OK" RESET "\n");
                            if(setMATime(pathDestGZ, infoSrc.lastModified,  infoSrc.lastAccessed))
                            {
                                //fprintf(stderr, "path=%s\n", pathDestGZ);
                                pfprintf(stderr, ERRORCOLOR "gz failed" RESET "\n");
                                res = -1;
                            }
                        }
                    }
                }
                else pfprintf(stderr, SKIPCOLOR "skipping" RESET "\n");
            }
        }
        else
            pfprintf(stderr, "\n");

        free(pathSrc);
        pathSrc = NULL;
        free(pathDest);
        pathDest = NULL;
        free(pathDestGZ);
        pathDestGZ = NULL;
    }

    if(closedir(dir) < 0)
    {
        pfprintf(stderr, "closedir failed [%s]\n", src);
        return(-1);
    }

    if(setMATime(dest, infoDir.lastModified,  infoDir.lastAccessed))
    {
        pfprintf(stderr, ERRORCOLOR "failed" RESET "\n");
        closedir(dir);
        return(-1);
    }

    return(res);
}

int main(int argc, char** argv, char** envp)
{
    if(argc != 3)
    {
        printf("Usage: %s /path/to/src_dir /path/to/dest_dir\n", argv[0]);
        return(-1);
    }

    envpGlobal = &envp;

    if(directoryScanBackup(argv[1], argv[2]))
    {
        printf(ERRORCOLOR "Completed, with errors" RESET "\n");
        return(-1);
    }
    else
    {
        printf(OKCOLOR "Completed, no errors" RESET "\n");
        return(0);
    }

    return(0);
}
