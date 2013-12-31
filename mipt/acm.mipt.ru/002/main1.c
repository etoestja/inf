#include <stdio.h>

#define NMAX 1000000

char arr[NMAX];

int main()
{
    int i, t, p = 0;
    for(i = 0; i < NMAX; i++)
        arr[i] = 0;

    while(scanf("%d", &t) == 1 && t != -1)
        arr[t] = 1;

    while(scanf("%d", &t) == 1 && t != -1)
        if(arr[t])
        {
            arr[t] = 0;
            printf("%d ", t);
            p = 1;
        }

    if(!p) printf("empty");
}
