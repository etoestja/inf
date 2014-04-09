#include <stdio.h>

#define N 7

int x[N] = {1,2,3,5,7,8,10};
int y[N] = {3,5,7,11,14,15,19};

int main()
{
    int i;
    for(i = 0; i < N; i++)
    {
        printf("t_{%d}=-%d-%da_++%da_--c_++c_--T\\\\\n", 2 * i + 1, y[i], x[i], x[i]);
        printf("t_{%d}=%d+%da_+-%da_-+c_+-c_--T\\\\\n", 2 * i + 2, y[i], x[i], x[i]);
    }
}
