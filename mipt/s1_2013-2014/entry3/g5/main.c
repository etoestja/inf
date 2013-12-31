#include <stdio.h>

#define NMAX 90
#define KMAX 10

#define DEBUG

unsigned long long c[NMAX + 1][KMAX + 1];
int N, K;

int main()
{
    int i, j;

    for(i = 1; i <= 9 ; i++)
    {
        c[i][1] = 1;
        c[i][0] = 0;
    }

    for(i = 10; i <= NMAX ; i++)
    {
        c[i][1] = 0;
        c[i][0] = 0;
    }

    c[0][0] = 1;
    c[0][1] = 1;

/*#ifdef DEBUG
    for(K = 0; K <= 10; K++)
    {
        for(N = 0; N <= 10; N++)
        {
            printf("%llu ", c[N][K]);
        }
        printf("\n");
    }
#endif*/

    for(N = 0; N <= NMAX; N++)
    {
        for(K = 2; K <= KMAX; K++)
        {
            c[N][K] = 0;
            for(i = 0; i <= 9; i++)
            {
                if(N - i >= 0)
                    c[N][K] += c[N - i][K - 1];
            }
            c[N][K] *= K;
        }
    }

#ifdef DEBUG
    for(K = 0; K <= 10; K++)
    {
        for(N = 0; N <= 10; N++)
        {
            printf("%llu ", c[N][K]);
        }
        printf("\n");
    }
#endif

    scanf("%d", &N);
    scanf("%d", &K);

    printf("%llu\n", c[N][K]);

    return(0);
}
