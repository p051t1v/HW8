#pragma once
#include "Wire.h"

using namespace std;

class Gate {
	Gate(int type, int delay, vector<Wire*> inputs, Wire* output);
	int getDelay() const;
	Wire* getInput(int) const;
	Wire* getOutput() const;
	bool evaluate() const;

private:
	int type;
	int delay;
	vector<Wire*> inputs;
	Wire* output;

};