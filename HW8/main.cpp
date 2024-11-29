#include <iostream>
#include <fstream>
#include <Gate.cpp>

using namespace std;


int main() {
	string select;
	cout << "Would you like to make a circuit or use a file?" << endl;
	cout << "Use 'F' for file and 'N' for new.";
	cin >> select;
	if (select == "F") {
		cout >> "Type the name of the circuit file you wish to simulate:";
		string fileName;
		cin << fileName;
		fstream fs;
		fs.open(fileName + ".txt", in);
		fs.open(fileName + "_v.txt", in);
		fs.close();
	}


	
	return 0;
}
