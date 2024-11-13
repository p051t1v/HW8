<<<<<<< HEAD
#pragma once
#include <string>
#include <vector>
#include "Gate.h"
using namespace std;



class Wire {
public:
	Wire(string name, int value, vector<Gate*> drives, int index, vector<int> history);
	void SetVal(string name, int value);
	void SetHist(string name, int value, vector <int>& hist );
	void SetDrives(string name, vector<Gate*> drives);
	void printHistory(string name, vector<int> hist) const;
private:
	int value;
	string name;
	vector<Gate*> drives;
	int index;
	vector<int> history;
};
