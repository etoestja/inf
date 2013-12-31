#include <stdio.h>

#define NMAX 10000

long long int arr[NMAX], N, K;

long long int able(int L)
{
    if(L == 0) return 1;

    long long int i;
    long long int Kc = 0;
    for(i = 0; i < N; i++)
        Kc += arr[i] / L;

    return(Kc >= K);
}

int main()
{
    long long int i, sum = 0;
    scanf("%lld%lld", &N, &K);

    for(i = 0; i < N; i++)
    {
        scanf("%lld", &arr[i]);
        sum += arr[i];
    }

    long long int l = 0, r = sum, m, L;
    while(l + 1 < r)
    {
//        printf("%d %d\n", l, r);
        m = (l + r) / 2;
        if(able(m)) l = m;
        else r = m;
    }
    if(able(r)) L = r;
    else L = l;

    printf("%lld\n", L);

    return 0;
}
