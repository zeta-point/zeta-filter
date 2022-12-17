#include "Zeta.h"

void Zeta_init(Zeta_t *filter)
{
    // state to zero meaning inifinite variance
    Complex_multiplyByScalar(&filter->x_prior, &filter->x_prior, 0);
    Complex_multiplyByScalar(&filter->x_post,  &filter->x_post,  0);
}

void Zeta_predict(Zeta_t *filter, Control_t *b, double dt)
{
    double var_b  = b->var*dt*dt;
    double x_len  = Complex_getMagnitude(&filter->x_post);
    double radius = 1.0/(1.0 + x_len*var_b);
    double angle  = b->omega*dt;

    Complex_fromOrthogonal(&filter->b, angle, radius);
    Complex_multiply(&filter->x_prior, &filter->x_post, &filter->b);

    // In case predict is run at different delta time than update
    filter->x_post.r = filter->x_prior.r;
    filter->x_post.i = filter->x_prior.i;
}

void Zeta_update(Zeta_t *filter, Output_t *y)
{
    double y_len_scale = 1/(Complex_getMagnitude(&y->y) * y->var_phi);

    Complex_multiplyByScalar(&filter->y, &y->y, y_len_scale);
    Complex_add(&filter->x_post, &filter->x_prior, &filter->y);

    // In case someone extracts angle estimate from x prior
    filter->x_prior.r = filter->x_post.r;
    filter->x_prior.i = filter->x_post.i;
}
