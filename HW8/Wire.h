
#include <string>
#include <vector>
class Gate;

#define HI  1
#define LO  0
#define DNF -1
#define X -1

#define NOT  1
#define AND  2
#define OR  3
#define XOR  4

using namespace std;

class Wire {
public:
	Wire(string name, int index);

	//Set everything
	void SetVal(int value);
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
	int value = DNF;
	string name="~";
	vector<Gate*> drives;
	int index=0;
	vector<int> history;
};
