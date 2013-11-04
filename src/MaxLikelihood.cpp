#include "MaxLikelihood.h"
#include "MyPdf.h"

MaxLikelihood::MaxLikelihood(mat data, mat initial_params, double tmax)
    :
        params(initial_params),
        logLikelihood(0.0)
{
    this->data = data;
    nDataPoints = data.n_rows;
    pdf = new MyPdf(params(0,0), params (1,0), tmax);
}

double MaxLikelihood::evaluate(){
    logLikelihood = 0.0;
    for (int i = 0; i < nDataPoints; ++i) {
        logLikelihood += log(pdf->evaluate(data(i,0)));
        
    }
    logLikelihood *= -1;

    return logLikelihood;
}

void MaxLikelihood::setParameters(mat params)
{
    pdf->setParameters(params);
}
