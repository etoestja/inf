#include <stdio.h>

#define N 7

int x[N] = {1,2,3,5,7,8,10};
int y[N] = {3,5,7,11,14,15,19};

int main()
{
    int i;
    for(i = 0; i < N; i++)
    {
        printf("%da_+-%da_-+%d+c_+-c_-+T+t_{%d}=0\\\\\n", x[i], x[i], y[i], 2 * i + 1);
        printf("-%da_++%da_--%d-c_++c_-+T+t_{%d}=0\\\\\n\n", x[i], x[i], y[i], 2 * i + 2);
    }
}
