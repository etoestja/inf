#include "integrate.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PARTIAL(x,y) (sin((x)) <= (y) ? (x) * (y) : 0)

double integrate(int seed_x, int seed_y, double x1, double x2, unsigned N)
{
    int i;
    double res = 0;
    for(i = 0; i <= N; i++)
    {
        double x = x1 + 1. * rand_r(&seed_x) * (x2 - x1) / RAND_MAX;
        double y = 1. * rand_r(&seed_y) / RAND_MAX;
        res += PARTIAL(x, y);
    }
    res *= (x2 - x1);
    res /= N;
    return(res);
}
