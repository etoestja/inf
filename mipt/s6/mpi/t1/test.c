#include "integrate.h"
#include <stdio.h>

double f(double x)
{
    return(4. / (1 + x * x));
}

int main(int argc, char** argv)
{
    double a = 0;
    double b = 1;
    unsigned N = 10000;
    double eps = 1e-6;
//    printf("%lf %lf %u %lf\n", a, b, N, integrate(f, N, a, b));
    printf("%lf %lf %u %lf\n", a, b, N, integrateAuto(f, a, b, eps));

    return(0);
}
