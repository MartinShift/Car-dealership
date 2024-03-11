#include "gearbox.h"
Gearbox::Gearbox(int max)
{
	this->current = 1;
	this->maxgears = max;
}
void Gearbox::up()
{
	if(current!=maxgears) current++;
}
void Gearbox::down()
{
	if (current > 1) current--;
}
double Gearbox::getmultiplier()
{
	return 1.0 * current / maxgears;
}
int Gearbox::getcurrent() { return current; }
int Gearbox::getmax() { return maxgears; }
Gearbox* Gearbox::clone()
{
	return new Gearbox(maxgears);
}
void Gearbox::set(int gear)
{
	if(gear<=maxgears)
	this->current = gear;
}