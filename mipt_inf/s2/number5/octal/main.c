#include <stdio.h>

#define MAXLEN 100
#define BASE 8

int main()
{
    int x;
    char y[MAXLEN];
    int yC = 0;

    scanf("%d", &x);

    if(x == 0) printf("0");

    while(x)
    {
        y[yC++] = x % BASE;
        x /= BASE;
    }

    for(yC--; yC >=0; yC--)
        printf("%c", y[yC] + '0');

    printf("\n");

    return(0);
}
