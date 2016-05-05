#include <stdio.h>
#include "exact.h"
#include "constants.h"
#include "diff_single.h"

int main(int argc, char** argv)
{
    printf("c = %lf T = %lf h = %lf tau = %lf X = %lf P = %d N = %d\n", c, T, h, tau, X, P, N);

    print_differential_single();

    return(0);
}

