#include <stdio.h>

#define p (1./3)

int bool_(int x)
{
    return(x ? 1 : -1);
}

double proba(int x)
{
    if(x == -1)
        return(p);
    return(1. - p);
}

double proba_3(int b0, int b1, int b2)
{
    int x[4], k;
    int y0, y1, y2;

    double sum = 0;

    double sum_1 = 0, sum_12 = 0, sum_01 = 0, sum_012 = 0;

    for(k = 0; k < 16; k++)
    {
        x[3] = (bool_)(k & 0b0001);
        x[2] = (bool_)(k & 0b0010);
        x[1] = (bool_)(k & 0b0100);
        x[0] = (bool_)(k & 0b1000);

        y0 = x[0] * x[1];
        y1 = x[1] * x[2];
        y2 = x[2] * x[3];

        double pr = proba(x[0]) * proba(x[1]) * proba(x[2]) * proba(x[3]);
        sum += pr;

        if(y0 == b0 && y1 == b1 && y2 == b2)
            sum_012 += pr;
        if(y1 == b1)
            sum_1 += pr;
        if(y1 == b1 && y2 == b2)
            sum_12 += pr;
        if(y0 == b0 && y1 == b1)
            sum_01 += pr;

        printf("%d %d %d, %d %d %d %d %lf\n", y0, y1, y2, x[0], x[1], x[2], x[3], pr);
    }

    printf("sum = %lf\n", sum);

    double x1 = sum_012 / sum_01;
    double x2 = sum_12 / sum_1;

    printf("sum_012 = %lf sum_01 = %lf x1 = %lf\n", sum_012, sum_01, x1);
    printf("sum_12 = %lf sum_1 = %lf x2 = %lf\n", sum_12, sum_1, x2);
}

int main()
{
    proba_3(1, 1, 1);
    return(0);
}
