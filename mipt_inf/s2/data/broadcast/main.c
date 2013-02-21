#include <stdio.h>

#define M 4
int x[M], y[M];

int main()
{
    int i, t;
    char c;
    for(i = 0; i < M; i++)
    {
        scanf("%d", &t);
        if(i <= 2) scanf("%c", &c);
        x[i] = t;
    }

    for(i = 0; i < M; i++)
    {
        scanf("%d", &t);
        if(i <= 2) scanf("%c", &c);
        y[i] = t;
    }


    const unsigned int K = 8;
    int si;
    unsigned int r;

    for(i = 0; i < M; i++)
    {
        r = 0;
        for(si = K - 1; si >= 0; si--)
        {
            if(y[i] & (1 << si)) r += (1 << si) * ((x[i] & (1 << si)) ? 1 : 0);
            else r += (1 << si);
        }
        printf("%d", r);
        if(i <= 2) printf(".");
    }

    printf("\n");

    return(0);
}
