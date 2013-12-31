#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void randInit()
{
    srand(time(NULL));
}

#define N1 10

int randN(int N)
{
    return((rand() * ((long long) N)) / RAND_MAX);
}

int main()
{
    randInit();
    int N;
    scanf("%d", &N);

    printf("%d\n", N);

    int i, j;
    for(i = 0; i < N; i++)
    {
        for(j = 0; j < N; j++)
            printf("%ld\t", randN(N1));
        printf("\n");
    }
}
