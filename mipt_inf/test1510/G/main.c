#include <stdio.h>
#include <math.h>

#define PMAX (5000 + 1)

double R[PMAX];
int P;

int psort()
{

}

int main(void)
{
    int i, si;
    scanf("%d", &P);

    for(i = 0; i < P; i++)
        scanf("%lf", &R[i]);

    for(i = 0; i < P; i++)
    {
        for(si = 0; si < i; si++)
        {
            printf("%lf ", 1 / fabs(pow(R[0] / R[i], 1.5) - pow(R[0] / R[si], 1.5)));
        }
        printf("-1\n");
    }

    return 0;
}

