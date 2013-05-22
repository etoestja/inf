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
    freopen("circles.in", "r", stdin);
    freopen("circles.out", "w", stdout);
    scanf("%u", &N);
    for(i = 0; i < N; i++)
        scanf("%u", &(arr[i]));

    qsort(arr, N, sizeof(unsigned), ucmp);

    int j, k = 0;
    unsigned long long C1 = 0, C2 = 0;

    for(j = N - 1; j >= 0; j--)
    {
        //cerr << arr[j] << endl;
        if(k % 2 == 0)
        {
            C1 += arr[j] * arr[j];
            if(j > 0)
                C1 -= arr[j - 1] * arr[j - 1];
        }
        else
        {
            C2 += arr[j] * arr[j];
            if(j > 0)
                C2 -= arr[j - 1] * arr[j - 1];
        }
        k++;
    }
    //64000000000000
    //18446744073709551616

    //cerr << C1 << endl;
    //cerr << C2 << endl;
    printf("%s", (C1 > C2 ? "YES" : "NO"));
    return(0);
}
