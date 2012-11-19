#include <stdio.h>
#include <stdlib.h>

#define N 2000

char count[N], arr[N];

int main()
{
    freopen("symbols.in", "r", stdin);
    freopen("symbols.out", "w", stdout);

    int i = 0, ans1 = 0, ans2 = 0, tt = 0;
    for(i = 0; i < N; i++) count[i] = 0;

    scanf("%s", arr);
    scanf("%d", &ans1);

    for(i = 0; arr[i] && i < N; i++)
    {
        tt = arr[i];
        if(tt >= 'a' && tt < 'z' && tt < N)
            count[tt]++;
    }

    for(ans2 = 0, i = 'a'; i <= 'z' && i < N; i++) if(count[i]) ans2++;

    if(ans1 == ans2)
        printf("Yes");
    else
        printf("No");

    fclose(stdin);
    fclose(stdout);

    return(0);
}
