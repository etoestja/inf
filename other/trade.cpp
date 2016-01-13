#include <stdio.h>
#include <inttypes.h>
#include <strings.h>
#include <string.h>
#define NAN 99999999
#define T 101

int main()
{
    int64_t m[T], n[T];
    bzero(m, sizeof(m)); // now
    bzero(n, sizeof(n)); // new

    for(int64_t i = 0; i < T; i++)
        m[i] = NAN;
    for(int64_t i = 0; i < T; i++)
        n[i] = NAN;

    m[0] = 0;

    char s[1000];

    scanf("%s,%s", s, s);

    int64_t t, p;

    int64_t res = 0;

    while(scanf("%ld,%ld", &t, &p) == 2)
    {
        printf("%ld  %ld\n", t, p);
        memcpy(&n, &m, sizeof(m));
        for(int64_t i = 0; i < T; i++)
        {
            if(t == 100)
                break;
            if(m[i] != NAN)
            {
            if((m[i] - p > n[i + 1]) || (n[i + 1] == NAN))
            {
                n[i + 1] = m[i] - p;
            }
            if(i == 0)
                continue;
            if((n[i - 1] == NAN) || (n[i - 1] < m[i] + p))
                n[i - 1] = m[i] + p;
            }
        }
        memcpy(&m, &n, sizeof(m));
        if(t == 100)
        {
            for(int64_t i = 0; i < T; i++)
            {
                if(n[i] == NAN) continue;
                int64_t r = n[i] + i * p;
                if(r > res) res = r;
            }
        }
    }
    printf("%ld\n", res);
}
