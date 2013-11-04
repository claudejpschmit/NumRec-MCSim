#include "Preamble.h"
#include "MyPdf.h"

class MaxLikelihood {

public:
    MaxLikelihood(mat data, mat initial_params, double tmax);
    
    double evaluate();

    void setParameters(mat params);

private:
    MyPdf* pdf;
    mat data;
    mat params; 
    int nDataPoints;
    double logLikelihood;
};
