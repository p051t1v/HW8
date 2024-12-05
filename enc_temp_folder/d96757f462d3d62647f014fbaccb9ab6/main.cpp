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

	cout << "Paste the path of the circuit file you wish to simulate: (take the quotation marks off and have the files in the same";
		cout<<" directory. Also, take the txt off and make sure one both files have the same name with the only difference being the";
		cout << "vector file having the ending _v.txt. Thank you!) :)";
		cin >> fileName;
		cout <<"\n" << fileName<<endl;
		
		fs.open(fileName, ios::in);
		cout <<"\n" << fileName << endl;
		while (!fs.is_open()) {
			cout << "Error: invalid file name. Try again: ";
			cin >> fileName;
			fs.open(fileName + ".txt", ios::in);
		}


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

			if (input == "INPUT") {
				//create wire
				fs >> name >> index;
				wires.push_back(new Wire(name, index));
			}
			else if (input == "OUTPUT") {
				//create wire
			}
			else if (input == "AND" || input == "OR" || input == "XOR") {
				//create gate and connect the wires and gate
				int n1, n2, n3;
				
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
				fs >> delay >> n1 >> n2 >> n3;
				for (int i = 0; i < inputs.size() || i < 70; i++) {
					if (wires.at(i)->getValue() == n1 || wires.at(i)->getValue() == n2) {
						inputs.push_back(wires.at(i));
					}
				}
				//new Gate(type, delay, new Wire(), new Wire());

			}
			else {
				
				//input == NOT, create and conect wires and gate
			}
			fs >> input;
		}

		fs.close();
		fileName.erase(fileName.size()-4);
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


	
	

