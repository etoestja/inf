#include <stdio.h>

int MAXZ = 20;
#define OP *

int main()
{
    int a, b;
    scanf("%d", &a);
    scanf("%d", &b);

    int z;
    for(z = 1; z <= MAXZ; z++)
        printf("%d %d\n", z, ((a % z) OP (b % z)) - ((a OP b) % z));

    return(0);
}
