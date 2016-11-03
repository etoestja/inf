#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int arr[] = {1, 8, 28, 56, 70, 56, 28, 8, 1};

double get_sum(int k1, int k2)
{
    double s = 0;
    for(int i = k1 + 1; i < k2; i++)
        s += arr[i];
    s /= pow(2, 8);
    return(1 - s);
}

int main()
{
    for(int k1 = 0; k1 <= 8; k1++)
        for(int k2 = k1 + 1; k2 <= 8; k2++)
        {
            int s = (k1 + 1) * (k1 - 8) + (9 - k2) * k2;
            if(abs(s) == 0)
                printf("%d %d %d %lf\n", k1, k2, s, get_sum(k1, k2));
        }
    return(0);
}
