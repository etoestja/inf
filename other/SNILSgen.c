#include <stdio.h>

#define N 9

int arr[N];

int main()
{
    int i;
    char c;

    int sum = 0, t;

    for(i = 0; i < N; i++)
    {
        scanf("%c", &c);
        arr[i] = c - '0';
        sum += (N - i) * arr[i];
    }

    t = sum;
    while(t >= 101)
    {
        t %= 101;
    }

    if(t == 100) t = 0;
    
    printf("%d%d%d-", arr[0], arr[1], arr[2]);
    printf("%d%d%d-", arr[3], arr[4], arr[5]);
    printf("%d%d%d ", arr[6], arr[7], arr[8]);

    if(t < 10) printf("0");

    printf("%d", t);

    return(0);
}
