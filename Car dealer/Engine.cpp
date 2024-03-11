#include "Engine.h"
Engine::Engine(Turbine * turbine)
{
	this->turbine = turbine;
}
Engine::Engine(Engine* engine)
{
	this->turbine = engine->turbine;
}
Engine::Engine() {}

void Engine::setTurbine(Turbine* turbine)
{
	this->turbine = turbine;
}
double Engine::getSpeed(Fuel& fuel, Wheels& wheels, Gearbox& gearbox, bool road) {
	checkfueltype(fuel);
	return (road ? fuel.getRoadSpeed() * turbine->getRoadSpeedMultiplier() * wheels.getRoadSpeedMultiplier() : fuel.getOffRoadSpeed() * turbine->getOffRoadSpeedMultiplier() * wheels.getOffRoadSpeedMultiplier()) * gearbox.getmultiplier();
}
std::string Engine::maxRoadspeed(Fuel& fuel, Wheels& wheels)
{
	return("Engine max road speed: " + std::to_string(getSpeed(fuel, wheels, *new Gearbox(1), true)));
}
std::string Engine::maxOffroadspeed(Fuel& fuel, Wheels& wheels)
{
	return("Engine max offroad speed: " + std::to_string(getSpeed(fuel, wheels, *new Gearbox(1), false)));
}
Engine::~Engine()
{
	delete turbine;
}
void Engine::operator=(Engine* engine)
{
	this->turbine = engine->turbine;
}

Gasoline92_95Engine::Gasoline92_95Engine(Turbine* turbine) : Engine(turbine) {}
std::string Gasoline92_95Engine::info(Fuel& fuel, Wheels& wheels, Gearbox& gearbox) {
	return ("Gasoline92/95 "+ std::to_string(fuel.getMaxVolume()) + "L " + turbine->getinfo() + " engine");
}
void Gasoline92_95Engine::checkfueltype(Fuel& fuel)
{
	if (fuel.gettype() != fueltypes[GASOLINE92] and fuel.gettype() != fueltypes[GASOLINE95])
	{
		throw("Incompitable fuel");
	}
}
Engine* Gasoline92_95Engine::clone()
{
	return new Gasoline92_95Engine(turbine->clone());
}

Gasoline95_98Engine::Gasoline95_98Engine(Turbine* turbine) : Engine(turbine) {}
std::string Gasoline95_98Engine::info(Fuel& fuel, Wheels& wheels, Gearbox& gearbox) {
	return ("Gasoline95/98 " + std::to_string(fuel.getMaxVolume()) + "L " + turbine->getinfo() + " engine");
}
void Gasoline95_98Engine::checkfueltype(Fuel& fuel)
{
	if (fuel.gettype() != fueltypes[GASOLINE95] and fuel.gettype() != fueltypes[GASOLINE98])
	{
		throw("Incompitable fuel");
	}
}
Engine* Gasoline95_98Engine::clone()
{
	return new Gasoline95_98Engine(turbine->clone());
}

Gasoline98_100Engine::Gasoline98_100Engine(Turbine* turbine) : Engine(turbine) {}
std::string Gasoline98_100Engine::info(Fuel& fuel, Wheels& wheels, Gearbox& gearbox) {
	return ("Gasoline98/100 " + std::to_string(fuel.getMaxVolume()) + "L " + turbine->getinfo() + " engine");
}
void Gasoline98_100Engine::checkfueltype(Fuel& fuel) 
{
	if (fuel.gettype() != fueltypes[GASOLINE98] and fuel.gettype() != fueltypes[GASOLINE100])
	{
		throw("Incompitable fuel");
	}
}
Engine* Gasoline98_100Engine::clone() 
{
	return new Gasoline98_100Engine(turbine->clone());
}

std::string GasEngine::info(Fuel& fuel, Wheels& wheels, Gearbox& gearbox) {
	return ("Gas " + std::to_string(fuel.getMaxVolume()) + "L " + turbine->getinfo() + " engine");
}
GasEngine::GasEngine(Turbine* turbine) : Engine(turbine) {}
void GasEngine::checkfueltype(Fuel& fuel) 
{
	if (fuel.gettype() != fueltypes[GAS])
	{
		throw("Incompitable fuel");
	}
}
Engine* GasEngine::clone() 
{
	return new GasEngine(turbine->clone());
}

DieselEngine::DieselEngine(Turbine* turbine) : Engine(turbine) {}
std::string DieselEngine::info(Fuel& fuel, Wheels& wheels, Gearbox& gearbox) {
	return ("Diesel " + std::to_string(fuel.getMaxVolume()) + "L " + turbine->getinfo() + " engine");
}
void DieselEngine::checkfueltype(Fuel& fuel) 
{
	if (fuel.gettype() != fueltypes[DIESEL])
	{
		throw("Incompitable fuel");
	}
}
Engine* DieselEngine::clone() 
{
	return new DieselEngine(turbine->clone());
}
ElectricEngine::ElectricEngine(Turbine* turbine) : Engine(turbine) {}
std::string ElectricEngine::info(Fuel& fuel, Wheels& wheels, Gearbox& gearbox) {
	return ("Gasoline92/95 " + std::to_string(fuel.getMaxVolume()) + "L " + turbine->getinfo() + " engine");
}
void ElectricEngine::checkfueltype(Fuel& fuel) 
{
	if (fuel.gettype() != fueltypes[ELECTRIC])
	{
		throw("Incompitable fuel");
	}
}
Engine* ElectricEngine::clone()
{
	return new ElectricEngine(turbine->clone());
}

BoatEngine::BoatEngine(Turbine* turbine, Propeller* propeller) : Engine(turbine) { this->propeller = propeller; }
BoatEngine::BoatEngine(BoatEngine* engine) { this->propeller = engine->propeller; this->turbine = engine->turbine; }
double BoatEngine::getSpeed(Fuel& fuel, Gearbox& gearbox) {
	checkfueltype(fuel);
	return fuel.getRoadSpeed() * turbine->getRoadSpeedMultiplier() * propeller->getAccelerator() * gearbox.getmultiplier();
}
BoatEngine::~BoatEngine()
{
	delete propeller;
}
std::string BoatEngine::getmaxspeed(Fuel& fuel, Gearbox& gearbox)
{
	return "Max speed: " + std::to_string(getSpeed(fuel, *new Gearbox(1)));
}

Propeller* BoatEngine::getpropeller()
{
	return propeller;
}
GasolineAllBoatEngine::GasolineAllBoatEngine(Turbine* turbine, Propeller* propeller) : BoatEngine(turbine, propeller) {}
std::string GasolineAllBoatEngine::info(Fuel& fuel, Gearbox& gearbox)  {
	return ("Gasoline all " + std::to_string(fuel.getMaxVolume()) + "L " + turbine->getinfo() + " boat engine");
}
std::string GasolineAllBoatEngine::info(Fuel& fuel, Wheels& wheels, Gearbox& gearbox) { return ""; }
BoatEngine* GasolineAllBoatEngine::clone()
{
	return new GasolineAllBoatEngine(turbine->clone(), propeller->clone());
}
void GasolineAllBoatEngine::checkfueltype(Fuel& fuel) 
{
	if (fuel.gettype() != fueltypes[GASOLINE92] and fuel.gettype() != fueltypes[GASOLINE95] and fuel.gettype() != fueltypes[GASOLINE98] and fuel.gettype() != fueltypes[GASOLINE100])
	{
		throw("Incompitable fuel");
	}
}

GasBoatEngine::GasBoatEngine(Turbine* turbine, Propeller* propeller) : BoatEngine(turbine, propeller) {}
std::string GasBoatEngine::info(Fuel& fuel, Gearbox& gearbox) {
	return ("Gas " + std::to_string(fuel.getMaxVolume()) + "L " + turbine->getinfo() + " boat engine");
}
std::string GasBoatEngine::info(Fuel& fuel, Wheels& wheels, Gearbox& gearbox) { return ""; }
BoatEngine* GasBoatEngine::clone()
{
	return new GasolineAllBoatEngine(turbine->clone(), propeller->clone());
}
void GasBoatEngine::checkfueltype(Fuel& fuel)
{
	if (fuel.gettype() != fueltypes[GAS])
	{
		throw("Incompitable fuel");
	}
}

ElectricBoatEngine::ElectricBoatEngine(Turbine * turbine, Propeller * propeller) : BoatEngine(turbine, propeller) {}
std::string ElectricBoatEngine::info(Fuel& fuel, Gearbox& gearbox)  {
	return ("Electric " + std::to_string(fuel.getMaxVolume()) + "L " + turbine->getinfo() + " boat engine");
}
std::string ElectricBoatEngine::info(Fuel& fuel, Wheels& wheels, Gearbox& gearbox) { return ""; }
void ElectricBoatEngine::checkfueltype(Fuel& fuel) 
{
	if (fuel.gettype() != fueltypes[ELECTRIC])
	{
		throw("Incompitable fuel");
	}
}
BoatEngine* ElectricBoatEngine::clone() 
{
	return new ElectricBoatEngine(turbine->clone(), propeller->clone());
}