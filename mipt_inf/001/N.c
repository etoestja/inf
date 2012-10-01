#include <stdio.h>

int main()
{
    int i = 0, t, max;

    while(scanf("%d", &t) == 1)
        if(i == 0 || max < t)
        {
    	    max = t;
            i = 1;
        }

    printf("%d\n", max);

    return 0;
}
