#include "integrate.h"
#include <math.h>
#include <stdio.h>

double integrate(DDFunc f, unsigned N, double a, double b)
{
    fprintf(stderr, "integrate 0x%lx %u %lf %lf\n", f, N, a, b);
    double res = 0;
    res += f(a) / 2 + f(b) / 2;
    unsigned i;
    for(i = 1; i < N; i++)
    {
        res += f(a + (b - a) * i / N);
    }
    return(res * (b - a) / N);
}

double integrateAuto(DDFunc f, double a, double b, double eps)
{
    fprintf(stderr, "integrateAuto 0x%lx %lf %lf %lf\n", f, a, b, eps);
    unsigned N0 = 10;
    double res_old, res;
    unsigned N;
    for(N = N0; ; N *= 2)
    {
        res = integrate(f, N, a, b);
        if(N > N0)
        {
            if(res_old != 0 && fabs((res_old - res) / res_old) < eps)
                return(res);
            else if(res_old == 0)
            {
                fprintf(stderr, "Error defining accuracy!\n");
                return(0);
            }
        }
        res_old = res;
    }
}
