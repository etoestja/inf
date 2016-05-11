#include "constants.h"

const int P = 800; // T / tau
const int N = 1000000; // X / h

const double LEFT = 0;
const double T = 0.005;
const double c = 1;
const double X = 10;
double tau, h;

double g(double x)
{
    if(x < 0 || x > 2)
        return(0);
    return(x * (2 - x));
}
