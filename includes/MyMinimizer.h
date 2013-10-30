#pragma once

#include "Preamble.h"
#include "Interface.h"


class MyMinimizer : public Interface{
public:
	MyMinimizer(double convLimit, int maxIterations, mat params, double initialStepsize);

	// Main minimising method
	mat minimise(double chisq);

	// Methods to report if finished
	bool isFinished();

private:
	mat parameters, newParams;
	double convLimit, maxIterations;
	double initialStepsize, currentStepsize;
	int nParameters; //number of parameters
	int currentParameter;
	bool finished;
	double lastChiSq;
	int currentIt;
	int minCycles, currentCycle;


};
