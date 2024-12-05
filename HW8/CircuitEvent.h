#pragma once
#include "Wire.h"
#include "Gate.h"

using namespace std;

class CircuitEvent {
public:
	CircuitEvent(int time, int value, Wire* w);

	// add the time to other events and then place it in that order
	void AddEvent(int time, int value, Wire* w);

	void SortEvents(vector<CircuitEvent>);

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