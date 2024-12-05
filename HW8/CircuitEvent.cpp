#include "CircuitEvent.h"
#include <vector>
#include <algorithm>

CircuitEvent::CircuitEvent(int time, int value, Wire* w)
: time(time),value(value),w(w){}

CircuitEvent::CircuitEvent()
{
}

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

vector<CircuitEvent> CircuitEvent::SortEvents(vector<CircuitEvent> EZ){
		
}
void CircuitEvent::SortEvents(vector<CircuitEvent> EZ){
	vector<CircuitEvent> tempEvents;
	for (int i = 0; i <= EZ.size(); i++) {
		if (i + 1 == tempEvents.size()) {
			tempEvents.push_back(EZ.at(i));
		}
		for (int j = 0; j <= tempEvents.size(); j++) {
			if (!(EZ.at(i).GetTime() <= 1)) {

			}
		}
	}
}

CircuitEvent CircuitEvent::GetNextEvent(vector<CircuitEvent> NE)
{

}

