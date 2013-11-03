#pragma once

#include "Preamble.h"


/**
 *@file
 *
 *	MyPdf.h defines class MyPdf and creates references for all memberfunctions.
 *
 *	The class MyPdf creates the probability density function for the Monte Carlo Simulation. 
 *	This follows an exponential disgtribution multiplied by a sinusoid.
 *	
 */
class MyPdf
{
        public:

                /**  
                 * Constructor that initializes all the parameters for the probability density function
                 *
                 * @param tau is the rate of change. 
                 *        
                 * @param A sets the amplitude of the sinusoid. 
                 *
                 * @param t_max sets the maximum of the interval for which 
                 *			the exponential distribution can be used
                 */
                MyPdf(double tau, double A, double t_max);

                /**
                 * sets parameters tau and A in the pdf
                 */
                void setParameters(mat params);
                
                /**
                 * Gives a random value drawn from an exponential distribution multiplied by a sinusoid.
                 *
                 * @param noise is the noise fraction from a normal distribution to be added.
                 *
                 * @return random value drawn from the pdf
                 */
                double drawNextValueNoise(double noise);

                /**
                 * Evaluates the probability density function at a point in time t 
                 *
                 * @param t free parameter in the probability density function

                 * @return value of probability density function at a point in time t 
                 */
                double evaluate( double t );

        private: 
                double tau, A, t_max, max_random, omega;
};

