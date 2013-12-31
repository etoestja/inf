#include <stdio.h>

int main()
{
    long long N, ans;

    scanf("%lld", &N);

    ans = 0;
    while(N)
    {
        if(N <= 3)
        {
            ans += N;
            break;
        }
        else
        {
            if((N % 2) == 0) N /= 2;
            else if((N % 4) == 1) N--;
            else N++;
            ans++;
        }
    }

    printf("%lld", ans);
}
