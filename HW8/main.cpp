#include <iostream>
#include <fstream>
#include <string>
#include <queue>

#include "Gate.h"
#include "Wire.h"
#include "CircuitEvent.h"

using namespace std;


int main() {
	string select;
	fstream fs;
	string fileName;

	cout << "Paste the path of the circuit file you wish to simulate (take the quotation marks off and have the files in the same";
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
		Wire* output = nullptr;
		string name;
		string delay;
		
		int type;
		int index;
		fs >> input;
		vector<Wire*> wires;
		vector<Gate*> gates;
		Gate* tempGate;
		int i = 0;
		while (!fs.eof()) {

			if (input == "INPUT") {
				//create wire
				fs >> name >> index;
				wires.push_back( new Wire (name, index));
			}
			else if (input == "OUTPUT") {
				//create wire
				fs >> name >> index;
				wires.push_back(new Wire(name, index));
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

				delay.erase(delay.size() - 2);

				for (int i = 0; i < wires.size(); i++) {
					if (wires.at(i)->getIndex() == n1 || wires.at(i)->getIndex() == n2) {
						inputs.push_back(wires.at(i));
					}
				}
				for (int i = 0; i < wires.size(); i++) {
					if (wires.at(i)->getIndex() == n3) {
						output = wires.at(i);
					}
				}
				tempGate = new Gate(type, stoi(delay), inputs, output);
				for (int i = 0; i < inputs.size(); i++) {
					inputs.at(i)->AddDrives(tempGate);
				}

				inputs.clear();
				output = nullptr;
			}
			else if (input == "NOT") {
				//input == NOT, create and conect wires and gate
				int n1, n2;
				fs >> delay >> n1 >> n2;
				delay.erase(delay.size() - 2);
				for (int i = 0; i < wires.size(); i++) {
					if (wires.at(i)->getIndex() == n1) {
						inputs.push_back(wires.at(i));
					}
				}
				for (int i = 0; i < wires.size(); i++) {
					if (wires.at(i)->getIndex() == n2) {
						output = wires.at(i);
					}
				}
				tempGate = new Gate(type, stoi(delay), inputs, output);
				for (int i = 0; i < inputs.size(); i++) {
					inputs.at(i)->AddDrives(tempGate);
				}
				inputs.clear();
				output = nullptr;
			}
			fs >> input;
		}
		struct {
			int time;
			int value;
			Wire* w;
		} circiutEvent;
		//1)
		//Read vector file and put events into event object
		fs.close();
		fileName.erase(fileName.size()-4);
		fs.open(fileName + "_v.txt", ios::in);
		while (!fs.is_open()) {
			char ans;
			cout << "Error: circuit file found but vector file missing. Does it have a different pathway? \n (Y/N)"<<endl;
			cin >> ans;
			if (ans == 'Y') {
				cout << "do the exact same thing you did to the other file.Put it in here without the quotations or file type"<<endl;
				cin >> fileName;
				fs.open(fileName + "_v.txt", ios::in);
			}
			else {
				cout << "I'm sorry, I cannot help you.";
				return 1;
			}
			
		}

		fs >> input;
		int time, value;
		//CircuitEvent events;
		while (!fs.eof()) {
			if (input == "INPUT") {
				fs >> name >> time >> value;
				Wire* tempWire;
				for (int i = 0; i < wires.size(); i++) {
					if (wires.at(i)->getName() == name) {
						tempWire = wires.at(i);
					}
				}
				//events.AddEvent(time, value, tempWire);
			}
			fs >> input;
		}
		fs.close();

		//2)
		//Cycle through event object and add events to history in wire objects
		
		for (int t = 0; t <= 60 /*&& !events.empty()*/; t++) {
			//
			//
			//
			//
			//
			//
			//
			// do history
			 for (int h; h <= wires.size(); h++){
				 wires.at(i)->SetHist(wires.at(i)->getValue());
			 }
			// 
			//events.NextEvent();
			
		}

		//
		//3)
		//Print the wire information using history in wire objects
		//
		
		
		
		queue<queue<int>> eventQueue;
	
		return 0;
}


	
	

