#include "Preamble.h"


class MaxLikelihood : {

public:
    MaxLikelihood(mat data, mat initial_params, double tmax);
    
    double evaluate();

    void setParameters(mat params);

private:

    mat params; 
    int nDataPoints;
    double logLikelihood;
};
