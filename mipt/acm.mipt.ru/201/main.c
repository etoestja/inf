#include <stdio.h>

int main()
{
    int x1, x2, x3, x4, n, ans = 0;
    scanf("%d", &n);

    for(x4 = 0; 4 * x4 <= n; x4++)
        for(x3 = 0; 3 * x3 + 4 * x4 <= n; x3++)
            for(x2 = 0; 2 * x2 + 3 * x3 + 4 * x4 <= n; x2++)
            {
                //x1 = n - 2 * x2 - 3 * x3 - 4 * x4
                if(n - 2 * x2 - 3 * x3 - 4 * x4 >= 0) ans++;
            }

    printf("%d\n", ans);
}
