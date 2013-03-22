#include <stdio.h>
#include <string.h>

#define NMAX (100000000 / 8 + 1)
#define C 8
unsigned char map[NMAX];
unsigned char arr1[C], arr2[C];

unsigned int M, N, t, ans;

void fill1()
{
    int i;
    for(i = 0; i < C; i++)
    {
        arr1[i] = ~((long unsigned int) (1 << ((C - 1) - (i % C))));
        arr2[i] = ~arr1[i];
    }
}

#define setFalse(i) {map[i / C] &= arr1[i % C];}
#define isTrue(i) (map[i / C] & arr2[i % C])

int main()
{
    memset(map, 0xff, NMAX);
    fill1();

    scanf("%u", &M);
    scanf("%u", &N);

    unsigned int i, si, ssi;
    ans = 0;
    for(i = 0; i < M; i++)
    {
        scanf("%u", &t);

//        printf("=>%u\n", t);

        if(isTrue(t))
        {
            ans++;
            setFalse(t);
        }

        ssi = 1;
        for(si = 2 * t; si < N; si += t + ssi, ssi++)
        {
//            printf("? %u\n", si);
            if(isTrue(si))
            {
                ans++;
                setFalse(si);
            }
        }
    }

    printf("%u\n", ans);

    return 0;
}
