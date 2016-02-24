#ifndef INTEGRATE_H
#define INTEGRATE_H

// pointer function to integrate type (Double-to-Double Function)
typedef double(*DDFunc)(double);

// integrate with such N that eps(N) <= eps
double integrateAuto(DDFunc f, double a, double b, double eps);

// integrate with fixed N
double integrate(DDFunc f, unsigned N, double a, double b);

#endif
