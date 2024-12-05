#include "CircuitEvent.h"
#include <vector>
#include <algorithm>
#include <iostream>
#include <stdexcept>

CircuitEvent::CircuitEvent(int time, int value, Wire* w)
: time(time),value(value),w(w){}

CircuitEvent::CircuitEvent():
 time(0), value(0), w(nullptr){}

//Setters
void CircuitEvent::setTime(int time){
	this->time = time;
}

void CircuitEvent::setValue(int value)
{
	this->value = value;
}

void CircuitEvent::setWire(Wire* w)
{
	this->w = w;
}


//Getters
int CircuitEvent::GetTime()
{
	return time;
}

int CircuitEvent::getValue()
{
	return value;
}

Wire* CircuitEvent::getWire()
{
	return w;
}





void CircuitEvent::AddEvent(int time, int value, Wire* w){
	CE.push_back(CircuitEvent(time, value, w));
}


void CircuitEvent::SortEvents(vector<CircuitEvent> EZ){
	std::sort(EZ.begin(), EZ.end(), [](CircuitEvent& a, CircuitEvent& b) {
		return a.time < b.time;
	}
);
}

CircuitEvent CircuitEvent::GetNextEvent(vector<CircuitEvent> NE)
{
	if (NE.empty()) {
		return CircuitEvent();
	}
	auto it = std::find(NE.begin(), NE.end(), *this); 
		if (it == NE.end()) {
		throw std::runtime_error("current event not found in the vector");
	}

		auto nextIt = it + 1;
	if (nextIt != NE.end()) {
		return *(nextIt);
	}
	else {
		cout << "done reading the vector or no object" << endl;
		return CircuitEvent();
	}

}
//equality operator
bool CircuitEvent::operator==(const CircuitEvent& other) const {
	return this->time == other.time;
}
