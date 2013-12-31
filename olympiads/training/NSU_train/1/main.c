#include <stdio.h>

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int res = 0, N, i;
    scanf("%d", &N);

    if(N >= 1)
        for(i = 1; i <= N; i++)
            res += i;
    else
        for(i = 1; i >= N; i--)
            res += i;

    printf("%d\n", res);
    return(0);
}
