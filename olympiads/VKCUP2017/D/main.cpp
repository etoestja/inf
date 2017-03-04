#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define AMAX 10050
int count[AMAX];

int N, K;

int count_bit(int x)
{
    int ans = 0;
    while (x > 0)
    {
        x &= x - 1;
        ans++;
    }
    return ans;
}

int main()
{
    memset(count, 0x00, sizeof(int) * AMAX);
    //bzero(count, AMAX * sizeof(int));

    scanf("%d", &N);
    scanf("%d", &K);

    int a_max = -1;
    int a;
    for(int i = 0; i < N; i++)
    {
        scanf("%d", &a);
        count[a]++;
        if(a_max < a)
            a_max = a;
    }

    int res = 0;

    if(K == 0)
    {
        for(int ai = 0; ai <= a_max; ai++)
        {
            if(count[ai] > 0)
            {
                //printf("%d %d\n", ai, count[ai]);
                res += (count[ai] * (count[ai] - 1)) / 2;
            }
        }
    }
    else
    {
        unsigned bmax = a_max * 2;
        //printf("MAX: %u\n", bmax);
        for(unsigned b = 0; b <= bmax; b++)
        {
            if(count_bit(b) == K)
            {
                for(int ai = 0; ai <= a_max; ai++)
                {
                    if(count[ai] > 0)
                    {
                        int aj = ai ^ b;
                        if(aj != ai && aj <= a_max && count[aj] > 0)
                        {
                            //printf("%d %d %d %d\n", ai, aj, count[ai], count[aj]);
                            res += count[ai] * count[aj];
                        }
                    }
                }
            }
        }

        res /= 2;
    }

    printf("%d\n", res);
}
