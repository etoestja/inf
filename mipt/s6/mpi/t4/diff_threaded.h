#ifndef DIFF_THREADED_H
#define DIFF_THREADED_H

#include <semaphore.h>

typedef struct
{
    int i_start;
    int i_end;
    volatile double* v_right;
    volatile double* v_left;
    sem_t* s_right;
    sem_t* s_left;
    volatile double* res;
} diff_threaded_params;

void* diff_thread(void* a);

#endif
