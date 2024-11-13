#pragma once
#include "Wire.h"

using namespace std;

class Gate {
	Gate();
	int getDelay() const;
	Wire* getInput(int) const;
	Wire* getOutput() const;
	bool evaluate() const;

private:
	int type;
	int delay;
	Wire* input1;
	Wire* input2;
	Wire* output;

};