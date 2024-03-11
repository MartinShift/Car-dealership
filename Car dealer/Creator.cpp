#include "Creator.h"
Selector::Selector() {}
Car* Selector::selectcar()
{
	system("cls");
	CarBuilder* builder = nullptr;
	switch (mainmenu({ "Standard car","FAST car","Offroad car","Drift car","Armed car"}, "Select car type"))
	{
	case 0:
		builder = new Gasoline92CarStandardBuilder;
		break;
	case 1:
		builder = new FastDeluxeRaceCarBuilder;
		break;
	case 2:
		builder = new OffRoadDieselCarBuilder;
		break;
	case 3:
		builder = new TokyoDriftCarBuilder;
	case 4:
		builder = new ArmedForceCarBuilder;
	}
	return builder->start();
}
Motorbike* Selector::selectbike()
{
	system("cls");
	MotorbikeBuilder* builder = nullptr;
	switch (mainmenu({ "Standard Motorbike","Nice Motorbike","Electro Motorbike" }, "Select motorbike type"))
	{
	case 0:
		builder = new StandardMotorBikeBuilder;
		break;
	case 1:
		builder = new NiceMotorBikeBuilder;
		break;
	case 2:
		builder = new ElectroBikeBuilder;
	}
	return builder->start();
}
Boat* Selector::selectboat()
{
	system("cls");
	BoatBuilder* builder = nullptr;
	switch (mainmenu({ "Standard boat","Ultra fast boat","Electro boat","Dual armed boat"}, "Select boat type"))
	{
	case 0:
		builder = new StandardMotorboatbuilder;
		break;
	case 1:
		builder = new UltraFastMotorboatbuilder;
		break;
	case 2:
		builder = new BigElectricBoatBuilder;
		break;
	case 3:
		builder = new DualArmedShipBuilder;
		break;
	}
	return builder->start();
}
Vehicle* Selector::run()
{
	switch (mainmenu({ "Car","Motorbike","Boat" }, "Select vehicle"))
	{
	case 0:
		return selectcar();
	case 1:
		return selectbike();
	case 2:
		return selectboat();
	}

}
AirConditioner* VehicleCreator::selectConditioner()
{
	switch (mainmenu({ "No conditioner","Vintage air conditioner","Two zone climate control" }, "Select air conditioner"))
	{
	case 0:
		return nullptr;
	case 1:
		return new VintageAirConditioner;
	case 2:
		return new TwoZoneClimateControl;
	}
}
Audio* VehicleCreator::selectAudio()
{
	switch (mainmenu({ "No audio","Realtek R audio","HiFi audio system" }, "Select audio"))
	{
	case 0:
		return nullptr;
	case 1:
		return new Realtek_R_Audio;
	case 2:
		return new HiFiAudioSystem;
	}
}
Fuel* VehicleCreator::selectFuel()
{
	int volume = stoi(inputbox(YELLOW, "Enter total volume(in L): "));
	switch (mainmenu({ "Gasoline 92","Gasoline 95","Gasoline 98","Gasoline 100","Gas","Diesel","Electric" }, "Select fuel"))
	{
	case 0:
		return new Gasoline92(volume);
	case 1:
		return new Gasoline95(volume);
	case 2:
		return new Gasoline98(volume);
	case 3:
		return new Gasoline100(volume);
	case 4:
		return new Gas(volume);
	case 5:
		return new Diesel(volume);
	case 6:
		return new Electric(volume);
	}
}
Turbine* VehicleCreator::selectTurbine()
{
	switch (mainmenu({ "Standard turbine","Turbo turbine","Dual turbine","Boost turbine" }, "Select turbine"))
	{
	case 0:
		return new StandardTurbine;
	case 1:
		return new TurboTurbine;
	case 2:
		return new DualTurbine;
	case 3:
		return new BoostTurbine;
	}
}
std::string VehicleCreator::Entermodel()
{
	return inputbox(BLUE, "Enter model name: ");
}
Gearbox* VehicleCreator::selectGearBox()
{
	return new Gearbox(stoi(inputbox(BLUE_FADE, "Enter amount of gears: ")));
}
int VehicleCreator::enterpassengers()
{
	return stoi(inputbox(GREEN_FADE, "Enter max amount of passengers: "));
}
std::vector<Weapon*> VehicleCreator::createweapons()
{
	std::vector<Weapon*> weapons;
	int times = stoi(inputbox(BLUE_FADE, "Enter amount of weapons: "));
	for (int i{}; i < times; i++)
	{
		weapons.push_back(selectWeapon());
	}
	return weapons;
}
Weapon* VehicleCreator::selectWeapon()
{
	switch (mainmenu({ "No weapon","Minigun","Artillery","Flamethrower","M777Howitzer(adapted)","Neon cat launcher","Multi weapon"}, "Select weapon"))
	{
	case 0:
		return nullptr;
	case 1:
		return new Minigun;
	case 2:
		return new Artillery;
	case 3:
		return new Flamethrower;
	case 4:
		return new M777HowitzerWeaponAdapter;
	case 5:
		return new NeonCatLauncher;
	case 6:
		return new MultiWeapon(createweapons());
	}
}
Engine* CarCreator::selectEngine()
{
	Turbine* turbine = selectTurbine();
	switch (mainmenu({ "Gasoline 92/95","Gasoline 95/98","Gasoline 98/100","Gas","Diesel","Electric" }, "Select engine fuel type"))
	{
	case 0:
		return new Gasoline92_95Engine(turbine);
	case 1:
		return new Gasoline95_98Engine(turbine);
	case 2:
		return new Gasoline98_100Engine(turbine);
	case 3:
		return new GasEngine(turbine);
	case 4:
		return new DieselEngine(turbine);
	case 5:
		return new ElectricEngine(turbine);
	}
}
Wheels* CarCreator::selectWheels()
{
	switch (mainmenu({ "Standard wheels","Track wheels","Offroad wheels","Drift wheels" }, "Select engine fuel type"))
	{
	case 0:
		return new StandardWheels;
	case 1:
		return new TrackWheels;
	case 2:
		return new OffRoadWheels;
	case 3:
		return new DriftWheels;
	}
}
Vehicle* CarCreator::createVehicle()
{
	return new Car(selectEngine(), selectWheels(), selectFuel(), selectGearBox(), Entermodel(), enterpassengers(), selectAudio(), selectConditioner(),selectWeapon());
}

Vehicle* MotorBikeCreator::createVehicle()
{
	return dynamic_cast<Motorbike*>(CarCreator::createVehicle());
}

Propeller* BoatCreator::selectPropeller()
{
	switch (mainmenu({ "Standard propeller","Carbon propeller","RTX 4090" }, "Select propeller"))
	{
	case 0:
		return new StandardPropeller;
	case 1:
		return new CarbonPropeller;
	case 2:
		return new RTX4090;
	}
}
BoatEngine* BoatCreator::selectEngine()
{
	Propeller* propeller = selectPropeller();
	Turbine* turbine = selectTurbine();
	switch (mainmenu({ "Gasoline all","Gas","Electric" }, "Select boat engine"))
	{
	case 0:
		return new GasolineAllBoatEngine(turbine, propeller);
	case 1:
		return new GasBoatEngine(turbine, propeller);
	case 2:
		return new ElectricBoatEngine(turbine, propeller);
	}
}
Vehicle* BoatCreator::createVehicle()
{
	return new Boat(selectEngine(), selectFuel(), selectGearBox(), Entermodel(), enterpassengers(), selectAudio(), selectConditioner(),selectWeapon());
}