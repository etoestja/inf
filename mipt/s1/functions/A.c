#include <stdio.h>
#include "math.h"
#include "Af.c"

int main()
{
    int a;
    unsigned int b;
    scanf("%d%u", &a, &b);

//    printf("mine: %d, math.h: %d\n", pow_(a, b), pow(a, b));

    printf("mine: %d\n", power(a, b));
    return 0;
}
