#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <string.h>

using namespace std;

unsigned N, i, j;
unsigned M;
//1000000000
//4294967296

#define PiB 54
#define PiA 6
#define  sB 6
#define NMAX 10005

bool arr[NMAX * (PiB + 6 + 1)];
unsigned zeros[NMAX * (PiB + 6 + 1)];

bool ablelr(unsigned l, unsigned r)
{
    if(l == r) return(arr[l] == 0 && M <= 1);
    if((zeros[r] - zeros[l] + 1) >= M) return(true);
    return(false);
}

int main()
{
    freopen("train.in", "r", stdin);
    //freopen("train.out", "w", stdout);

    scanf("%u", &N);
    scanf("%u", &M);

    char t;

    for(i = 0; i < N; i++)
    {
        //block A
        for(j = 1; j <= PiB; j++)
        {
            scanf("%c", &t);
            if(j <= 35)
            {
                arr[i * (PiB + sB) + ((j - 1) / 4) * PiA + (j % 4 - 1)] = (t == '1' ? 1 : 0);
            }
            else
            {
                int C = 8 - (j - 37);
                arr[i * (PiB + sB) + C * PiA + j % 2] = (t == '1' ? 1 : 0);
            }
            for(j = 54; j < PiB + sB; j++) arr[i * (PiB + sB) + j] = 1;
        }
    }

    unsigned Len = N * (54 + 6);

    for(i = 0; i < Len; i += 6)
    {
        printf("[%d %d %d %d | %d %d]", arr[i], arr[i + 1], arr[i + 1], arr[i + 1], arr[i + 1], arr[i + 1], arr[i + 1])
    }

    if(arr[0] == 0) zeros[0] = 1;
    for(i = 1; i < Len; i++)
    {
        zeros[i] = zeros[i - 1];
        if(arr[i] == 0) zeros[i]++;
    }

    unsigned l, m, r;
    unsigned distance, minDistance = -1;

    for(i = 0; i < Len; i++)
    {
        l = i;
        r = Len - 1;
        while(l + 1 < r)
        {
            m = (l + r) / 2;
            if(ablelr(i, m)) r = m;
            else l = m;
        }
        if(ablelr(i, l)) r = l;
        if(ablelr(i, r))
        {
            cout << "found i=" << i << " r=" << r << endl;
            distance = (i / PiA) - (r / PiA);
            if(distance < minDistance) minDistance = distance;
        }
    }

    printf("%d\n", minDistance);

    return 0;
}
