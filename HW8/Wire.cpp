
// Author:  Jonah Teal
// Date:    10/8/24
// Purpose: To implement a simple, sorted linked-list of positive integers

#include "Wire.h"

Wire::Wire(string name, int value, vector<Gate*> drives, int index, vector<int> history){
	
}

void Wire::SetVal(string name, int value) {
	this->value = value;
}

void Wire::SetHist(string name, int value, vector <int>& hist) {
	if (value != NULL){
		hist.push_back(this->value);
	}
}

void Wire::SetDrives(string name, vector<Gate*> drives) {
	
}

void printHistory(string name, vector<int> hist) const{
	
		for (hist.size()) {
			if (hist.at(i) == 0){
			cout<<"_"
			}
			else if (hist.at(i) == 1) {
			cout<<"-"
			}
		}
}