#include "diff_threaded.h"
#include "constants.h"
#include "stderr.h"
#include <semaphore.h>
#include <string.h>
#include <stdlib.h>

#define SWAPD(x,y) {double* t = (x); (x) = (y); (y) = t;}

void* diff_thread(void* a)
{
    if(a == NULL)
    {
        StdErr_f("[diff_thread] a == NULL");
        return(0);
    }

    diff_threaded_params p;
    memcpy(&p, a, sizeof(diff_threaded_params));

    StdErr("[diff_thread] start %d end %d left 0x%x 0x%x right 0x%x 0x%x res 0x%x", p.i_start, p.i_end, p.v_left, p.s_left, p.v_right, p.s_right, p.res);

    int n = p.i_end - p.i_start + 1;
    double* old = malloc(sizeof(double) * (n + 1));
    double* new = malloc(sizeof(double) * (n + 1));

    int i;
    for(i = 0; i <= n; i++)
        old[i + 1] = g((i + p.i_start) * h);

    StdErr("[diff_thread] starting iterations...");

    int t;
    for(t = 0; t < P; t++)
    {
        for(i = 1; i <= n; i++)
            new[i] = old[i] * (1 - c * tau / h) + c * tau / h * old[i - 1];

        if(p.v_right)
        {
            StdErr("start %d t %d sent %lf", p.i_start, t, new[n]);
            *p.v_right = new[n];
        }
        if(p.s_right)
            sem_post(p.s_right);

        if(p.s_left)
            sem_wait(p.s_left);
        new[0] = p.v_left ? *p.v_left : LEFT;
        StdErr("start %d t %d got %lf", p.i_start, t, new[0]);

        SWAPD(old, new);
    }

    StdErr("[diff_thread] copying result...");

    for(i = p.i_start; i <= p.i_end; i++)
        p.res[i] = old[i - p.i_start + 1];

    StdErr("[diff_thread] done");

    return(0);
}
