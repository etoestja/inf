#include <stdio.h>

#define NMAX 100000

struct ath
{
    int m;
    int f;
} arr[NMAX];

int cmp_ath(const void *p1, const void *p2)
{
    struct ath a = *((struct ath*) p1);
    struct ath b = *((struct ath*) p2);

    if(a.m != b.m)
        return(a.m > b.m ? 1 : -1);
    else if(a.f != b.f)
        return(a.f > b.f ? 1 : -1);
    else return 0;
}

int main()
{
    int i, N;
    scanf("%d", &N);

    for(i = 0; i < N; i++)
    {
        scanf("%d", &(arr[i].m));
        scanf("%d", &(arr[i].f));
    }

    qsort(arr, N, sizeof(struct ath), cmp_ath);

    int h = 0;
    int mSum = 0;
    for(i = 0; i < N; i++)
    {
        if(arr[i].f >= mSum)
        {
            h++;
            mSum += arr[i].m;
        }
    }

    printf("%d\n", h);

    return 0;
}
