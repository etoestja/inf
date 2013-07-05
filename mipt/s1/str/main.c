#include <stdio.h>
#include <string.h>

//+1 for '\0'
#define N (1000 + 1)

char x[N], y[N];

int main()
{
    int i, si, lx, ly, found = 0;

    scanf("%s%s", x, y);

    fprintf(stderr, "strings: x=[%s] y=[%s]\n", x, y);

    lx = strlen(x);
    ly = strlen(y);

    int cLen = 0, mLen = 0, delta;
    char mP[N], cP[N];

    for(i = 0; i < lx; i++)
    {
        for(si = 0; si < ly; si++)
        {
            if(x[i] == y[si])
            {
                cLen = 1;
                cP[0] = x[i];
                found = 1;

                for(delta = 1; i + delta < lx && si + delta < ly; delta++)
                {
                    if(x[i + delta] == y[si + delta])
                    {
                        cP[cLen] = x[i + delta];
                        cLen++;
                    }
                    else
                    {
                        if(mLen < cLen)
                        {
                            mLen = cLen;
                            for(delta = 0; delta < cLen; delta++)
                                mP[delta] = cP[delta];
                            mP[delta] = 0;
                        }
                        break;
                    }
                }
            }
        }
    }

    if(!found) printf("Empty\n");
    else printf("%s\n", mP);

    return 0;
}
