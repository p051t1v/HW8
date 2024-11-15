#include "Gate.h"

int Gate::getDelay(int delay) const
{
	return this->delay;
}

Wire* Gate::getInput(int input) const
{
	return inputs.at(input);
}

Wire* Gate::getOutput() const
{
	return output;
}

int Gate::evaluate() const
{
	// make sure this gets fixed!!!
	if(inputs.at(0)->value == X || inputs.at(1)->value == X){
		return X;
	}
	if (type == AND) {
		if (inputs.at(0)->value >= 1 && inputs.at(1)->value >= 1) {
			return true;
		}
		else {
			return false;
		}
	}
	if (type == OR) {
		if (inputs.at(0)->value == 1 || inputs.at(1)->value == 1) {
			return true;
		}
		else {
			return false;
		}
	}
	if (type == NOT) {
		return !(inputs.at(0)->value);
	}
	return 0;
}
