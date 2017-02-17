#include <stdio.h>
#include <omp.h>

const int N = 100000000;

int main()
{
#ifdef _OPENMP
    int i;
    double t1 = omp_get_wtime();
#pragma omp parallel for
    for(i = 0; i < N; i++)
        omp_get_wtime();
    double t2 = omp_get_wtime();
    double delta = (t2 - t1) / N;
    double tick = omp_get_wtick();
    printf("avg = %.15lf tick = %.9lf %lf\n", delta, tick, delta / tick);
#endif
}
