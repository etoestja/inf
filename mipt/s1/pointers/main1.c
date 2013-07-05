#include <stdio.h>

#define typeInfo(typename) printf(#typename"\t%ld\t%ld\n", sizeof(typename), sizeof(typename *))

int main()
{
    int arr[10];

    printf("type\tsize\tsize*\n");
    typeInfo(char);
    typeInfo(int);
    typeInfo(long);
    typeInfo(short);
    typeInfo(float);
    typeInfo(double);
    printf("long d.\t%ld\t%ld\n", sizeof(long double), sizeof(long double *));
    printf("int[10]\t%ld\t%ld\n", sizeof(arr), sizeof(*arr));
}
