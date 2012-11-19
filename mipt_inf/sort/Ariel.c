#include <stdio.h>
#include <stdlib.h>

#define NMAX 10001

struct res
{
    long long int s;
    int t;
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

    int q, M, a, qBit;

    scanf("%d", &M);

    int placeC, inGroup;
    long long int scorePrev;

    for(q = 0; q < M; q++)
    {
        scanf("%d", &a);
        a--;
        qBit = readBit();

        placeC = 0;
        scorePrev = -1;
        inGroup = 0;

        for(i = 0; i < N; i++)
        {
            if(((arr[a].t ^ arrSorted[i].t) & qBit) == 0)
            {
                if(scorePrev == -1)
                {
                    placeC = 1;
                    inGroup = 1;
                }
                else if(arrSorted[i].s == scorePrev)
                    inGroup++;
                else
                {
                    placeC += inGroup;
                    inGroup = 1;
                }

                scorePrev = arrSorted[i].s;

                if(arr[a].s == arrSorted[i].s && arr[a].t == arrSorted[i].t) break;
            }
        }

        printf("%d\n", placeC);
    }
}
