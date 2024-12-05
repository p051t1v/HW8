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
void Gate::evaluate() const
{
	
	if((inputs.at(0)->getValue() == X) && (inputs.at(0)->getValue() == X))
	{
		output->SetVal(HI);

	}
	else if (type == AND)
	{
		if (inputs.at(0)->getValue() == HI && inputs.at(1)->getValue() == HI)
		{
			output->SetVal(HI);
		}
		else if(inputs.at(0)->getValue() == LO || inputs.at(1)->getValue() == LO)
		{
			output->SetVal(LO);
		}
		else
		{
			output->SetVal(X);
		}
	}
	else if (type == OR) 
	{
		if (inputs.at(0)->getValue() == HI || inputs.at(1)->getValue() == HI) 
		{
			output->SetVal(HI);
		}
		else if(inputs.at(0)->getValue() == LO && inputs.at(1)->getValue() == LO)
		{
			output->SetVal(LO);
		}
		else
		{
			output->SetVal(X);
		}
	}
	else if (type == XOR)
	{
		if (inputs.at(0)->getValue() == X || inputs.at(1)->getValue() == X) 
		{
			output->SetVal(X);
		}
		else if (inputs.at(0)->getValue() != inputs.at(1)->getValue()) 
		{
			output->SetVal(HI);
		}
		else 
		{
			output->SetVal(LO);
		}
	}
	else if (type == NOT) {
		if (inputs.at(0)->getValue() == HI)
		{
			output->SetVal(LO);
		}
		else if (inputs.at(0)->getValue() == LO)
		{
			output->SetVal(HI);
		}
		else
		{
			output->SetVal(X);
		}
	}
	output->SetHist(output->getValue(),output->hist);

	return;
}
