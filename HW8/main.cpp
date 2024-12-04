#include <iostream>
#include <fstream>
#include <string>
#include <queue>
#include <Gate.cpp>

using namespace std;


int main() {
	string select;
	cout << "Would you like to make a circuit or use a file?" << endl;
	cout << "Use 'F' for file and 'N' for new.";
	cin >> select;
	if (select == "F") {
		cout << "Type the name of the circuit file you wish to simulate:";
		string fileName;
		cin >> fileName;
		fstream fs;
		fs.open(fileName + ".txt", ios::in);
		while (!fs.is_open()) {
			cout << "Error: invalid file name. Try again: ";
			cin >> filename;
			fs.open(fileName + ".txt", ios::in);
		}
		//read file and initialize wire and gate objects
		string input;
		char name;
		int index;
		fs >> input;
		vector<Wire> wires;
		while (!fs.eof()) {
			if (input == "input") {
				//create wire
				fs >> name >> index;
				new Wire(name, index);
			}
			else if (input == "output") {
				//create wire
			}
			else{
				//create gate and connect the wires
			}
			fs >> input;
		}
		fs.close();
		fs.open(fileName + "_v.txt", ios::in);
		while (!fs.is_open()) {
			cout << "Error: circuit file found but vector file missing. Exiting program.";
			return 1;
		}
		//read vector file and create event vector

		fs.close();
		queue<queue<int>> eventQueue;
	}


	
	return 0;
}
