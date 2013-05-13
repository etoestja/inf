#include <stdio.h>

#define MAXN 1000000
int arr[MAXN];
int N;
int i;

int main()
{
    scanf("%d", &N);
    for(i = 0; i < N; i++)
        scanf("%d", arr + i);
    for(i = N - 1; i >= 0; i--)
        printf("%d ", *(arr + i));
    return(0);
}
