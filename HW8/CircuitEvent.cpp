#include "CircuitEvent.h"
#include <vector>
#include <algorithm>

CircuitEvent::CircuitEvent(int time, int value, Wire* w)
: time(time),value(value),w(w){}

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
int CircuitEvent::getTime()
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

