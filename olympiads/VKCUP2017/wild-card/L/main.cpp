#include <stdio.h>
#include <stdlib.h>

#define NMAX 200005
int N, K;

int arr[NMAX];

int main()
{
    scanf("%d", &N);
    scanf("%d", &K);

    char t;
    scanf("%c", &t);

    for(int i = 0; i < N; i++)
    {
        scanf("%c", &t);
        arr[i] = t - '0';
    }

    for(int i = 0; i < N; i++)
    {
        printf("%d", arr[i]);
    }
}
