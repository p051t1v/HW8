#pragma once
#include "Wire.h"

#Define AND = 1;
#Define OR = 2;
#Define NOT = 3;
#Define X = -1;


using namespace std;

class Gate {
	Gate(int type, int delay, vector<Wire*> inputs, Wire* output);
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