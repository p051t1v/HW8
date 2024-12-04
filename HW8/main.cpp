#include <iostream>
#include <fstream>
#include <string>
#include <queue>
#include "Gate.h"

using namespace std;


int main() {
	string select;
	cout << "Would you like to make a circuit or use a file?" << endl;
	cout << "Use 'F' for file and 'N' for new.";
	cin >> select;
	string fileName;
	if (select == "F") {
		cout << "Type the name of the circuit file you wish to simulate:";
		
		cin >> fileName;
		fstream fs;
		fs.open(fileName + ".txt", ios::in);
		while (!fs.is_open()) {
			cout << "Error: invalid file name. Try again: ";
			cin >> fileName;
			fs.open(fileName + ".txt", ios::in);
		}
		//read file and initialize wire and gate objects
		string input;
		vector<int> numInputs;
		string name;
		string delay;
		string type;
		int index;
		fs >> input;
		vector<Wire*> wires;
		int i = 0;
		while (!fs.eof()) {

			if (input == "input") {
				//create wire
				fs >> name >> index;
				wires.push_back(new Wire(name, index));
			}
			else if (input == "output") {
				//create wire
			}
			else if (input == "AND" || input == "OR" || input == "XOR") {
				//create gate and connect the wires and gate
				//fs >> delay >>;
				//new vector<>;
				if (input == "AND") {
					type = 2;
				}
				else if (input == "OR") {
					type = 3;
				}
				else {
					type = 4;
				}
				//new Gate(type, delay, new Wire(), new Wire());
			}
			else {
				
				//input == NOT, create and conect wires and gate
			}
			fs >> input;
		}
		fs.close();
		fs.open(fileName + "_v.txt", ios::in);
		while (!fs.is_open()) {
			cout << "Error: circuit file found but vector file missing. Exiting program.";
			return 1;
		}

		//1)
		//Read vector file and put events into event object
		//
		//2)
		//Cycle through event object and add events to history in wire objects
		//
		//3)
		//Print the wire information using history in wire objects
		//
		

		fs.close();
		queue<queue<int>> eventQueue;
	}


	
	return 0;
}
