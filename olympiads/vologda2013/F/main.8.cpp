#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <string.h>

using namespace std;

#define NMAX 100000
#define uswap(x, y) {t = x; x = y; y = t;}
unsigned arr[NMAX];
unsigned N, i;

inline int ucmp(unsigned x, unsigned y)
{
    return(x > y ? 1 : 0);
}

gcd

unsigned gcd(unsigned x, unsigned y)
{
    unsigned t;
    if(x > y)
        swap(x, y);
    while(x < y && x > 0)
    {
        //t = y;
        y = y % x;
        //y = t;
        swap(x, y);
        //cout << x << " " << y << endl;
    }
    return(y);
}

unsigned ncount[NMAX];

int main()
{
    freopen("wheel.in", "r", stdin);
    //freopen("wheel.out", "w", stdout);
    scanf("%u", &N);
    vector<unsigned> arr;
    arr.resize(N);
    for(i = 0; i < N; i++)
    {
        scanf("%u", &(arr[i]));
    }
    sort(arr.begin(), arr.end(), ucmp);
    //qsort(arr, N, sizeof(unsigned), ucmp);

    for(i = 0; i < N; i++) ncount[i] = 0;

    unsigned int t = 0;
    for(i = 0; i < N; i++)
    {
        if(i > 0 && arr[i] != arr[i - 1])
            t++;
        ncount[t]++;
    }

    unsigned gcdres = ncount[0];
    for(i = 1; i < t; i++)
        gcdres = gcd(gcdres, ncount[i]);

    printf("%u\n", N / gcdres);

    return 0;
}
