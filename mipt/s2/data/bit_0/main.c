#include <stdio.h>

int main()
{
    unsigned int x, y;
    scanf("%x", &x);
    scanf("%x", &y);
    printf("%x\n", x ^ y);

    return(0);
}
