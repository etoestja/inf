#ifndef INTEGRATE_H
#define INTEGRATE_H

#include <semaphore.h>

typedef struct
{
    int seed_x;
    int seed_y;
    double x1;
    double x2;
    unsigned N;
    sem_t* sem;
    volatile double* res;
} integrate_params;

double integrate(integrate_params* p);
void* integrate_thread(void* a);

#endif
