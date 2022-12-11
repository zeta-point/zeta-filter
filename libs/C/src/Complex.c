#include "Complex.h"
#include <math.h>

void Complex_multiply(Complex_t *result, Complex_t *first, Complex_t *second) 
{
    result->r = first->r * second->r - first->i * second->i;
    result->i = first->i * second->r + first->r * second->i;
}

void Complex_multiplyByScalar(Complex_t *result, Complex_t *num, double scalar)
{
    result->r = num->r * scalar;
    result->i = num->i * scalar;
}

void Complex_fromOrthogonal(Complex_t *result, double angle, double radius)
{
    result->r = radius * cos(angle);
    result->i = radius * sin(angle);
}
