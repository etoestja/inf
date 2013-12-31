#include <stdio.h>

#define BITS 32
int arr[BITS];
int x;
int N;

int y, i, j, printed;

void print(int x1, int y1)
{
    int t;
    if(x1 > y1)
    {
        t = x1;
        x1 = y1;
        y1 = t;
    }
    printf("%d %d\n", x1, y1);
    printed = 1;
}

void init()
{
    printed = 0;
    x = 0;
    for(int i = 0; i < BITS; i++)
        arr[i] = 0;
}

int main()
{
    init();
    scanf("%d", &N);

    for(i = 0; i < N; i++)
    {
        scanf("%d", &y);
        x ^= y;
        for(j = 0; j < BITS; j++)
        {
            if((y & (1 << j)) != 0)
                arr[j] ^= y;
        }
    }

    for(j = 0; j < BITS; j++)
    {
        if(arr[j] != x && arr[j] != 0)
        {
            print(arr[j], x ^ arr[j]);
            break;
        }
    }

    if(!printed)
        print(0, x);

    return(0);
}
