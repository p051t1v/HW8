#include <iostream>
#include <fstream>
#include <string>
#include <queue>
#include "Gate.h"
#include "Wire.h"

using namespace std;


int main() {
	string select;
	fstream fs;
	string fileName;

		cout << "Type the name of the circuit file you wish to simulate:";
		cin >> fileName;
		
		fs.open(fileName, ios::in);
		cout <<"\n" << fileName << endl;
		while (!fs.is_open()) {
			cout << "Error: invalid file name. Try again: ";
			cin >> fileName;
			fs.open(fileName + ".txt", ios::in);
		}
	//else if(select=="N") {
		//cout << "type your output like this: \n  CIRCUIT curcuit name here \n ";

	//}
		//read file and initialize wire and gate objects
		string input;
		vector<int> numInputs;
		vector<Wire*> inputs;
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
				int n1, n2, n3;
				//fs >> delay >> n1 >> n2 >> n3;
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
	
		return 0;
}


	
	

