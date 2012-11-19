#include <stdio.h>

int readHHMM()
{
    int h, m;
    scanf("%d%d\n", &h, &m);
    return(h * 60 + m);
}

void printWZero(int x)
{
    if(x < 10)
        printf("0");
    printf("%d", x);
}

int main(void)
{
    int a = readHHMM();
    int x;
    scanf("%d", &x);

    a += x;

    printWZero(a / 60);
    printf(":");
    printWZero(a % 60);
    printf("\n");

    return 0;
}

