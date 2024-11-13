#pragma once
#include "Wire.h"

#Define AND = 1;
#Define OR = 2;
#Define NOT = 3;


using namespace std;

class Gate {
	Gate();
	int getDelay() const;
	Wire* getInput(int input) const;
	Wire* getOutput() const;
	bool evaluate() const;

private:
	int type;
	int delay;
	vector<Wire*> inputs;
	Wire* output;

};