#include <stdio.h>
#include <string.h>

#define DEBUG 0

#define NMAX (1000 + 5)

#define max(a, b) (a > b ? a : b)

struct c
{
    int x;
    int y;
};

int len[NMAX][NMAX];

char x[NMAX], y[NMAX];

char resBackwards[NMAX];

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
            if(DEBUG) fprintf(stderr, "%d, %d (%c, %c): ", ix, iy, x[ix - 1], y[iy - 1]);

            if(x[ix - 1] == y[iy - 1])
            {
                len[ix][iy] = len[ix - 1][iy - 1] + 1;
                if(DEBUG) fprintf(stderr, "equal ");
            }
            else
            {
                if(DEBUG) fprintf(stderr, "not equal ");
                len[ix][iy] = max(len[ix - 1][iy], len[ix][iy - 1]);
            }

            if(DEBUG) fprintf(stderr, "prev %d sum %d\n", t, len[ix][iy]);
        }
    }

    if(DEBUG)
    {
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

        fprintf(stderr, "%d\n", len[lx][ly]);
    }

    char* resBP = (char*) &(resBackwards);
    int prev;

    int prev_ix, prev_iy;

    for(ix = lx, iy = ly; ix > 0 || iy > 0;)
    {
        prev_ix = 0;
        prev_iy = 0;
        if(ix > 0 && len[ix - 1][iy] > len[prev_ix][prev_iy])
        {
            prev_ix = ix - 1;
            prev_iy = iy;
        }
        if(iy > 0 && len[ix][iy - 1] > len[prev_ix][prev_iy])
        {
            prev_ix = ix;
            prev_iy = iy - 1;
        }
        if(len[prev_ix][prev_iy] < len[ix][iy])
//            printf("%c", x[ix - 1]);
            *(resBP++) = x[ix - 1];

        ix = prev_ix;
        iy = prev_iy;
    }

    if(resBP != (char*) &resBackwards)
        for(; resBP >= (char*) &(resBackwards); resBP--)
            printf("%c", *resBP);
    else
        printf("Empty");

    printf("\n");

    return 0;
}
