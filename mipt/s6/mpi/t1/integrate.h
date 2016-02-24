#ifndef INTEGRATE_H
#define INTEGRATE_H

typedev double(*DDFunc)(double);

double integrate(DDFunc f, unsigned N, double a, double b);

#endif
