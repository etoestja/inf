#include <stdio.h>

int x1, x2, x3;

int test()
{
    return((x1 + x2 + x3 <= 60) && (2 * x1 + 1 * x2 + 3 * x3 <= 100));
}

int cost()
{
    return(1000 * x1 + 1200 * x2 + 12000 * x3);
}

int main()
{
    int x1m = 40, x2m = 30, x3m = 20;

    int cmax = 0;

    for(x1 = 0; x1 <= x1m; x1++)
        for(x2 = 0; x2 <= x2m; x2++)
            for(x3 = 0; x3 <= x3m; x3++)
            {
                if(test())
                {
                    if(cost() >= cmax)
                    {
                        cmax = cost();
                        printf("cmax update c=%d\tx1=%d\tx2=%d\tx3=%d\n", cmax, x1, x2, x3);
                    }
                }
            }

     return(0);
}
