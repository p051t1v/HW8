#include "Gate.h"
#include "Wire.h"
#include <iostream>



//default constructor
Gate::Gate(int type, int delay, vector<Wire*> inputs, Wire* output)
   :type(type), delay(delay), inputs(inputs), output(output) {}




//get everything
int Gate::getDelay() const
{
	return this->delay;
}

 Wire* Gate::getInput(int index) const
{
	return this->inputs.at(index);
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
int Gate::evaluate() const
{
	
	if((inputs.at(0)->getValue() == X) && (inputs.at(0)->getValue() == X))
	{
		return HI;

	}
	else if (type == AND)
	{
		if (inputs.at(0)->getValue() == HI && inputs.at(1)->getValue() == HI)
		{
			return HI;
		}
		else if(inputs.at(0)->getValue() == LO || inputs.at(1)->getValue() == LO)
		{
			return LO;
		}
		else
		{
			return X;
		}
	}
	else if (type == OR) 
	{
		if (inputs.at(0)->getValue() == HI || inputs.at(1)->getValue() == HI) 
		{
			return HI;
		}
		else if(inputs.at(0)->getValue() == LO && inputs.at(1)->getValue() == LO)
		{
			return LO;
		}
		else
		{
			return X;
		}
	}
	else if (type == XOR)
	{
		if (inputs.at(0)->getValue() == X || inputs.at(1)->getValue() == X) 
		{
			return X;
		}
		else if (inputs.at(0)->getValue() != inputs.at(1)->getValue()) 
		{
			return HI;
		}
		else 
		{
			return LO;
		}
	}
	else if (type == NOT) {
		if (inputs.at(0)->getValue() == HI)
		{
			return LO;
		}
		else if (inputs.at(0)->getValue() == LO)
		{
			return HI;
		}
		else
		{
			return X;
		}
	}

	return;
}
