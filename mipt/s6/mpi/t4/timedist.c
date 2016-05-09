#include "timedist.h"

long double timeval_to_dd(struct timeval *t)
{
    long sec = t->tv_sec;
    long usec = t->tv_usec;

    long double res = sec;
    long double res1 = usec;
    res1 /= 1e6;
    res += res1;
    return(res);
}

long double time_dist(struct timeval *t1, struct timeval *t2)
{
    return(timeval_to_dd(t2) - timeval_to_dd(t1));
}

