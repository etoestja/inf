#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <string.h>
#include <fstream>

using namespace std;

#define NMAX 100005
unsigned long arr[NMAX];
unsigned long N, i;
unsigned long ncount[NMAX];

inline int ucmp(unsigned long x, unsigned long y)
{
    return(x > y ? 1 : 0);
}

unsigned long gcd(unsigned long m, unsigned long n)
{
    unsigned long gcdt;
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
    ifstream if("wheel.in");
    freopen("wheel.in", "r", stdin);
    freopen("wheel.out", "w", stdout);

    scanf("%llu", &N);

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

    vector<unsigned long> arr;
    arr.resize(N + 1);

    for(i = 0; i < N; i++)
        scanf("%lu", &(arr[i]));

    sort(arr.begin(), arr.end(), ucmp);

    for(i = 0; i < N; i++) ncount[i] = 0;

    unsigned long int uniquec = 0;
    for(i = 0; i < N; i++)
    {
        if(i > 0 && arr[i] != arr[i - 1])
            uniquec++;
        ncount[uniquec]++;
    }

    unsigned long gcdres = ncount[0];
    for(i = 1; i < uniquec; i++)
        gcdres = gcd(gcdres, ncount[i]);

    printf("%lu\n", N / gcdres);

    return 0;
}
