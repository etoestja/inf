#include <stdio.h>
#include <stdlib.h>
#include "diff_threaded.h"
#include "exact.h"
#include "constants.h"
#include "diff_single.h"
#include "timedist.h"

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

    struct timeval t1, t2;
    gettimeofday(&t1, NULL);
    solve_threaded(p);
    gettimeofday(&t2, NULL);
    free(single_res);

    fprintf(stderr, "TIME = %llf\n", time_dist(&t1, &t2));

    return(0);
}

