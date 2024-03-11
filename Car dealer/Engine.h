#pragma once
#include "Wheels.h"
#include "Fuel.h"
#include "Turbines.h"
#include "gearbox.h"
#include "Shift.h"
#include "Other.h"
enum Engines
{
	benzin92_95, benzin95_98,benzin98_100, diesel, gas,electric
};
const std::string enginefuels[]{ "gasoline92/95","gasoline95/98","gasoline98/100","diesel","Gas","Electric" };
class Engine {
protected:
	Turbine* turbine = nullptr;
public:
	Engine(Turbine* turbine);
	Engine(Engine* engine);
	Engine();
	virtual std::string info(Fuel& fuel, Wheels& wheels, Gearbox&gearbox) = 0;
	std::string maxRoadspeed(Fuel& fuel, Wheels& wheels);
	std::string maxOffroadspeed(Fuel& fuel, Wheels& wheels);
	virtual void checkfueltype(Fuel& fuel) = 0;
	void setTurbine(Turbine* turbine);
	double getSpeed(Fuel& fuel, Wheels& wheels, Gearbox& gearbox, bool road);
	~Engine();
	void operator=(Engine* engine);
	virtual Engine* clone() = 0;
};
class Gasoline92_95Engine : public Engine {
public:
	Gasoline92_95Engine(Turbine* turbine);
	std::string info(Fuel& fuel, Wheels& wheels, Gearbox& gearbox) override;
	void checkfueltype(Fuel& fuel) override;
	Engine* clone() override;
};
class Gasoline95_98Engine : public Engine {
public:
	Gasoline95_98Engine(Turbine* turbine);
	std::string info(Fuel& fuel, Wheels& wheels, Gearbox& gearbox) override;
	void checkfueltype(Fuel& fuel) override;
	Engine* clone() override;
};
class Gasoline98_100Engine : public Engine {
public:
	Gasoline98_100Engine(Turbine* turbine);
	std::string info(Fuel& fuel, Wheels& wheels, Gearbox& gearbox) override;
	void checkfueltype(Fuel& fuel) override;
	Engine* clone() override;
};
class GasEngine : public Engine {
public:
	std::string info(Fuel& fuel, Wheels& wheels, Gearbox& gearbox) override;
	GasEngine(Turbine* turbine);
	void checkfueltype(Fuel& fuel) override;
	Engine* clone() override;
};
class DieselEngine : public Engine {
public:
	DieselEngine(Turbine* turbine);
	std::string info(Fuel& fuel, Wheels& wheels, Gearbox& gearbox) override;
	void checkfueltype(Fuel& fuel) override;
	Engine* clone() override;
};
class ElectricEngine : public Engine {
public:
	ElectricEngine(Turbine* turbine);
	std::string info(Fuel& fuel, Wheels& wheels, Gearbox& gearbox) override;
	void checkfueltype(Fuel& fuel) override;
	Engine* clone() override;
};

class BoatEngine : public Engine
{
protected:
	Propeller* propeller = nullptr;
public:
	BoatEngine(Turbine* turbine, Propeller* propeller);
	BoatEngine(BoatEngine* engine);
	double getSpeed(Fuel& fuel, Gearbox& gearbox);
	~BoatEngine();
	virtual std::string info(Fuel& fuel, Gearbox& gearbox) = 0;
	virtual BoatEngine* clone() = 0;
	std::string getmaxspeed(Fuel& fuel, Gearbox& gearbox);
	Propeller* getpropeller();
};
class GasolineAllBoatEngine : public BoatEngine
{
public:
	GasolineAllBoatEngine(Turbine* turbine, Propeller* propeller);
	std::string info(Fuel& fuel, Gearbox& gearbox) override;
	std::string info(Fuel& fuel, Wheels& wheels, Gearbox& gearbox) override;
	BoatEngine* clone() override;
	void checkfueltype(Fuel& fuel) override;
};
class GasBoatEngine : public BoatEngine
{
public:
	GasBoatEngine(Turbine* turbine, Propeller* propeller);
	std::string info(Fuel& fuel, Gearbox& gearbox) override;
	std::string info(Fuel& fuel, Wheels& wheels, Gearbox& gearbox) override;
	BoatEngine* clone() override;
	void checkfueltype(Fuel& fuel) override;
};
class ElectricBoatEngine : public BoatEngine
{
public:
	ElectricBoatEngine(Turbine* turbine, Propeller* propeller);
	std::string info(Fuel& fuel, Gearbox& gearbox) override;
	std::string info(Fuel& fuel, Wheels& wheels, Gearbox& gearbox) override;
	void checkfueltype(Fuel& fuel) override;
	BoatEngine* clone() override;
};
