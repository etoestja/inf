#include <stdio.h>
#include <math.h>

double omega = 2 * M_PI, Theta = 0;

typedef struct
{
    double x;
    double y;
} xy;

xy getR(double t)
{
    xy res;
    res.x  = cos(-omega * t / 2.);
    res.y  = sin(-omega * t / 2.);
    res.x += cos(omega * t + Theta);
    res.y += sin(omega * t + Theta);
    return(res);
}

xy getRD(double t)
{
    xy res;
    res.x  =  omega / 2. * sin(-omega * t / 2.);
    res.y  = -omega / 2. * cos(-omega * t / 2.);
    res.x += -omega      * sin(omega * t + Theta);
    res.y +=  omega      * cos(omega * t + Theta);
    return(res);
}

xy getRDD(double t)
{
    xy res;
    res.x  = -omega * omega / 4. * cos(-omega * t / 2.);
    res.y  = -omega * omega / 4. * sin(-omega * t / 2.);
    res.x += -omega * omega      * cos(omega * t + Theta);
    res.y += -omega * omega      * sin(omega * t + Theta);
    return(res);
}

void printXY(xy a)
{
    printf("%lf\t%lf", a.x, a.y);
}

int main()
{
    int i, N;
    double dt;
    scanf("%d", &N);
    scanf("%lf", &dt);

    double t = 0;

    for(i = 0; i < N; i++)
    {
        printf("%d\t%lf\t", i, t);
        printXY(getR(t));
        printf("\t");
        printXY(getRD(t));
        printf("\t");
        printXY(getRDD(t));
        printf("\n");
        t += dt;
    }
}
