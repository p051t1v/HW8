#include "Gate.h"

int Gate::getDelay() const
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

bool Gate::evaluate() const
{
	if (type == AND) {
		if (inputs.at(0)->value >= 1 && inputs.at(1)->value >= 1) {
			return true;
		}
		else {
			return false;
		}
	}
	if (type == OR) {
		if (inputs.at(0)->value >= 1 || inputs.at(1)->value >= 1) {
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
