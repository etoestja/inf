#include <stdio.h>

#define NMAX 100

int arr[NMAX][NMAX];

int main()
{
    int N, c = 0, i, j, t;

    scanf("%d", &N);

    for(i = 0; i < N; i++)
    {
        for(j = 0; j < N; j++)
        {
            scanf("%d", &t);
            if(t && i > j)
                printf("%d %d\n", i, j);
        }
    }

    return 0;
}
