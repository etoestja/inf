#include <stdio.h>
#include <stdlib.h>
#define size 16

//char a[size][size];
int main()
{
	char* x;
	x = malloc(size);
	printf("%lld", x);
	free(x);
	return 0;
}
