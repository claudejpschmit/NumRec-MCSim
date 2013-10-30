#pragma once

#include "Preamble.h"

class Interface{
public:
	// Main minimising method
	virtual mat minimise(double chisq) = 0;

	// Methods to report if finished
	virtual bool isFinished() = 0;

};
