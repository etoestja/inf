#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>

int main(int argc, char** argv)
{
	if(argc < 2)
		return(-1);
	int fd = open(argv[1], O_RDONLY);
	int pos = lseek(fd, 0, SEEK_END);
	printf("size of %s = %d\n", argv[1], pos);
	return(0);
}
