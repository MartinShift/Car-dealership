#include "Fuel.h"
Fuel::Fuel(double volume) {
	this->volume = volume;
	this->maxvolume = volume;
}
std::string Fuel::info() {
	return("Fuel type: " + gettype());
}
std::string Fuel::Volumeinfo()
{
	return "Current volume: " + std::to_string(volume);
}
std::string Fuel::MaxVolumeinfo()
{
	return "Max volume: " + std::to_string(maxvolume);
}
double Fuel::getVolume() {
	return volume;
}
double Fuel::getMaxVolume()
{
	return maxvolume;
}
void Fuel::use(Gearbox* gearbox) {
	if (this->volume - getConsumptionRate()*gearbox->getmultiplier() < 0) {
		throw "FUEL RAN OUT";
	}
	this->volume -= getConsumptionRate()*gearbox->getmultiplier();
}

Gasoline92::Gasoline92(double volume) : Fuel(volume) {}
std::string Gasoline92::gettype() 
{
	return fueltypes[GASOLINE92];
}
double Gasoline92::getConsumptionRate() 
{
	return 0.2;
}
int Gasoline92::getRoadSpeed() 
{
	return fuelspeeds[GASOLINE92].first;
}
int Gasoline92::getOffRoadSpeed() 
{
	return fuelspeeds[GASOLINE92].second;
}
Fuel* Gasoline92::clone() 
{
	return new Gasoline92(maxvolume);
}
Gasoline95::Gasoline95(double volume) : Fuel(volume) {}
std::string Gasoline95::gettype()
{
	return fueltypes[GASOLINE95];
}
double Gasoline95::getConsumptionRate()
{
	return 0.23;
}
int Gasoline95::getRoadSpeed()
{
	return fuelspeeds[GASOLINE95].first;
}
int Gasoline95::getOffRoadSpeed()
{
	return fuelspeeds[GASOLINE95].second;
}
Fuel* Gasoline95::clone()
{
	return new Gasoline95(maxvolume);
}

Gasoline98::Gasoline98(double volume) : Fuel(volume) {};
std::string Gasoline98::gettype() 
{
	return fueltypes[GASOLINE98];
}
double Gasoline98::getConsumptionRate() 
{
	return 0.26;
}
int Gasoline98::getRoadSpeed() 
{
	return fuelspeeds[GASOLINE98].first;
}
int Gasoline98::getOffRoadSpeed() 
{
	return fuelspeeds[GASOLINE98].second;
}
Fuel* Gasoline98::clone() 
{
	return new Gasoline98(maxvolume);
}

Gasoline100::Gasoline100(double volume) : Fuel(volume) {}
	std::string Gasoline100::gettype() 
	{
		return fueltypes[GASOLINE100];
	}
	double Gasoline100::getConsumptionRate() 
	{
		return 0.31;
	}
	int Gasoline100::getRoadSpeed() 
	{
		return fuelspeeds[GASOLINE100].first;
	}
	int Gasoline100::getOffRoadSpeed()
	{
		return fuelspeeds[GASOLINE100].second;
	}
	Fuel* Gasoline100::clone()
	{
		return new Gasoline100(maxvolume);
	}

	Gas::Gas(double volume) : Fuel(volume) {}
	std::string Gas::gettype() 
	{
		return fueltypes[GAS];
	}
	double Gas::getConsumptionRate() 
	{
		return 0.15;
	}
	int Gas::getRoadSpeed() 
	{
		return fuelspeeds[GAS].first;
	}
	int Gas::getOffRoadSpeed() 
	{
		return fuelspeeds[GAS].second;
	}
	Fuel* Gas::clone() 
	{
		return new Gas(maxvolume);
	}

	Diesel::Diesel(double volume) : Fuel(volume) {}
	std::string Diesel::gettype() 
	{
		return fueltypes[DIESEL];
	}
	double Diesel::getConsumptionRate()
	{
		return 0.18;
	}
	int Diesel::getRoadSpeed()
	{
		return fuelspeeds[DIESEL].first;
	}
	int Diesel::getOffRoadSpeed() 
	{
		return fuelspeeds[DIESEL].second;
	}
	Fuel* Diesel::clone() 
	{
		return new Diesel(maxvolume);
	}

	Electric::Electric(double volume) : Fuel(volume) {}
	std::string Electric::gettype() 
	{
		return fueltypes[ELECTRIC];
	}
	double Electric::getConsumptionRate() 
	{
		return 0.28;
	}
	int Electric::getRoadSpeed() 
	{
		return fuelspeeds[ELECTRIC].first;
	}
	int Electric::getOffRoadSpeed() 
	{
		return fuelspeeds[ELECTRIC].second;
	}
	Fuel* Electric::clone()
	{
		return new Electric(maxvolume);
	}