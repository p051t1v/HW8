
// Author:  Jonah Teal
// Date:    10/8/24
// Purpose: To implement a simple, sorted linked-list of positive integers

#include "Wire.h"

Wire::Wire(string name,int index){
	this->name = name;
		this->index = index;
}


void Wire::SetVal(int index, int value) {
	this->value = value;
}

void Wire::SetHist(int value, vector <int>& hist)
{
	if (value != NULL)
	{
		hist.push_back(this->value);
	}
}

void Wire::AddDrives(Gate* gate) 
{
	drives.push_back(gate);
}

vector<int> Wire::getHistory()
{
	return history;
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

void printHistory(vector<int> hist) const
{
	for (int i:hist)
	{
		if (i == 0)
		{
			cout << "_";
		}
		else if (i == 1)
		{
			cout << "-";
		}
		else
		{
			cout << "X";
		}
	}
}