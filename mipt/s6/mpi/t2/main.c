#include <stdio.h>
#include "exact.h"
#include "config.h"

int main()
{
    double t, x;
    for(t = 0; t <= T; t += 0.001)
    {
        for(x = 0; x <= l; x += 0.05)
            printf("%0.2lf\t", getExactSolution(x, t));
        printf("\n");
    }

    return(0);
}
