#include "constants.h"

const double LEFT = 0;
const double T = 4;
const double c = 1;
const double h = 0.1;
const double tau = 0.05;
const double X = 10;

const int P = 80; // T / tau
const int N = 100; // X / h

double g(double x)
{
    if(x < 0 || x > 2)
        return(0);
    return(x * (2 - x));
}
