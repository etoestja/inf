#include "exact.h"
#include "config.h"
#include <math.h>

double getExactSolutionTerm(double x, double t, unsigned m)
{
    return(exp(-k * M_PI * M_PI * (2 * m + 1) * t / l / l) * sin(M_PI * (2 * m + 1) * x / l) / (2 * m + 1));
}

double getExactSolution(double x, double t)
{
    double coef = 4 * u_0 / M_PI;
    int m;
    double res = 0;
    for(m = 0; ; m++)
    {
        double term = getExactSolutionTerm(x, t, m);
        res += term;

        if(1. < EXACT_EPS * (2 * m + 1))
            break;
    }
    return(res * coef);
}
