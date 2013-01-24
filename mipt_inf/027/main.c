#include <stdio.h>

#define NMAX (1000000 + 1)

char arr[NMAX];

int main(void)
{
    int i, N, t;
    for(i = 0; i < NMAX; i++) arr[i] = 0;

    scanf("%d", &N);
    for(i = 0; i < N; i++)
    {
        scanf("%d", &t);
        arr[t] ^= 1;
    }

    for(i = 0; i < NMAX; i++)
        if(arr[i])
        {
            printf("%d\n", i);
            break;
        }

    return(0);

    return 0;
}

