#include <stdio.h>

int main()
{
    int N = 1000, K = 100000, Kc = 0;
    int i, j, k;

    printf("%d %d\n", N, K);

    for(i = 1; i <= N; i++)
        for(j = 1; j <= N; j++)
            for(k = 1; k <= N; k++)
            {
                if(Kc >= K)
                {
                    i = j = k = N + 1;
                    break;
                }

                printf("%d %d %d\n", i, j, k);

                Kc++;
            }

    printf("1 1 %d\n", N);

    return 0;
}
