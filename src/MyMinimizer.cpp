#include "MyMinimizer.h"

MyMinimizer::MyMinimizer(double convLimit, int maxIterations, mat params, double initialStepsize)
    :
        initialStepsize(initialStepsize),
        currentStepsize(initialStepsize),
        parameters(params),
        convLimit(convLimit),
        maxIterations(maxIterations),
        finished(false),
        lastChiSq(100000000000.),
        minCycles(100),
        currentIt(0),
        currentCycle(0)
{
    nParameters = parameters.n_rows;
    currentParameter = 0;
    mat buffMatrix(parameters.n_rows,1);
    for (int i = 0; i < parameters.n_rows; ++i)
        buffMatrix(i,0) = 0;
    newParams = buffMatrix;
}


// Main minimising method
mat MyMinimizer::minimise(double chisq)
{
    ++currentIt;
    if (currentIt > maxIterations)
    {
        finished = true;
        return newParams;
    }

    if ((chisq < lastChiSq) && ((lastChiSq - chisq) < convLimit))
    {
        // then this parameter has converged and we move on to the next
        currentParameter++;

        if (currentParameter > nParameters-1)
        {
            currentParameter = 0;
            currentCycle++;
            if (currentCycle > minCycles)
            {
                finished = true;
                return newParams;
            }				
        }
        lastChiSq = chisq;	
        newParams(currentParameter,0) = parameters(currentParameter,0)+currentStepsize;	
        return newParams;	
    }
    else
    {
        // We continue with the current parameter
        if (chisq < lastChiSq)
        {
            lastChiSq = chisq;
            newParams(currentParameter,0) = parameters(currentParameter,0)+currentStepsize;
            return newParams;
        }
        else
        {
            lastChiSq = chisq;
            currentStepsize = - currentStepsize * 0.5;
            newParams(currentParameter,0) = parameters(currentParameter,0)+currentStepsize;
            return newParams;
        }
    }
}

// Methods to report if finished
bool MyMinimizer::isFinished() 
{
    return finished;
}
