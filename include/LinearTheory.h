#pragma once

#include "Preamble.h"

class Linear
{
public: 
	Linear();

	void setParameters(mat in);
	double evaluate( double x );
	mat evaluate( mat x );

private:
	double m;
	double c;
};
