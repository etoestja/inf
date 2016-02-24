#include "integrate.h"

double integrate(DDFunc f, unsigned N, double a, double b)
{
    double res = 0;
    res += f(a) / 2 + f(b) / 2;
    unsigned i;
    for(i = 1; i < N; i++)
    {
        res += f(a + (b - a) * i / N);
    }
    return(res * (b - a) / N);
}
