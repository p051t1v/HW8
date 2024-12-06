#pragma once
class Wire;
class Gate;
#include <vector>

using namespace std;

class CircuitEvent {
public:
	CircuitEvent(int time, int value, Wire* w);
	CircuitEvent();


	//should sort the vector to have the highest time at the back
	void SortEvents(vector<CircuitEvent>& EZ);


	// add the time to other events and then place it in that order
	void AddEvent(int time, int value, Wire* w);


	CircuitEvent GetNextEvent(vector<CircuitEvent> NE);

	//Equality operator
	bool operator==(const CircuitEvent& other) const;

	bool EventCompare(const CircuitEvent& other) const;

	//Setters

	void SetTime(int time);
	void SetValue(int value);
	void SetWire(Wire* w);

	//Getters
	int GetTime();
	int GetValue();
	Wire* GetWire();
	vector<CircuitEvent> GetCE();
	bool IsEmpty(CircuitEvent& e);
	bool timeCompare(const CircuitEvent& other) const;
private:
	int time;
	int value;
	Wire* w;
	vector <CircuitEvent> CE;
	vector <CircuitEvent> NEW;


};