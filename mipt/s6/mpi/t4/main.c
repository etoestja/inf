#include <stdio.h>
#include <stdlib.h>
#include "diff_threaded.h"
#include "exact.h"
#include "constants.h"
#include "diff_single.h"

int main(int argc, char** argv)
{
    if(argc < 2)
    {
        printf("Usage: %s p\n", argv[0]);
        return(1);
    }

    printf("c = %lf T = %lf h = %lf tau = %lf X = %lf P = %d N = %d\n", c, T, h, tau, X, P, N);
    get_differential_single();

    int p = atoi(argv[1]);

    solve_threaded(p);
    free(single_res);

    return(0);
}

