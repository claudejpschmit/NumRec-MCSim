#include "LinearTheory.h"

Linear::Linear()
    :
        m(0.0),
        c(1.0)
{}

void Linear::setParameters(mat in)
{
    m = in(0,0);
    c = in(1,0);
}

double Linear::evaluate(double x)
{
    return m*x+c;
}

mat Linear::evaluate(mat x)
{
    int numRows = x.n_rows;
    mat resMatrix(numRows, 1);
    for (int i = 0; i < numRows; i++)
        resMatrix(i,0) = m*x(i,0)+c;

    return resMatrix;

}
