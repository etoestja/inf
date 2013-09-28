#include <stdio.h>

#define NMAX (100000 + 10)
int N, k, R;
int H[NMAX];
int l[NMAX];

// p-R.......p.......p+R
int getM(int p)
{
    int i = p - R, iM = p + R;
    if(i < 0) i = 0;
    if(iM >= N) iM = N - 1;
    int m = -1;

    for(; i <= iM; i++)
    {
        if(m == -1 || H[i] > H[m])
            m = i;
    }
    return(m);
}

int main()
{
    scanf("%d", &N);
    scanf("%d", &k);
    scanf("%d", &R);

    int i;
    for(i = 0; i < N; i++)
        scanf("%d", &(H[i]));

    for(i = 0; i < k; i++)
    {
        scanf("%d", &(l[i]));
        l[i]--; // 0...N-1
    }

    int t, m = -1, M = -1;
    for(i = 0; i < k; i++)
    {
        t = getM(l[i]); // H[m] = max H[i]
                        //    i \in [p-R, p+R]

        if(M == -1 || H[t] > M)
            M = H[t];
        if(m == -1 || H[t] < m)
            m = H[t];
    }

    printf("%d %d\n", m, M);
    return(0);
}
