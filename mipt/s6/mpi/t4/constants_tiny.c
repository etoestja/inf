#include "constants.h"

const double LEFT = 0;
const double T = 0.15;
const double c = 1;
const double h = 0.1;
const double tau = 0.05;
const double X = 1;

const int P = 3; // T / tau
const int N = 10; // X / h

double g(double x)
{
    if(x < 0 || x > 2)
        return(0);
    return(x * (2 - x));
}
