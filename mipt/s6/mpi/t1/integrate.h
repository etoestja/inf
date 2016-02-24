#ifndef INTEGRATE_H
#define INTEGRATE_H

typedef double(*DDFunc)(double);

double integrateAuto(DDFunc f, double a, double b, double eps);

double integrate(DDFunc f, unsigned N, double a, double b);

#endif
