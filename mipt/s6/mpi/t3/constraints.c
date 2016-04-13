#include "constraints.h"
#include <math.h>

bool isInside(double x, double y)
{
    return(x >= 0 && x <= M_PI && y >= 0 && y <= sin(x));
}
