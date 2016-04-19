#include "integrate.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    double exact = M_PI * M_PI / 8;
    printf("EXACT: %lf\n", exact);

    double res = integrate(1, 10, 0, M_PI / 2, 100000) + integrate(0, 66, M_PI / 2  , M_PI, 100000);

    printf("res = %lf\n", res   );
}
