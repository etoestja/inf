#include <stdio.h>

int main()
{
    unsigned long int n, a, a1, a2, a3, ok, t, count = 0;

    scanf("%lu", &n);

    for(a = 1; a <= n; a++)
    {
        ok = 0;

        for(a3 = 0; a3 * a3 <= a; a3++)
            for(a2 = 0; a2 <= a3; a2++)
                for(a1 = 0; a1 <= a2; a1++)
                {
                    if(a == a1 * a1 + a2 * a2 + a3 * a3)
                        ok = 1;
                }

        if(!ok)
        {
            count++;
            printf("%lu, ", a);
        }
/*        if((a - 1) % 8 == 0) printf("0b");
        printf("%u", !ok);
        if((a - 1) % 8 == 7) printf(", ");*/
    }

//    printf("%lu", count);

    return 0;
}
