#include "int_threaded.h"
#include "stderr.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

const char* modes[] = {"shared", "ret"};

void print_exact()
{
    double exact = M_PI * M_PI / 8.;
    StdErr("[main]\t\tEXACT: %lf", exact);
}

int main(int argc, char** argv)
{
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

    if(n * P != N)
        StdErr_f("[main]\t\tWarning: N = %d not divisable by %d = P. Skipped %d points", N, P, N - n * P);

    if(N < P)
    {
        printf("N = %d < %d = P. Can't continue\n", N, P);
        return(1);
    }

    print_exact();

    StdErr("[main]\t\tN = %d P = %d n = %d mode = %s", N, P, n, mode == MODE_RET ? "ret" : "shared");

    double res = integrate_threaded(P, n, mode);

    StdErr_f("[main]\t\tres = %lf", res);

    return(0);
}
