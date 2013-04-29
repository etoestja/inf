#include <stdio.h>

int main()
{
    int x = -(1 << 31);
    printf("%d\n", x + x);
    return(0);
}
