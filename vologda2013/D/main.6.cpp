#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

#define NMAX 100000
#define uswap(x, y) {t = x; x = y; y = t;}
unsigned arr[NMAX];
unsigned N, i;

inline int ucmp(const void* x, const void* y)
{
    return((*(unsigned*)x) > (*(unsigned*)y) ? 1 : -1);
}

unsigned gcd(unsigned x, unsigned y)
{
    unsigned t;
    if(x > y)
        swap(x, y);
    while(x < y && x > 0)
    {
        y = y % x;
        swap(x, y);
        //cout << x << " " << y << endl;
    }
    return(y);
}

int main()
{
    //unsigned t1, t2;
    //cin >> t1 >> t2;
    //cout << gcd(t1, t2) << endl;
    //return(0);

    scanf("%u", &N);
    for(i = 0; i < N; i++)
    {
        scanf("%u", &(arr[i]));
    }

    qsort(arr, N, sizeof(unsigned), ucmp);

    for(i = 0; i < N; i++)
            printf("%d %u\n", i, arr[i]);

    int t = 0;
    vector<unsigned> count;
    count.assign(NMAX + 1, 0);
    for(i = 0; i < N; i++)
    {
        if(!(i == 0 || arr[i] == arr[i - 1]))
            t++;
        count[t]++;
    }
    //if(count[t] == 0) count[t]++;

    //vector<unsigned>::iterator it;
    //for(it = count.begin(); it != count.end(); it++)
    //    if(*it) cout << *it << endl;

    unsigned gcdres = count[0];
        for(i = 1; i < N; i++)
            gcdres = gcd(gcdres, count[i]);

    cout << gcdres << endl;

    return 0;
}
