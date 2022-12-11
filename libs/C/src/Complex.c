#include "Complex.h"
#include <math.h>

void Complex_multiply(Complex *result, Complex *first, Complex *second) 
{
    result->r = first->r * second->r - first->i * second->i;
    result->i = first->i * second->r + first->r * second->i;
}

void Complex_multiplyByScalar(Complex *result, Complex *num, double scalar)
{
    result->r = num->r * scalar;
    result->i = num->i * scalar;
}

void Complex_fromOrthogonal(Complex *result, double angle, double radius)
{
    result->r = radius * cos(angle);
    result->i = radius * sin(angle);
}
