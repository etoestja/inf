#include <math.h>
#include <stdio.h>
#include <string.h>

#define LEN 1000
#define BASE 2

int main()
{
    char x[LEN];
    scanf("%s", x);

    double res = 0;

    int l = strlen(x), i;
    int point = 0;
    int pointC = 0, intC = 0, pP = l;

    for(i = 0; i < l; i++)
        if(x[i] == '.') pP = i;
        else x[i] -= '0';

    if(pP <= l - 2)
    {
        for(i = pP + 1; i < l; i++)
            res += pow(BASE, -(i - pP)) * x[i];
    }

    for(i = 0; i < pP; i++)
        res += pow(BASE, pP - i - 1) * x[i];

    printf("%.12lf\n", res);

    return 0;
}
