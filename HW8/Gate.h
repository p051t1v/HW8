#pragma once
#include "Wire.cpp"
#include <vector>
#include <string>


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