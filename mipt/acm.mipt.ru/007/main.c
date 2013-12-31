#include <stdio.h>

#define NMAX (20 + 1)

int arr[NMAX][NMAX][NMAX];
int sum[NMAX][NMAX][NMAX];

int main()
{
    int i, j, k, M, N, D;

    scanf("%d%d%d", &N, &D, &M);

    for(i = 0; i <= M; i++)
        for(j = 0; j <= N; j++)
            for(k = 0; k <= D; k++)
                sum[i][j][k] = 0;


    for(i = 0; i < M; i++)
        for(j = 0; j < N; j++)
            for(k = 0; k < D; k++)
            {
                scanf("%d", &(arr[i][j][k]));
                sum[i + 1][j + 1][k + 1] = sum[i][j + 1][k + 1] + sum[i + 1][j][k + 1] + sum[i + 1][j + 1][k] - sum[i + 1][j][k] - sum[i][j + 1][k] - sum[i][j][k + 1] + sum[i][j][k] + arr[i][j][k];
            }

    /*for(i = 1; i <= M; i++)
    {
        for(j = 1; j <= N; j++)
            printf("%d ", sum[i][j][1]);
        printf("\n");
    }*/

    int mmin, mmax, nmin, nmax, dmin, dmax, smax = arr[0][0][0], st;

    for(mmin = 1; mmin <= M; mmin++)
        for(mmax = mmin; mmax <= M; mmax++)
            for(nmin = 1; nmin <= N; nmin++)
                for(nmax = nmin; nmax <= N; nmax++)
                    for(dmin = 1; dmin <= D; dmin++)
                        for(dmax = dmin; dmax <= D; dmax++)
                        {
                            //printf("%d %d, %d %d, %d %d\n", mmin, mmax, nmin, nmax, dmin, dmax);
                            st = sum[mmax][nmax][dmax] - sum[mmin - 1][nmax][dmax] - sum[mmax][nmin - 1][dmax] - sum[mmax][nmax][dmin - 1]
                                + sum[mmax][nmin - 1][dmin - 1] + sum[mmin - 1][nmax][dmin - 1] + sum[mmin - 1][nmin - 1][dmax]
                                - sum[mmin - 1][nmin - 1][dmin - 1];

                            //printf("st=%d\n", st);
                            if(st > smax) smax = st;
                        }
    printf("%d\n", smax);

    return 0;
}
