#include <gtest/gtest.h>
#include <math.h>
#include "Complex.h"

TEST(Complex, multiply_shouldReturnProperValue)
{
    // Given
    Complex_t num1   = {1, 0};
    Complex_t num2   = {0, 2};
    Complex_t result = {0, 0};

    // When
    Complex_multiply(&result, &num1, &num2);

    // Then
    EXPECT_DOUBLE_EQ(0, result.r);
    EXPECT_DOUBLE_EQ(2, result.i);
}

TEST(Complex, multiplyByScalar_shouldReturnProperValue)
{
    // Given
    Complex_t num    = {1, 1};
    double  scalar = 3;
    Complex_t result = {0, 0};

    // When
    Complex_multiplyByScalar(&result, &num, scalar);

    // Then
    EXPECT_DOUBLE_EQ(3, result.r);
    EXPECT_DOUBLE_EQ(3, result.i);
}

TEST(Complex, fromOrthogonal_shouldInitializeComplexNumberWithProperValues)
{
    // Given
    Complex_t result = {0, 0};
    double  angle  = M_PI/6;
    double  radius = 2;

    // When
    Complex_fromOrthogonal(&result, angle, radius);

    // Then
    EXPECT_DOUBLE_EQ(sqrt(3), result.r);
    EXPECT_DOUBLE_EQ(sqrt(1), result.i);
}