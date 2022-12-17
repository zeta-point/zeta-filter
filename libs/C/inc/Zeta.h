#ifndef __ZETA_H
#define __ZETA_H

#ifdef __cplusplus
extern "C" {
#endif

    #include "Complex.h"

    /**
     * @brief Zeta filter data cache
    */
    typedef struct
    {
        Complex_t x_prior; //!< filter prior state
        Complex_t x_post;  //!< filter posterior state
        Complex_t b;       //!< control vector
        Complex_t y;       //!< output vector
    } Zeta_t;

    /**
     * @brief Control vector data type
     * This is data from the gyroscope
    */
    typedef struct
    {
        double omega; //!< gyro angular velocity in rad/s units
        double var;   //!< variance of the gyro measurement rad^2/s^2
    } Control_t;
    
    /**
     * Observation vector data type
    */
    typedef struct
    {
        Complex_t y;    //!< any measurement with high-pass noise characteristic like accelerometer
        double var_phi; //!< variance of the measurement argument ( angle )
    } Output_t;

    /**
     * @brief Sets filter initial state
     * @param filter a pointer to filter data to initialize
    */
    void Zeta_init(Zeta_t * filter);

    /**
     * @brief Prediction step of the Zeta filter / model advance.
     * Angular velocity integration is done using zero order hold.
     * @param filter a pointer to filter data
     * @param b a pointer to gyroscope control data
     * @param dt time delta between last model advancement.
    */
    void Zeta_predict(Zeta_t * filter, Control_t *b, double dt);

    /**
     * @brief Update step of the Zeta filter.
     * Estimates new posterior distribution of the filter
     * based on the innovation / new measurement
     * @param filter a pointer to filter data
     * @param y a pointer to measurement data
    */
    void Zeta_update(Zeta_t * filter, Output_t * y);

#ifdef __cplusplus
}
#endif

#endif // __ZETA_H