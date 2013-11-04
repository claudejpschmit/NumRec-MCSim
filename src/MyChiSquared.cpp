#include "MyChiSquared.h"

MyChiSquared::MyChiSquared( mat xin, mat yin, mat ein )
    :
        xMatrix(xin),
        yMeasured(yin)

{
    mat buffMatrix(ein.n_rows,ein.n_rows);
    for (int i = 0; i < ein.n_rows; ++i)
        for (int j = 0; j < ein.n_rows; ++i)
            buffMatrix(i,j) = 0; 
	


    for (int i = 0; i < ein.n_rows ; ++i){
        buffMatrix(i,i) = ein(i,0) * ein(i,0);
    }

inverseErrorMatrix = buffMatrix.i();
}

void MyChiSquared::setParameters( mat params )
{
    function.setParameters(params);
}

double MyChiSquared::evaluate()
{
    mat yTheoretical = function.evaluate(xMatrix);
    mat D = yTheoretical - yMeasured;
    mat ChiSq = D.t()*inverseErrorMatrix*D;

    return ChiSq(0,0);
}
