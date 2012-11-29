#include <stdio.h>

int main()
{
    int N, c = 0, i, j, t;

    scanf("%d", &N);

    for(i = 0; i < N; i++)
    {
        for(j = 0; j < N; j++)
        {
            scanf("%d", &t);
            if(t == 1) c++;
        }
    }

    printf("%d\n", c / 2);

    return 0;
}
