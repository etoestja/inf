#include <stdio.h>

int main()
{
    int k;
    for(k = 401; k <= 1000; k++)
    {
        if((509 * k + 24) % 2013 == 0)
            printf("509 * %d + 24 = 2013 * %d\n", k, (509 * k + 24) / 2013);
    }
    return(0);
}
