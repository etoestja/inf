#include <stdio.h>

#define N 3

void perm(int* arr, int filled_n)
{
    if(filled_n == N)
    {
        int i;
        for(i = 0; i < N; i++)
        {
            printf("%d ", arr[i]);
        }
        int lu = arr[0];
        if(arr[1] < lu) lu = arr[1];
        if(arr[2] < lu) lu = arr[2];
        int ld = arr[0];
        if(arr[1] < ld) ld = arr[1];
        int ru = arr[1];
        if(arr[2] < ru) ru = arr[2];
        int rd = arr[1];
        int diff = lu * rd - ru * ld;
        printf("%d \n", diff);
        return;
    }
    int i = 0;
    for(i = 0; i < N; i++)
    {
        arr[filled_n] = i;
        perm(arr, filled_n + 1);
    }
}

int main()
{
    int arr[N];
    perm(arr, 0);
    return(0);
}
