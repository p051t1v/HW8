#include "CircuitEvent.h"
#include <vector>
#include <algorithm>
#include <iostream>
#include <stdexcept>

CircuitEvent::CircuitEvent(int time, int value, Wire* w)
: time(time),value(value),w(w){}

CircuitEvent::CircuitEvent()
: time(0), value(0), w(nullptr){}

//Setters
void CircuitEvent::SetTime(int time){
	this->time = time;
}

void CircuitEvent::SetValue(int value)
{
	this->value = value;
}

void CircuitEvent::SetWire(Wire* w)
{
	this->w = w;
}


//Getters
int CircuitEvent::GetTime()
{
	return time;
}

int CircuitEvent::GetValue()
{
	return value;
}

Wire* CircuitEvent::GetWire()
{
	return w;
}

vector<CircuitEvent> CircuitEvent::GetCE()
{
	return CE;
}

bool CircuitEvent::IsEmpty(CircuitEvent& e)
{
	if (e == *CE.end()) {

	if (e == CE.back()) {
		return true;
	}
	return false;
}



void CircuitEvent::SortEvents(vector<CircuitEvent>& EZ) {
	sort(EZ.begin(), EZ.end(), [](const CircuitEvent& a, const CircuitEvent& b) {
		return a.time < b.time;
		});
}

void CircuitEvent::AddEvent(int time, int value, Wire* w){
	CE.push_back(CircuitEvent(time, value, w));
	(*this).SortEvents(CE);
}




CircuitEvent CircuitEvent::GetNextEvent(vector<CircuitEvent> NE)
{
	if (NE.empty()) {
		return CircuitEvent();
	}
	auto it = find(NE.begin(), NE.end(), *this); 
		if (it == NE.end()) {
		throw runtime_error("current event not found in the vector");
	}

		auto nextIt = it + 1;
	if (nextIt != NE.end()) {
		return *(nextIt);
	}
	else {
		cout << "done reading the vector or no object" << endl;
		return ;
	}

}
//equality operator
bool CircuitEvent::operator==(const CircuitEvent& other) const {
	return this->time == other.time && this->value == other.value && this->w == other.w;
}

//compare time
bool CircuitEvent::timeCompare(const CircuitEvent& other) const {
	return this->time == other.time;
}