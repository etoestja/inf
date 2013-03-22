#include <stdio.h>

#define N 3

void one()
{
    int x;
    scanf("%c", &x);
    x -= '0';

    printf(x & 0b100 ? "r" : "-");
    printf(x & 0b010 ? "w" : "-");
    printf(x & 0b001 ? "x" : "-");
}

int main()
{
    int i;
    for(i = 0; i < N; i++) one();
    printf("\n");

    return(0);
}
