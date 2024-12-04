#pragma once
#include "Wire.cpp"
#include "Wire.h"
#include <vector>
#include <string>

#define HI 1
#define LO 0
#define DNF -1
#define X = -1;

#define NOT = 1;
#define AND = 2;
#define OR = 3;
#define XOR = 4;


using namespace std;

class Gate {
	//Default constructor
	Gate(int type, int delay, vector<Wire*> inputs, Wire* output);

	//Get everything
	int getDelay(int delay) const;
	Wire* getInput(int input) const;
	Wire* getOutput() const;
	//Evaluate the gate
	int evaluate() const;

private:
	int type;
	int delay;
	vector<Wire*> inputs;
	Wire* output;

};