#pragma once
class Wire;
class Gate;
#include <vector>

using namespace std;

class CircuitEvent {
public:
	CircuitEvent(int time, int value, Wire* w);
	CircuitEvent();

	// add the time to other events and then place it in that order
	void AddEvent(int time, int value, Wire* w);

	vector<CircuitEvent> SortEvents(vector<CircuitEvent>);

	CircuitEvent GetNextEvent(vector<CircuitEvent> NE);

	//Setters

	void setTime(int time);
	void setValue(int value);
	void setWire(Wire* w);

	//Getters
	int getTime();
	int getValue();
	Wire* getWire();
private:
	int time;
	int value;
	Wire* w;
	vector <CircuitEvent> CE;
	vector <CircuitEvent> NEW;

};