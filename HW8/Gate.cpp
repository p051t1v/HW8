#include "Gate.h"
#include "Wire.h"

//default constructor
Gate::Gate(int type, int delay, vector<Wire*> output) {
}

//get everything
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

//Evaluate function
int Gate::evaluate() const{
	
	if(inputs.at(0)->0value == X || inputs.at(1)->value == X){
		return X;
	}
	else if (type == AND) {
		if (inputs.at(0)->value == 1 && inputs.at(1)->value == 1) {
			return HI;
		}
		else if(inputs.at(0)==0||inputs.at(1)==0){
			return LO;
		}
		else {
			return X;
		}
	}
	else if (type == OR) {
		if (inputs.at(0)->value == HI || inputs.at(1)->value == HI) {
			return HI;
		}
		else if(inputs.at(0)->value == LO && inputs.at(1)->value == LO){
			return LO;
		}
		else {
			return X;
		}
	}
	else if (type == XOR) {
		if (input.at(0) == X || input.at(1) == X) {
			return X;
		}
		else if (input.at(0) != input.at(1)) {
			return HI;
		}
		else {
			return LO;
		}
	}
	else if (type == NOT) {
		if(inputs.at(0)==HI)
		return LO;
		else if (inputs.at(0) == LO) {
		return HI;
		}
		else {
			return X;
		}
	}
	return 0;
}
