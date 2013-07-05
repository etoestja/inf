#include <stdio.h>
#include <stdlib.h>

#define NMAX 10001
#define tNMAX 1024

struct res
{
    long long int s;
    int t;
    int Place[tNMAX];
} arr[NMAX], arrSorted[NMAX];

int res_cmp(const void *p1, const void *p2)
{
    struct res res1 = *((struct res*) p1);
    struct res res2 = *((struct res*) p2);

    if(res1.s == res2.s) return 0;
    return(res1.s > res2.s ? -1 : 1);
}

int readBit()
{
    int i, k, res = 0, c;

    scanf("%d", &k);
    for(i = 0; i < k; i++)
    {
        scanf("%d", &c);
        res |= (1 << c);
    }

    return res;
}

int main()
{
    int N, i, k;

    scanf("%d", &N);
    scanf("%d", &k);

    for(i = 0; i < N; i++)
    {
        scanf("%d", &(arr[i].s));
        arr[i].t = readBit();

        arrSorted[i] = arr[i];
    }

    qsort(arrSorted, N, sizeof(struct res), res_cmp);

    int qPlace, qGroup = 0, prevScore;

    int qBit;
    for(qBit = 0; qBit < (1 << k); qBit++)
    {
        for(i = 0; i < N; i++)
        {
            if( )
        }
    }

    return 0;
}
