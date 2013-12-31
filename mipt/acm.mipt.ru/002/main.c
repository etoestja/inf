#include <stdio.h>

#define NMAX 1000

int arr[NMAX];
int arr_used[NMAX];

int main()
{
    int i, N = 0, t, is_empty = 1, is_printed;

    while(scanf("%d", &t) == 1)
    {
        if(t == -1) break;

        arr_used[N] = 1;
        arr[N++] = t;
    }

    while(scanf("%d", &t) == 1)
    {
        if(t == -1) break;

        is_printed = 0;

        for(i = 0; i < N; i++)
        {
            if(arr[i] == t && arr_used[i])
            {
                arr_used[i] = 0;
                if(!is_printed) printf("%d ", t);

                is_printed = 1;
                is_empty = 0;
            }
        }
    }

    if(is_empty) printf("empty");
}
