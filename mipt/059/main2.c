#include <stdio.h>

#define KMAX 20
#define NMAX 1024

unsigned int arr[KMAX * NMAX + 1], len[KMAX];

int main()
{
    int K, N, i, si;

    for(i = 0; i < KMAX; i++)
        arr[i] = 0;

    scanf("%d%d", &N, &K);

    arr[0] = 1;

    for(i = 0; i < K; i++)
    {
        scanf("%d", &(len[i]));
        arr[len[i]] = 1;
    }

    for(i = 1; i < KMAX * NMAX; i++)
    {
        for(si = 0; si < K; si++)
        {
            if(i > len[si])
            {
                arr[i] |= arr[i - len[si]];
            }
        }
    }

    for(i = N; i; i--)
    {
        if(arr[i])
        {
            printf("%d\n", i);
            break;
        }
    }

    return 0;
}
