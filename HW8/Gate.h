#pragma once
#include "Wire.h"

#Define AND = 1;
#Define OR = 2;
#Define NOT = 3;
#Define XOR =4;
#Define NAM#include <string>
#include <vector>
#include "Gate.h"
using namespace std;



class Wire {
public:
	Wire(string name, int value, vector<Gate*> drives, int index, vector<int> history);
	void Wire::SetVal(string name, int value);
	void Wire::SetHist(string name, int value, vector int& hist);
	void Wire::SetDrives();
	void printHistory() const;

private:
	int value;
	string name;
	vector<Gate*> drives;
	int index;
	vector<int> history;
};

#Define X = -1;


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