#include <stdio.h>

int main()
{
    int i, N = 29;
    for(i = 1; i <= N; i++)
    {
        if(i < 10) printf(" ");
        printf("%d,      ", i);
    }

    printf("\n");

    return 0;
}
