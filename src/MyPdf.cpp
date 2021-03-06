#include "MyPdf.h"


/**
 *@file
 *
 * MyPdf.cpp the definitions of all member functions of the class MyPdf.
 *
 */
#define PI 3.1415

MyPdf::MyPdf(double tau, double A, double t_max)
    :
        tau(tau),
        A(A),
        t_max(t_max),
        omega(0.3)
{
    // Throws errors when bad values are given.
    assert(t_max >= 0.0);
    assert(tau >= 0.0);
    assert(A >= 0.0);

    //fixes upper limit for the algorithm in drawValueNoise
    //we take 1+A since 1+A*sin has maximum value 1+A, and the exponential can only decrease this value.
    max_random = 1+A; // fixes upper limit for the algorithm in drawValueNoise
}


double MyPdf::evaluate(double t)
{
    return exp(-t/this->tau)*(1+A*sin(2.0*PI*t/this->omega))/(this->tau*(1-exp(-this->t_max/this->tau))); // evaluates the exponential at t
}

void MyPdf::setParameters(mat params)
{
    tau = params(0,0);
    A = params(1,0);
}

double MyPdf::drawNextValueNoise(double noise)
{
    double y1, y2, random_t;
    max_random += noise;
    do 
    {
        random_t = (double) rand() / (double) RAND_MAX; // creates random number between 0 and 1.
        random_t *= t_max; // creates random number between 0 and t_max.

        y1 = this->evaluate(random_t) + noise; // evaluates the distribution at random_t
        y2 = (double) rand() / (double) RAND_MAX; // creates random number between 0 and 1.
        y2 *= max_random; // creates random number between 0 and max_random.
    }
    while (y2 >= y1);

    return random_t;
}
