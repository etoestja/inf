#include <stdio.h>

char x;

void binPrint(unsigned char x)
{
    const int B = 8;
    int i;
    for(i = B - 1; i >=0; i--)
        printf("%d", (x & (1 << i)) ? 1 : 0);
}

int main()
{
    int x;
    scanf("%d", &x);
    unsigned int y;
    if(x >= 0)
        y = x;
    else y = ((int) x) + 256;
    binPrint(y);
    printf("\n");

    return 0;
}
