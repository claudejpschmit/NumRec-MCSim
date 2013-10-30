#pragma once

#include "Preamble.h"
#include "LinearTheory.h"

class MyChiSquared {
public:
	MyChiSquared( mat xin, mat yin, mat ein);

	void setParameters( mat params );
	double evaluate();

private:
	Linear function;
	mat xMatrix, yMeasured;
	mat inverseErrorMatrix;
};
