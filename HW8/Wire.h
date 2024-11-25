<<<<<<< HEAD
#pragma once
#include <string>
#include <vector>
#include "Gate.h"



using namespace std;



class Wire {
public:
	Wire(string name, int index);
	void SetVal(int index, int value);
	void SetHist(int value, vector <int>& hist );
	void AddDrives(Gate* gate);
	// get everyting
	int getValue();
	string getName();
	int getIndex();
	vector<int> getHistory();
	vector<Gate*> getDrives();
	void printHistory(vector<int> hist) const;
private:
	int value=DNF;
	string name="~";
	vector<Gate*> drives;
	int index=0;
	vector<int> history;
};
