#include "int_threaded.h"
#include "integrate.h"
#include "stderr.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double integrate_threaded(int P, int n, int mode)
{
    pthread_t* threads = malloc(sizeof(pthread_t) * P);
    integrate_params* params = malloc(sizeof(integrate_params) * P);

    sem_t sem;
    double res = 0;

    sem_init(&sem, 0, 1);

    int i;
    for(i = 0; i < P; i++)
    {
        params[i].seed_x = i;
        params[i].seed_y = P + i;
        params[i].x1 = 0;
        params[i].x2 = M_PI;
        params[i].N = n;

        if(mode == MODE_SHARED)
        {
            params[i].sem = &sem;
            params[i].res = &res;
        }
        else if(mode == MODE_RET)
        {
            params[i].sem = NULL;
            params[i].res = NULL;
        }

        pthread_create(&threads[i], NULL, integrate_thread, (void*) &params[i]);
    }

    for(i = 0; i < P; i++)
    {
        if(mode == MODE_RET)
        {
            double* res1;
            pthread_join(threads[i], &res1);
            res += *res1;
            free(res1);
        }
        else if(mode == MODE_SHARED)
            pthread_join(threads[i], NULL);
    }

    res /= P;

    free(threads);
    free(params);

    return(res);
}
