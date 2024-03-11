#pragma once
#include <iostream>
#include <string>
#include "gearbox.h"
enum FuelTypes
{
	GASOLINE92, GASOLINE95, GASOLINE98,GASOLINE100, GAS, DIESEL, ELECTRIC
};
const std::string fueltypes[]{"gasoline92","gasoline95","gasoline98","gasoline100","gas","diesel","electric" };
const std::pair<int, int> fuelspeeds[]{ {170, 110}, {180,110},{200,120},{220,110},{170,95},{195,140},{195,100} };
class Fuel {
protected:
	double volume;
	double maxvolume;
public:
	Fuel(double volume);
	std::string info();
	std::string Volumeinfo();
	std::string MaxVolumeinfo();
	virtual std::string gettype() = 0;
	virtual int getRoadSpeed() = 0;
	virtual int getOffRoadSpeed() = 0;
	virtual double getConsumptionRate() = 0;
	virtual Fuel* clone() = 0;
	double getVolume();
	double getMaxVolume();
	void use(Gearbox* gearbox);
};
class Gasoline92 : public Fuel {
public:
	Gasoline92(double volume);
	std::string gettype() override;
	double getConsumptionRate() override;
	int getRoadSpeed() override;
	int getOffRoadSpeed() override;
	Fuel* clone() override;
};
class Gasoline95 : public Fuel {
public:
	Gasoline95(double volume);
	std::string gettype() override;
	double getConsumptionRate() override;
	int getRoadSpeed() override;
	int getOffRoadSpeed() override;
	Fuel* clone() override;
};
class Gasoline98 : public Fuel {
public:
	Gasoline98(double volume);
	std::string gettype() override;
	double getConsumptionRate() override;
	int getRoadSpeed() override;
	int getOffRoadSpeed() override;
	Fuel* clone() override;
};
class Gasoline100 : public Fuel {
public:
	Gasoline100(double volume);
	std::string gettype() override;
	double getConsumptionRate() override;
	int getRoadSpeed() override;
	int getOffRoadSpeed() override;
	Fuel* clone() override;
};
class Gas : public Fuel {
public:
	Gas(double volume);
	std::string gettype() override;
	double getConsumptionRate() override;
	int getRoadSpeed() override;
	int getOffRoadSpeed() override;
	Fuel* clone() override;
};
class Diesel : public Fuel {
public:
	Diesel(double volume);
	std::string gettype() override;
	double getConsumptionRate() override;
	int getRoadSpeed() override;
	int getOffRoadSpeed() override;
	Fuel* clone() override;
};
class Electric : public Fuel {
public:
	Electric(double volume);
	std::string gettype() override;
	double getConsumptionRate() override;
	int getRoadSpeed() override;
	int getOffRoadSpeed() override;
	Fuel* clone() override;
};
