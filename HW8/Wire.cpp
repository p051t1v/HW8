#include "Wire.h"
#include <iostream>

Wire::Wire(string name, int index, vector<int>& hist)
	:name(name),index(index), hist(hist){}

Wire::Wire(string name, int index)
	:name(name),index(index),hist(hist){}

// Set everything
void Wire::SetVal(int value) {
	this->value = value;
}

void Wire::SetHist(int value)
{
		hist.push_back(value);
}
//Adding Drives (inputs) to a gate
void Wire::AddDrives(Gate* gate) 
{
	drives.push_back(gate);
}
// Get Everything
vector<int> Wire::getHistory()
{
	
	return hist;
}

vector<Gate*> Wire::getDrives()
{
	return drives;
}

int Wire::getIndex()
{
	return index;
}

string Wire::getName()
{
	return name;
}

int Wire::getValue()
{
	return value;
}

// Print Function
void Wire::printHistory(vector<int> hist) const
{
	cout << name <<" |";

	for (int i:hist)
	{
		if (i == LO)
		{
			cout << "_";
		}
		else if (i == HI)
		{
			cout << "-";
		}
		else
		{
			cout << "X";
		}
	}
}