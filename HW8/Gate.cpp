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

int Gate::getType()
{

	return type;
}

//Evaluate function
int Gate::evaluate() const{
	
	if(inputs.at(0) == X || inputs.at(1) == X){
		return X;
	}
	else if (type == AND) {
		if (inputs.at(0) == HI && inputs.at(1) == HI) {
			return HI;
		}
		else if(inputs.at(0) == LO||inputs.at(1) == LO){
			return LO;
		}
		else {
			return X;
		}
	}
	else if (type == OR) {
		if (inputs.at(0)->getValue() == HI || inputs.at(1)->getValue() == HI) {
			return HI;
		}
		else if(inputs.at(0) == LO && inputs.at(1) == LO){
			return LO;
		}
		else {
			return X;
		}
	}
	else if (type == XOR) {
		if (inputs.at(0)->getValue() == X || inputs.at(1)->getValue() == X) {
			return X;
		}
		else if (inputs.at(0) != inputs.at(1)) {
			return HI;
		}
		else {
			return LO;
		}
	}
	else if (type == NOT) {
		if(inputs.at(0)->getValue() == HI)
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
