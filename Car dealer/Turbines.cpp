#include "Turbines.h"

std::string StandardTurbine::getinfo() {
	return "Standard";
}
double StandardTurbine::getRoadSpeedMultiplier(){
	return 1.0;
}
double StandardTurbine::getOffRoadSpeedMultiplier()  {
	return 1.0;
}
Turbine* StandardTurbine::clone() 
{
	return new StandardTurbine;
}
std::string TurboTurbine::getinfo()  {
	return "Turbo";
}
double TurboTurbine::getRoadSpeedMultiplier()  {
	return 1.5;
}
double TurboTurbine::getOffRoadSpeedMultiplier()  {
	return 0.9;
}
Turbine* TurboTurbine::clone() 
{
	return new TurboTurbine;
}

std::string DualTurbine::getinfo()  {
	return "Dual";
}
double DualTurbine::getRoadSpeedMultiplier()  {
	return 1.4;
}
double DualTurbine::getOffRoadSpeedMultiplier()  {
	return 1.1;
}
Turbine* DualTurbine::clone() 
{
	return new DualTurbine;
}

std::string BoostTurbine::getinfo() {
	return "Boost";
}
double BoostTurbine::getRoadSpeedMultiplier() {
	return 1.2;
}
double BoostTurbine::getOffRoadSpeedMultiplier() {
	return 1.3;
}
Turbine* BoostTurbine::clone() 
{
	return new BoostTurbine;
}