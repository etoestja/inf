#include <stdio.h>
#include "lseek.h"

int main(int argc, char** argv)
{
	if(argc < 2)
		return(-1);
    printf("len of %s = %d\n", argv[1], fileLen(argv[1]));
	return(0);
}
