#include "constants.h"
#include "diff_single.h"
#include "exact.h"
#include "diff_threaded.h"
#include <pthread.h>
#include <stdlib.h>
#include "stderr.h"
#include <string.h>

void solve_threaded(int p)
{
    StdErr("[solve_threaded] starting p = %d", p);

    pthread_t* threads = (pthread_t*) malloc(sizeof(pthread_t) * p);
    diff_threaded_params* params = (diff_threaded_params*) malloc(sizeof(diff_threaded_params) * p);
    volatile double* res = (volatile double*) malloc(sizeof(double) * (N + 1));
    bzero((void*) res, sizeof(double) * (N + 1));

    int i;
    if(N < p)
    {
        StdErr_f("[solve_threaded] N = %d < %d = p", N, p);
        free(threads);
        free(params);
        free((void*) res);
        return;
    }

    int current_start_point = 1;
    for(i = 0; i < p; i++)
    {
        int n = (N) / p + (i < ((N) % p) ? 1 : 0);
        params[i].i_start = current_start_point;
        params[i].i_end = current_start_point + n - 1;
        current_start_point += n;

        params[i].rank = i;

        if(i == 0)
        {
            params[i].v_left = NULL;
            params[i].s_left = NULL;
            params[i].w_left = NULL;
        }
        else
        {
            params[i].v_left = params[i - 1].v_right;
            params[i].s_left = params[i - 1].s_right;
            params[i].w_left = params[i - 1].w_right;
        }

        if(i == p - 1)
        {
            params[i].v_right = NULL;
            params[i].s_right = NULL;
            params[i].w_right = NULL;
        }
        else
        {
            params[i].v_right = (double*) malloc(sizeof(double));
            params[i].s_right = (sem_t*) malloc(sizeof(sem_t));
            params[i].w_right = (sem_t*) malloc(sizeof(sem_t));
            sem_init(params[i].s_right, 0, 0);
            sem_init(params[i].w_right, 0, 0);
        }

        params[i].res = res;
    }

    StdErr("[solve_threaded] starting threads");

    for(i = 0; i < p; i++)
        pthread_create(&threads[i], NULL, diff_thread, (void*) &params[i]);

    StdErr("[solve_threaded] waiting...");

    for(i = 0; i < p; i++)
        pthread_join(threads[i], NULL);

    StdErr("[solve_threaded] wait OK");

    for(i = 0; i <= N; i++)
    {
        StdErr("x = %0.2lf diff %0.2lf single %0.2lf exact %0.2lf", i * h, res[i], single_res ? single_res[i] : 0, exact(i * h, T));
    }

    StdErr("[solve_threaded] free...");

    for(i = 0; i < p - 1; i++)
    {
        free((double*) params[i].v_right);
        sem_destroy(params[i].s_right);
        free((void*) params[i].s_right);
        sem_destroy(params[i].w_right);
        free((void*) params[i].w_right);
    }

    free(threads);
    free(params);
    free((void*) res);

    StdErr("[solve_threaded] done");
}
