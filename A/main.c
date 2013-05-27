#include <stdio.h>
#include <math.h>

const long double xi = 0.596;
const long double R = 0.2;
const long double C = 4200.;
const long double q = 1000.;

const long double T0 = 273 + 30;
const long double T1 = 273 + 15;
const long double Tw = 273 + 5;

#define NMAX 1000
int N;

long double dr;

const long double dt = 1; //sec

long double T[NMAX];

long double time;

void clean()
{
    time = 0;
    dr = 1.0 * R / N;
    T[0] = Tw;
    int i;
    for(i = 1; i < N; i++)
        T[i] = T0;

}

long double d2Tdr2(int i)
{
    if(i == N - 1)
        return((T[i - 1] - T[i]) / pow(dr, 2));
    else
        return((T[i + 1] + T[i - 1] - 2 * T[i]) / pow(dr, 2));
}

void step(int i)
{
    T[i] += dt * xi / q / C * d2Tdr2(i);
//    time += dt;
}

void stepAll()
{
    int i;
    for(i = 1; i < N; i++)
        step(i);
    time += dt;
}

int check()
{
    return(T[N - 1] <= T1);
}

void print()
{
    int i;
    printf("%llfh\t", time / 3600);
    #ifdef PRINT
        for(i = 0; i < N; i++)
            printf("%llf\t", T[i] - 273.);
    #endif
    printf("\n");
//    printf("Tin = %llf\n", T[N - 1]);
}

int main()
{
    scanf("%d", &N);
    clean();
    while(!check())
    {
        stepAll();
        #ifndef PRINT
            if(check())
        #endif
        print();
    }
    return(0);
}
