#pragma once
#include "Builder.h"
class Selector
{
public:
	Selector();
	Car* selectcar();
	Motorbike* selectbike();
	Boat* selectboat();
	Vehicle* run();
};
class CarCreator;
class MotorbikeCreator;
class BoatCreator;
class VehicleCreator
{
public:
	AirConditioner* selectConditioner();
	Audio* selectAudio();
	Fuel* selectFuel();
	Turbine* selectTurbine();
	std::string Entermodel();
	Gearbox* selectGearBox();
	Weapon* selectWeapon();
	int enterpassengers();
	std::vector<Weapon*> createweapons();
	virtual Vehicle* createVehicle() = 0;
};
class CarCreator : public VehicleCreator
{
public:
	Engine* selectEngine();
	Wheels* selectWheels();
	Vehicle* createVehicle() override;
};
class MotorBikeCreator : public CarCreator
{
	Vehicle* createVehicle() override;
};
class BoatCreator : public VehicleCreator
{
	Propeller* selectPropeller();
	BoatEngine* selectEngine();
	Vehicle* createVehicle() override;
};
