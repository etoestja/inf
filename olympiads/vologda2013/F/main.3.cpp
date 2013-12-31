#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <string.h>

using namespace std;

#define NMAX 100005
unsigned long long arr[NMAX];
unsigned long long N, i;
unsigned long long ncount[NMAX];

inline int ucmp(unsigned long long x, unsigned long long y)
{
    return(x > y ? 1 : 0);
}

unsigned long long gcd(unsigned long long m, unsigned long long n)
{
    unsigned long long gcdt;
    while(n != 0)
    {
        gcdt = m % n;
        m = n;
        n = gcdt;
    }
    return(m);
}

int main()
{
    freopen("wheel.in", "r", stdin);
    freopen("wheel.out", "w", stdout);

    scanf("%u", &N);

    if(N == 0)
    {
        printf("0\n");
        return 0;
    }
    else if(N == 1)
    {
        printf("1\n");
        return 0;
    }

    vector<unsigned long long> arr;
    arr.resize(N + 1);

    for(i = 0; i < N; i++)
        scanf("%llu", &(arr[i]));

    sort(arr.begin(), arr.end(), ucmp);

    for(i = 0; i < N; i++) ncount[i] = 0;

    unsigned long long int uniquec = 0;
    for(i = 0; i < N; i++)
    {
        if(i > 0 && arr[i] != arr[i - 1])
            uniquec++;
        ncount[uniquec]++;
    }

    unsigned long long gcdres = ncount[0];
    for(i = 1; i < uniquec; i++)
        gcdres = gcd(gcdres, ncount[i]);

    printf("%llu\n", N / gcdres);

    return 0;
}
