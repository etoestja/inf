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
#define  sB 30
#define NMAX 10005

bool arr[NMAX * (PiB + sB + 1)];
unsigned zeros[NMAX * (PiB + sB + 1)];

bool ablelr(unsigned l, unsigned r)
{
    if(l == r) return(arr[l] == 0 && M <= 1);
    if((zeros[r] - zeros[l] + (arr[r] == 0 ? 1 : 0)) >= M) return(true);
    return(false);
}

int main()
{
    freopen("train.in", "r", stdin);
    //freopen("train.out", "w", stdout);

    scanf("%u", &N);
    scanf("%u", &M);

    char t;

    scanf("%c", &t);
    for(i = 0; i < N; i++)
    {
        //block A
        for(j = 1; j <= PiB; j++)
        {
            t = 2;
            while(t(scanf("%c", &t);
            cerr << "ss: " << t << " ";
            if(j <= 36)
            {
                cout << "j=" << j << " index=" << i * (PiB + sB) + ((j - 1) / 4) * PiA + ((j - 1) % 4) << endl;
                arr[i * (PiB + sB) + ((j - 1) / 4) * PiA + ((j - 1) % 4)] = (t == '1' ? 1 : 0);
            }
            else
            {
                int C = 8 - (j - 37) / 2;
                cout << "indeX=" << i * (PiB + sB) + C * PiA + (j + 1) % 2 + 4 << endl;

                arr[i * (PiB + sB) + C * PiA + (j + 1) % 2 + 4] = (t == '1' ? 1 : 0);
            }
        }
        for(j = 54; j < PiB + sB; j++) arr[i * (PiB + sB) + j] = 1;
        scanf("%c", &t);
    }

    unsigned Len = N * (PiB + sB);

    for(i = 0; i < Len; i += PiA)
    {
        printf("[%d %d %d %d | %d %d] ", arr[i], arr[i + 1], arr[i + 2], arr[i + 3], arr[i + 4], arr[i + 5]);
    }

    zeros[0] = 0;
    for(i = 1; i < Len; i++)
    {
        zeros[i] = zeros[i - 1];
        if(arr[i - 1] == 0) zeros[i]++;
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
            distance = (r / PiA) - (i / PiA);
            cout << "found i=" << i << " r=" << r << " d=" << distance << endl;
            if(distance < minDistance) minDistance = distance;
        }
    }

    printf("%d\n", minDistance);

    return 0;
}
