#pragma once
#include "Vehicle.h"
class CarBuilder {
protected:
	Car* vehicle;
public:
	CarBuilder();
	Car* start();
	Car* getResult();
	virtual CarBuilder* makeRequired() = 0;

	virtual CarBuilder* makeOptions() = 0;

	
};
class MotorbikeBuilder
{
protected:
	Motorbike* vehicle;
public:
	MotorbikeBuilder();
	Motorbike* start();
	Motorbike* getResult();
	virtual MotorbikeBuilder* makeRequired() = 0;

	virtual MotorbikeBuilder* makeOptions() = 0;

	
};
class BoatBuilder
{
protected:
	Boat* vehicle;
public:
	BoatBuilder();
	Boat* start();
	Boat* getResult();
	virtual BoatBuilder* makeRequired() = 0;

	virtual BoatBuilder* makeOptions() = 0;

	
};

class Gasoline92CarStandardBuilder : public CarBuilder {
public:
	Gasoline92CarStandardBuilder();

	CarBuilder* makeRequired() override;

	CarBuilder* makeOptions() override;
};
class FastDeluxeRaceCarBuilder : public CarBuilder {
public:
	FastDeluxeRaceCarBuilder();

	CarBuilder* makeRequired() override;

	CarBuilder* makeOptions() override;
};
class OffRoadDieselCarBuilder : public CarBuilder
{
public:
	OffRoadDieselCarBuilder();

	CarBuilder* makeRequired() override;
	CarBuilder* makeOptions() override;
};
class TokyoDriftCarBuilder : public CarBuilder
{
public:
	TokyoDriftCarBuilder();

	CarBuilder* makeRequired() override;
	CarBuilder* makeOptions() override;
};
class ArmedForceCarBuilder : public CarBuilder {
	public:
	ArmedForceCarBuilder();

	CarBuilder* makeRequired() override;
	CarBuilder* makeOptions() override;
};

class StandardMotorBikeBuilder : public MotorbikeBuilder {
public:
	StandardMotorBikeBuilder();

	MotorbikeBuilder* makeRequired() override;
	MotorbikeBuilder* makeOptions() override;
};
class NiceMotorBikeBuilder : public MotorbikeBuilder {
public:
	NiceMotorBikeBuilder();

	MotorbikeBuilder* makeRequired() override;
	MotorbikeBuilder* makeOptions() override;
}; 
class ElectroBikeBuilder : public MotorbikeBuilder {
public:
	ElectroBikeBuilder();

	MotorbikeBuilder* makeRequired() override;
	MotorbikeBuilder* makeOptions() override;
};

class StandardMotorboatbuilder : public BoatBuilder
{
public:
	StandardMotorboatbuilder();

	BoatBuilder* makeRequired() override;
	BoatBuilder* makeOptions() override;
};
class UltraFastMotorboatbuilder : public BoatBuilder
{
public:
	UltraFastMotorboatbuilder();

	BoatBuilder* makeRequired() override;
	BoatBuilder* makeOptions() override;
};
class BigElectricBoatBuilder : public BoatBuilder
{
public:
	BigElectricBoatBuilder();

	BoatBuilder* makeRequired() override;
	BoatBuilder* makeOptions() override;
};
class DualArmedShipBuilder : public BoatBuilder
{
public:
	DualArmedShipBuilder();

	BoatBuilder* makeRequired() override;
	BoatBuilder* makeOptions() override;

};

