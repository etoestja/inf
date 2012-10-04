#include <stdio.h>
#include <string.h>

#define NMAX (1000 + 5)

#define max(a, b) (a > b ? a : b)

struct c
{
    int x;
    int y;
};

int len[NMAX][NMAX];

char x[NMAX], y[NMAX];

int main()
{
    scanf("%s%s", x, y);

    int lx, ly, ix, iy, t;

    lx = strlen(x);
    ly = strlen(y);

    for(ix = 0; ix < NMAX; ix++)
    {
        len[0][ix] = 0;
        len[ix][0] = 0;
    }

    for(ix = 1; ix <= lx; ix++)
    {
        for(iy = 1; iy <= ly; iy++)
        {
            len[ix][iy] = 0;

            fprintf(stderr, "%d, %d (%c, %c): ", ix, iy, x[ix - 1], y[iy - 1]);

            if(x[ix - 1] == y[iy - 1])
            {
                len[ix][iy]++;
                fprintf(stderr, "equal ");
            }
            t = max(len[ix - 1][iy], len[ix][iy - 1]);
            len[ix][iy] += t;

            fprintf(stderr, "prev %d sum %d\n", t, len[ix][iy]);
        }
    }

    fprintf(stderr, "  ");
    for(iy = 0; iy < ly; iy++)
        fprintf(stderr, "%c ", y[iy]);
    fprintf(stderr, "\n");

    for(ix = 1; ix <= lx; ix++)
    {
        fprintf(stderr, "%c ", x[ix - 1]);
        for(iy = 1; iy <= ly; iy++)
        {
            fprintf(stderr, "%d ", len[ix][iy]);
        }
        fprintf(stderr, "\n");
    }

    printf("%d\n", len[lx][ly]);

    return 0;
}
