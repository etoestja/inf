#include <stdio.h>
#include <stdlib.h>

int main()
{
    long long int N, i;

    scanf("%lld", &N);

    //long long int arr[N];

    long long int* arr = malloc(N * sizeof(long long int));

    if(NULL == arr) return 1;

    for(i = 0; i < N; i++)
        arr[i] = i;

    for(i = 0; i < N; i++)
        printf("%lld ", arr[i]);

    printf("\n");

    free(arr);

    return 0;
}

