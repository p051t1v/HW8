#pragma once
#include "Wire.h"
#include <vector>
#include <string>

#define HI 1
#define LO 0
#define DNF -1
#define X = -1;

#define AND = 1;
#define OR = 2;
#define NOT = 3;
#define XOR = 4;


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