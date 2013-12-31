#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

#define NMAX 40010
#define uswap(x, y) {t = x; x = y; y = t;}
unsigned arr[NMAX];
unsigned N, i;

inline int ucmp(const void* x, const void* y)
{
    return((*(unsigned*)x) > (*(unsigned*)y) ? 1 : -1);
}

int main()
{
    scanf("%u", &N);
    for(i = 0; i < N; i++)
        scanf("%u", &(arr[i]));

    qsort(arr, N, sizeof(unsigned), ucmp);

    int j;
    for(j = N - 1; i < N; i++)
    {
        f
    }
}
