#include "integrate.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <semaphore.h>
#include <string.h>
#include <sys/types.h>
#include "stderr.h"

#define PARTIAL(x,y) (sin((x)) <= (y) ? (x) * (y) : 0)

void* integrate_thread(void* a)
{
    integrate_params params_local;
    memcpy((void*) &params_local, a, sizeof(integrate_params));

    StdErr("[int_thread]\tseed %d %d", params_local.seed_x, params_local.seed_y);

    double res = integrate(&params_local);

    if(params_local.sem)
        sem_wait(params_local.sem);

    if(params_local.res)
        *(params_local.res) += res;

    if(params_local.sem)
        sem_post(params_local.sem);
    
    StdErr("[int_thread]\tdone");

    if(!params_local.res)
    {
        double* ret = malloc(sizeof(double));
        *ret = res;
        return((void*) ret);
    }

    return(NULL);
}

double integrate(integrate_params* p)
{
    int i;
    double res = 0;
    for(i = 0; i <= p->N; i++)
    {
        double x = p->x1 + 1. * rand_r(&p->seed_x) * (p->x2 - p->x1) / RAND_MAX;
        double y = 1. * rand_r(&p->seed_y) / RAND_MAX;
        res += PARTIAL(x, y);
    }
    res *= (p->x2 - p->x1);
    res /= p->N;
    return(res);
}
