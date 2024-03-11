#include "Wheels.h"

std::string Wheels::info()
{
	return ("Wheels type: " + gettype());
}
std::string Wheels::maxRoadSpeed()
{
	return "Max wheels road speed: " + std::to_string(getMaxRoadSpeed());
}
std::string Wheels::maxOffRoadSpeed()
{
	return "Max wheels offroad speed: " + std::to_string(getMaxOffRoadSpeed());
}
int StandardWheels::getMaxRoadSpeed()
{
	return 270;
}
int StandardWheels::getMaxOffRoadSpeed()
{
	return 130;
}
double StandardWheels::getRoadSpeedMultiplier()
{
	return 1;
}
double StandardWheels::getOffRoadSpeedMultiplier() 
{
	return 0.9;
}
std::string StandardWheels::gettype() 
{
	return wheeltypes[STANDARD];
}
Wheels* StandardWheels::clone()
{
	return new StandardWheels;
}
int  TrackWheels::getMaxRoadSpeed() 
{
	return 500;
}
int  TrackWheels::getMaxOffRoadSpeed()
{
	return 100;
}
double  TrackWheels::getRoadSpeedMultiplier() 
{
	return 1.5;
}
double TrackWheels::getOffRoadSpeedMultiplier()
{
	return 0.7;
}
std::string TrackWheels::gettype() 
{
	return wheeltypes[TRACK];
}
Wheels* TrackWheels::clone() 
{
	return new TrackWheels;
}
int OffRoadWheels::getMaxRoadSpeed() 
{
	return 220;
}
int OffRoadWheels::getMaxOffRoadSpeed()
{
	return 310;
}
double OffRoadWheels::getRoadSpeedMultiplier()
{
	return 0.8;
}
double OffRoadWheels::getOffRoadSpeedMultiplier()
{
	return 1.6;
}
std::string OffRoadWheels::gettype()
{
	return wheeltypes[OFFROAD];
}
Wheels* OffRoadWheels::clone()
{
	return new OffRoadWheels;
}

int DriftWheels::getMaxRoadSpeed()
{
	return 320;
}
int DriftWheels::getMaxOffRoadSpeed() 
{
	return 160;
}
double DriftWheels::getRoadSpeedMultiplier() 
{
	return 1.2;
}
double DriftWheels::getOffRoadSpeedMultiplier() 
{
	return 1;
}
std::string DriftWheels::gettype()
{
	return wheeltypes[DRIFT];
}
Wheels* DriftWheels::clone()
{
	return new DriftWheels;
}