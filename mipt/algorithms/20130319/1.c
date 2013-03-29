#include <stdio.h>

#define N (100 * 8)
int A[N] = {1, 1, 1, 1, 0, 1, 1, 1, 0, 0};
int ans;

void fill_array()
{
    void* a = main;
    
}

void find(l, r)
{
    if(l + 1 == r) ans = l;
    if(l + 1 >= r) return;

    int m = (l + r) / 2;
    if(A[l] != A[m]) find(l, m);
    else find(m, r);
}

int main()
{
    int i;
    for(i = 0; i < N; i++)
        printf("%d ", i);
    printf("\n");

    for(i = 0; i < N; i++)
        printf("%d ", A[i]);
    printf("\n");

    find(0, N - 1);

    printf("%d\n", ans);

    return(0);
}
