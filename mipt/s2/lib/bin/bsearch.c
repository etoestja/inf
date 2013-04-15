#include "bsearch.h"

double * bfind(double * arr, unsigned int N, unsigned int l, unsigned int r, double value)
{
    if(N == 0 || l >= N || r >= N || l > r) return(0);
    unsigned int m;
    while(r - l > 1)
    {
        m = (l + r) / 2;
        if(arr[m] > value) r = m;
        else l = m;
    }
    // r - l <= 1
    m = l;
    if(arr[m] != value) m++;
    if(arr[m] != value) return(0);
    return(&(arr[m]));
}
