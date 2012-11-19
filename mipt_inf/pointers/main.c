#include <stdio.h>

int main()
{
    printf("type\tsize\tsize*\n");
    printf("char\t%ld\t%ld\n", sizeof(char), sizeof(char *));
    printf("int\t%ld\t%ld\n", sizeof(int), sizeof(int *));
    printf("long\t%ld\t%ld\n", sizeof(long), sizeof(long *));
    printf("short\t%ld\t%ld\n", sizeof(short), sizeof(short *));
    printf("float\t%ld\t%ld\n", sizeof(float), sizeof(float *));
    printf("double\t%ld\t%ld\n", sizeof(double), sizeof(double *));
    printf("long d.\t%ld\t%ld\n", sizeof(long double), sizeof(long double *));
}
