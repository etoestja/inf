#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>

int fileLen(char* filename)
{
    return(lseek(open(filename, O_RDONLY), 0, SEEK_END));
}
