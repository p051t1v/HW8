#pragma once
#include "Wire.h"


#include <vector>
#include "Gate.h"

#define AND = 1;
#define OR = 2;
#define NOT = 3;
#define XOR = 4;
#define NAM#include <string>

using namespace std;





using namespace std;

class Gate {
	Gate(int type, int delay, vector<Wire*> inputs, Wire* output);
	int getDelay(int delay) const;
	Wire* getInput(int input) const;
	Wire* getOutput() const;
	int evaluate() const;

private:
	int type;
	int delay;
	vector<Wire*> inputs;
	Wire* output;

};