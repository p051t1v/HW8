#include "Gate.h"

int Gate::getDelay() const
{
	return 0;
}

Wire* Gate::getInput(int) const
{
	return nullptr;
}

Wire* Gate::getOutput() const
{
	return nullptr;
}

bool Gate::evaluate() const
{
	return 0;
}
