
#include <string>
#include <vector>
#include "Gate.h"
#include "Wire.cpp"

using namespace std;

class Wire {
public:
	Wire(string name, int index);

	//Set everything
	void SetVal(int index, int value);
	void SetHist(int value, vector <int>& hist );
	void AddDrives(Gate* gate);
	//Get everyting
	int getValue();
	string getName();
	int getIndex();
	vector<int> getHistory();
	vector<Gate*> getDrives();
	//Print UI
	void printHistory(vector<int> hist) const;
private:
	//Variable Defaults
	int value=DNF;
	string name="~";
	vector<Gate*> drives;
	int index=0;
	vector<int> history;
};
