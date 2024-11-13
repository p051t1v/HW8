#pragma once
#include <string>
#include <vector>
#include "Gate.h"
using namespace std;



class Wire {
public:
	Wire();
	void Wire::SetVal();
	void Wire::SetHist();
	void Wire::SetDrives();
	void printHistory() const;

private:
	int value;
	string name;
	vector<Gate*> drives;
	int index;
	vector<int> history;
};