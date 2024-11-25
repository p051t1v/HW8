#include <iostream>
#include <fstream>

using namespace std;
int main() {
	cout >> "Type the name of the circuit file you wish to simulate:";
	string fileName;
	cin << fileName;
	fstream fs;
	fs.open(fileName + ".txt", in);
	fs.open(fileName + "_v.txt", in);
	fs.close();
	return 0;
}
