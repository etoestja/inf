#include "constants.h"
#include "exact.h"

double g(double x)
{
    if(x < 0 || x > 2)
        return(0);
    return(x * (2 - x));
}

double exact(double x, double t)
{
    return(g(x - c * t));
}

