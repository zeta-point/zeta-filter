#include <gtest/gtest.h>
#include <math.h>
#include "Zeta.h"
#include <cstdlib>

#define ERROR_LVL (1e-15)
#define EXPECT_COMPLEX_NEAR(x, y, actual) { \
    EXPECT_NEAR((x), (actual).r, ERROR_LVL); \
    EXPECT_NEAR((y), (actual).i, ERROR_LVL); \
}

Zeta_t getZeroAngleInitializedFilter(void) {
    
    Zeta_t zeta;
    
    zeta.x_prior = {1, 0};
    zeta.x_post  = zeta.x_prior;
    
    return zeta;
}

double randomDouble(double min = -1e20, double max = 1e20)
{
    double f = (double)rand() / RAND_MAX;
    return min + f * (max - min);
}

Complex_t randomComplex() {
    return (Complex_t){randomDouble(), randomDouble()};
}

Zeta_t getRandomlyInitializedFilter(void) {
    
    Zeta_t zeta;
    
    zeta.x_prior = randomComplex();
    zeta.x_post  = randomComplex();
    
    return zeta;
}

TEST(Zeta, init_shouldInitializeFilterState)
{
    // Given
    auto zeta = getRandomlyInitializedFilter();

    // When
    Zeta_init(&zeta);

    // Then
    EXPECT_COMPLEX_NEAR(0, 0, zeta.x_prior);
    EXPECT_COMPLEX_NEAR(0, 0, zeta.x_post);
}

TEST(Zeta, predict_withSingleStep_shouldAdvanceModelProperly)
{
    // Given
    auto zeta = getZeroAngleInitializedFilter();

    Control_t b;
    b.omega = M_PI_2;
    b.var   = 2;

    double dt = 1;

    // When
    Zeta_predict(&zeta, &b, dt);

    // Then
    EXPECT_COMPLEX_NEAR(0, 1/3.0, zeta.x_prior);
}

TEST(Zeta, predict_withMultipleSteps_shouldAdvanceModelProperly)
{
    // Given
    auto zeta = getZeroAngleInitializedFilter();

    Control_t b;
    b.omega = M_PI_2;
    b.var   = 2;

    double dt = 1;

    // When
    Zeta_predict(&zeta, &b, dt);
    Zeta_predict(&zeta, &b, dt);

    // Then
    EXPECT_COMPLEX_NEAR(-1/5.0, 0, zeta.x_prior);
}

TEST(Zeta, update_shouldCorrectPriorEstimate)
{
    // Given
    auto zeta = getZeroAngleInitializedFilter();
    zeta.x_prior.r = 1;

    Output_t out;
    out.y = {0, 2};
    out.var_phi = 1;

    // When
    Zeta_update(&zeta, &out);

    // Then
    EXPECT_COMPLEX_NEAR(1, 1, zeta.x_post);
    // EXPECT_COMPLEX_NEAR(1, 1, zeta.x_prior);
}