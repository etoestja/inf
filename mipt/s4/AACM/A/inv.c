#include <stdio.h>

#define p 23

int main()
{
    int i;
    printf("int inv[p + 1] = {-1, ");
    for(i = 1; i < p; i++)
    {
        int j;
        for(j = 1; j < p; j++)
        {
            if((i * j) % p == 1)
            {
                //printf(stderr, "1/%d=%d mod %d\n", i, j, p);
                printf("%d", j);
                if(i < p - 1)
                    printf(", ");
            }
        }
    }

    printf("};\n");

    return(0);
}
