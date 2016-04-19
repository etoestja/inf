#include "int_threaded.h"
#include "stderr.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "timedist.h"

const char* modes[] = {"shared", "ret"};

void print_exact()
{
    double exact = M_PI * M_PI / 8.;
    StdErr("[main]\t\tEXACT: %lf", exact);
}

int main(int argc, char** argv)
{
    struct timeval t1, t2;

    if(argc < 3)
    {
        printf("Usage: %s n_threads N_points [mode]\n", argv[0]);
        printf("mode: %s (default) -- use shared memory variable for the result\n", modes[MODE_SHARED]);
        printf("mode: %s -- use thread return value\n", modes[MODE_RET]);
        return(1);
    }

    int P = atoi(argv[1]);
    int N = atoi(argv[2]);
    int n = N / P;

    int mode = MODE_SHARED;
    if(argc == 4 && !strcmp(argv[3], modes[MODE_RET]))
        mode = MODE_RET;

    int d = N - n * P;

    if(N < P)
    {
        printf("N = %d < %d = P. Can't continue\n", N, P);
        return(1);
    }

    print_exact();

    StdErr("[main]\t\tN = %d P = %d n = %d d = %d mode = %s", N, P, n, d, mode == MODE_RET ? "ret" : "shared");


    gettimeofday(&t1, NULL);
    double res = integrate_threaded(P, n, d, mode);
    gettimeofday(&t2, NULL);

    StdErr("[main]\t\tres = %lf", res);
    fprintf(stderr, "TIME = %llf\n", time_dist(&t1, &t2));

    return(0);
}
