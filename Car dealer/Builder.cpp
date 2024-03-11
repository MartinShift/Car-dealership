#include "Builder.h"

CarBuilder::CarBuilder() {}
Car* CarBuilder::start()
{
	vehicle = new Car;
	makeRequired();
	makeOptions();
	return getResult();
}
Car* CarBuilder::getResult() {
	return vehicle;
}
MotorbikeBuilder::MotorbikeBuilder() {}
Motorbike* MotorbikeBuilder::start()
{
	vehicle = new Motorbike;
	makeRequired();
	makeOptions();
	return getResult();
}
Motorbike* MotorbikeBuilder::getResult() {
	return vehicle;
}
BoatBuilder::BoatBuilder() {}
Boat* BoatBuilder::start()
{
	vehicle = new Boat;
	makeRequired();
	makeOptions();
	return getResult();
}
Boat* BoatBuilder::getResult() {
	return vehicle;
}

Gasoline92CarStandardBuilder::Gasoline92CarStandardBuilder() : CarBuilder() {}

CarBuilder* Gasoline92CarStandardBuilder::makeRequired() {
	vehicle->setModel("Standard");
	vehicle->setEngine(new Gasoline92_95Engine(new StandardTurbine));
	vehicle->setFuel(new Gasoline92(3.2));
	vehicle->setWheels(new StandardWheels());
	vehicle->setGearbox(new Gearbox(6));
	vehicle->setPassengers(5);
	return this;
}

CarBuilder* Gasoline92CarStandardBuilder::makeOptions()  {
	vehicle->setAirConditioner(nullptr);
	vehicle->setAudio(nullptr);
	return this;
}

FastDeluxeRaceCarBuilder::FastDeluxeRaceCarBuilder() : CarBuilder() {}

CarBuilder* FastDeluxeRaceCarBuilder::makeRequired()  {
	vehicle->setModel("Ultra mega fast deluxe race");
	vehicle->setEngine(new Gasoline98_100Engine(new TurboTurbine));
	vehicle->setFuel(new Gasoline100(10.5));
	vehicle->setWheels(new TrackWheels());
	vehicle->setGearbox(new Gearbox(7));
	vehicle->setPassengers(3);
	return this;
}

CarBuilder* FastDeluxeRaceCarBuilder::makeOptions() {
	vehicle->setAudio(new HiFiAudioSystem);
	vehicle->setAirConditioner(new TwoZoneClimateControl);
	return this;
}

OffRoadDieselCarBuilder::OffRoadDieselCarBuilder() : CarBuilder() {}

CarBuilder* OffRoadDieselCarBuilder::makeRequired() {
	vehicle->setModel("Range rover");
	vehicle->setEngine(new DieselEngine(new BoostTurbine));
	vehicle->setFuel(new Diesel(6.6));
	vehicle->setWheels(new OffRoadWheels());
	vehicle->setGearbox(new Gearbox(5));
	vehicle->setPassengers(7);
	return this;
}
CarBuilder* OffRoadDieselCarBuilder::makeOptions() {
	vehicle->setAirConditioner(new TwoZoneClimateControl);
	vehicle->setAudio(new Realtek_R_Audio);
	return this;
}

TokyoDriftCarBuilder::TokyoDriftCarBuilder() : CarBuilder() {}

CarBuilder* TokyoDriftCarBuilder::makeRequired() {
	vehicle->setModel("Tokyo drift");
	vehicle->setEngine(new Gasoline95_98Engine(new DualTurbine));
	vehicle->setFuel(new Gasoline95(5.2));
	vehicle->setWheels(new DriftWheels());
	vehicle->setGearbox(new Gearbox(4));
	vehicle->setPassengers(5);
	return this;
}
CarBuilder* TokyoDriftCarBuilder::makeOptions() {
	vehicle->setAirConditioner(new TwoZoneClimateControl);
	vehicle->setAudio(new Realtek_R_Audio);
	return this;
}
ArmedForceCarBuilder::ArmedForceCarBuilder() : CarBuilder() {}

CarBuilder* ArmedForceCarBuilder::makeRequired() {
	vehicle->setModel("Armed car");
	vehicle->setEngine(new DieselEngine(new BoostTurbine));
	vehicle->setFuel(new Diesel(5.2));
	vehicle->setWheels(new DriftWheels());
	vehicle->setGearbox(new Gearbox(5));
	vehicle->setPassengers(8);
	return this;
}
CarBuilder* ArmedForceCarBuilder::makeOptions() {
	vehicle->setAirConditioner(new TwoZoneClimateControl);
	vehicle->setAudio(new HiFiAudioSystem);
	vehicle->setWeapon(new Artillery);
	return this;
}
StandardMotorBikeBuilder::StandardMotorBikeBuilder() : MotorbikeBuilder() {}

MotorbikeBuilder* StandardMotorBikeBuilder::makeRequired() {
	vehicle->setModel("Standard");
	vehicle->setEngine(new Gasoline92_95Engine(new StandardTurbine));
	vehicle->setFuel(new Gasoline95(3.6));
	vehicle->setWheels(new StandardWheels());
	vehicle->setGearbox(new Gearbox(5));
	vehicle->setPassengers(2);
	return this;
}
MotorbikeBuilder* StandardMotorBikeBuilder::makeOptions() {
	vehicle->setAirConditioner(nullptr);
	vehicle->setAudio(new Realtek_R_Audio);
	return this;
}

NiceMotorBikeBuilder::NiceMotorBikeBuilder() : MotorbikeBuilder() {}

MotorbikeBuilder* NiceMotorBikeBuilder::makeRequired() {
	vehicle->setModel("Luxury");
	vehicle->setEngine(new Gasoline95_98Engine(new DualTurbine));
	vehicle->setFuel(new Gasoline95(3.6));
	vehicle->setWheels(new DriftWheels());
	vehicle->setGearbox(new Gearbox(6));
	vehicle->setPassengers(2);
	return this;
}
MotorbikeBuilder* NiceMotorBikeBuilder::makeOptions() {
	vehicle->setAirConditioner(nullptr);
	vehicle->setAudio(new HiFiAudioSystem);
	return this;
}

ElectroBikeBuilder::ElectroBikeBuilder() : MotorbikeBuilder() {}

MotorbikeBuilder* ElectroBikeBuilder::makeRequired() {
	vehicle->setModel("Tesla bike");
	vehicle->setEngine(new ElectricEngine(new DualTurbine));
	vehicle->setFuel(new Electric(3.6));
	vehicle->setWheels(new TrackWheels());
	vehicle->setGearbox(new Gearbox(8));
	vehicle->setPassengers(2);
	return this;
}
MotorbikeBuilder* ElectroBikeBuilder::makeOptions()  {
	vehicle->setAirConditioner(nullptr);
	vehicle->setAudio(new HiFiAudioSystem);
	return this;
}
StandardMotorboatbuilder::StandardMotorboatbuilder() : BoatBuilder() {}

BoatBuilder* StandardMotorboatbuilder::makeRequired() {
	vehicle->setModel("Mini");
	vehicle->setEngine(new GasolineAllBoatEngine({ new StandardTurbine,new StandardPropeller }));
	vehicle->setFuel(new Gasoline92(4));
	vehicle->setGearbox(new Gearbox(6));
	vehicle->setPassengers(5);
	return this;
}
BoatBuilder* StandardMotorboatbuilder::makeOptions()  {
	vehicle->setAirConditioner(nullptr);
	vehicle->setAudio(new Realtek_R_Audio);
	return this;
}

UltraFastMotorboatbuilder::UltraFastMotorboatbuilder() : BoatBuilder() {}

BoatBuilder* UltraFastMotorboatbuilder::makeRequired() {
	vehicle->setModel("Void breaker");
	vehicle->setEngine(new GasolineAllBoatEngine({ new TurboTurbine,new RTX4090 }));
	vehicle->setFuel(new Gasoline100(8));
	vehicle->setGearbox(new Gearbox(8));
	vehicle->setPassengers(4);
	return this;
}
BoatBuilder* UltraFastMotorboatbuilder::makeOptions() {
	vehicle->setAirConditioner(new TwoZoneClimateControl);
	vehicle->setAudio(new HiFiAudioSystem);
	return this;
}

BigElectricBoatBuilder::BigElectricBoatBuilder() : BoatBuilder() {}

BoatBuilder* BigElectricBoatBuilder::makeRequired()  {
	vehicle->setModel("Yacht");
	vehicle->setEngine(new ElectricBoatEngine({ new DualTurbine,new CarbonPropeller }));
	vehicle->setFuel(new Electric(8));
	vehicle->setGearbox(new Gearbox(6));
	vehicle->setPassengers(15);
	return this;
}
BoatBuilder* BigElectricBoatBuilder::makeOptions()  {
	vehicle->setAirConditioner(new TwoZoneClimateControl);
	vehicle->setAudio(new HiFiAudioSystem);
	return this;
}

DualArmedShipBuilder::DualArmedShipBuilder() : BoatBuilder() {}

BoatBuilder* DualArmedShipBuilder::makeRequired()  {
	vehicle->setModel("Pew meow ship");
	vehicle->setEngine(new GasolineAllBoatEngine({ new DualTurbine,new CarbonPropeller }));
	vehicle->setFuel(new Gasoline98(8));
	vehicle->setGearbox(new Gearbox(8));
	vehicle->setPassengers(10);
	return this;
}
BoatBuilder* DualArmedShipBuilder::makeOptions()  {
	vehicle->setAirConditioner(new TwoZoneClimateControl);
	vehicle->setAudio(new HiFiAudioSystem);
	vehicle->setWeapon(new MultiWeapon({new Minigun,new Minigun}));
	return this;
}