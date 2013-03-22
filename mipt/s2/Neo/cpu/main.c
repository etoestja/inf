#include <stdio.h>

#define R 4
#define RC 5
unsigned int A[R];

int main()
{
    int i, c;
    unsigned int t1, t2;
    unsigned int x;

    for(c = 0; c < R; c++) A[c] = 0;

    while(scanf("%u", &c) > 0)
    {
//        printf("=>%u\n", c);
        if(c == 0)
            return;
        else if(c == 1 || c == 2 || c == 3)
        {
            scanf("%u", &t1);
            scanf("%u", &t2);

//            printf("=>%u %u\n", t1, t2);

            if(c == 1)
            {
                x = A[t1 - RC] + A[t2 - RC];
                A[t1 - RC] = x % 256;
            }
            else if(c == 2)
            {
                x = A[t1 - RC] - A[t2 - RC];
                A[t1 - RC] = x % 256;
            }
            else
            {
                A[t1 - RC] = t2 % 256;
            }
        }
        else if(c == 4)
        {
            for(c = 0; c < R; c++)
                printf("%u ", A[c] % 256);
            printf("\n");
        }
    }

    return(0);
}
