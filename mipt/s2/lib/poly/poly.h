#ifndef POLY_H
#define POLY_H

// a structure that contains a single polynom
struct poly
{
    double * coeffs;
    unsigned int degree;
};

// copying
void poly_copy(struct poly * a, struct poly * b);

// multiple poly a to number b
void poly_mul_number(struct poly * a, double b);

// add poly b to poly a
void poly_add(struct poly * a, struct poly * b);

void poly_mul(struct)

#endif
