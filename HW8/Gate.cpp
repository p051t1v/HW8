#include "Gate.h"


int Gate::getDelay(int delay) const{
	this->delay = delay;
	return 0;
}

Wire* Gate::getInput() const{
	return nullptr;
}

Wire* Gate::getOutput() const{
	return nullptr;
}

bool Gate::evaluate() const{
	return 0;
}
