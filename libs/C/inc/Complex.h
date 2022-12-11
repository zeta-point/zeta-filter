#ifndef __COMPLEX_H
#define __COMPLEX_H

#ifdef __cplusplus
extern "C" {
#endif

    /**
     * @brief Represents complex number
    */
    typedef struct
    {
        double r; // realis
        double i; // imaginalis
    } Complex;
    
    /**
     * @brief Multiplies two complex numbers and saves value to result
     * @param result pointer to the result storage
     * @param first pointer to first multiplication factor
     * @param second pointer to second multiplication factor
    */
    void Complex_multiply(Complex * result, Complex * first, Complex * second);

    /**
     * @brief Multiplies complex number by scalar value and saves value to result
     * @param result pointer to the result storage
     * @param first pointer to the complex number
     * @param scalar multiplication factor
    */
    void Complex_multiplyByScalar(Complex * result, Complex * num, double scalar);

    /**
     * @brief Creates complex number from orthogonal coordinates ( angle and radius )
     * @param result pointer to the result storage
     * @param angle argument/angle of the complex number in radians
     * @param radius magnitude/radius/length of the complex number
    */
    void Complex_fromOrthogonal(Complex * result, double angle, double radius);

#ifdef __cplusplus
}
#endif

#endif // __COMPLEX_H