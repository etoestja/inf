#include "constants.h"
#include "exact.h"

double exact(double x, double t)
{
    return(g(x - c * t));
}

