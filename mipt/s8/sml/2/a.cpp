#include <stdio.h>

#define K 25
#define VMAX (1 << K)

int count[K + 1];

#define abs(x) ((x) > 0 ? (x) : -(x))

int get_idx(int r)
{
    if(r >= 0 && r <= K)
        return(r);
    else
        return(K - r);
}

int main()
{
    unsigned long long v = 0;
    for(int i = 0; i < 2 * K + 1; i++)
        count[i] = 0;
    for(v = 0; v <= VMAX; v++)
    {
        int r = 0;
        for(int j = 0; j < K; j++)
        {
            r += (v & (1 << j)) > 0;
        }
        count[abs(r)]++;
    }
    double E = 0;
    int N = 0;
    for(int i = 0; i < K + 1; i++)
    {
        E += i * count[i];
        N += count[i];
    }
    E /= N;
    printf("%lf\n", E);
}
