#include <stdio.h>

int main()
{
    int z;
    scanf("%d", &z);
    z += 2;
    int m = 32;
    int z1 = 1;
    for(m = 32; m >= 0; m--)
    {
        if(z1 >= z)
        {
            printf("%d\n", m);
            break;
        }
        z1 *= 2;
    }
    return(0);
}
