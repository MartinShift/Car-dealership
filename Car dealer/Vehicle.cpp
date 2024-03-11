#include "Vehicle.h"
Vehicle::Vehicle(Fuel* fuel, Gearbox* gearbox, std::string model, int passengers) {
	this->passengers = passengers;
	this->fuel = fuel;
	this->model = model;
	this->gearbox = gearbox;
}
Vehicle::Vehicle(Fuel* fuel, Gearbox* gearbox, std::string model, int passengers, Audio* audio, AirConditioner* conditioner,Weapon*weapon) : Vehicle(fuel, gearbox, model, passengers) {
	this->audio = audio;
	this->airConditioner = conditioner;
	this->weapon = weapon;
}
Vehicle::Vehicle() {}
Gearbox* Vehicle::gear() { return gearbox; }
double Vehicle::volume() { return fuel->getVolume(); }
void Vehicle::setFuel(Fuel* fuel) {
	this->fuel = fuel;
}
void Vehicle::shoot()
{
	Progressbar("Recharging", weapon->rechargetime());
	float lat = stof(inputbox(YELLOW, "Enter latitude: "));
	float lon = stof(inputbox(YELLOW, "Enter longitude: "));
	std::pair<float, float> coords(lat,lon);
	weapon->shoot(coords);
}
Fuel* Vehicle::getfuel() { return fuel; }
void Vehicle::setAirConditioner(AirConditioner* airConditioner) {
	this->airConditioner = airConditioner;
}
void Vehicle::setGearbox(Gearbox* gearbox)
{
	this->gearbox = gearbox;
}
void Vehicle::setAudio(Audio* audio) {
	this->audio = audio;
}
void Vehicle::setPassengers(int passengers)
{
	this->passengers = passengers;
}
void Vehicle::setModel(std::string model)
{
	this->model = model;
}
Vehicle::~Vehicle()
{
	delete fuel;
	delete airConditioner;
	delete gearbox;
	delete audio;
	std::cout << "Destructor\n";
}
std::vector<std::string> Car::getdriveinfo()
{
	std::vector<std::string>driveinfo;
	driveinfo.push_back(fuel->Volumeinfo() + '/' + std::to_string(fuel->getMaxVolume()));
	driveinfo.push_back("Current gear: " + std::to_string(gearbox->getcurrent()) + '/' + std::to_string(gearbox->getmax()));
	return driveinfo;
}
Car::Car() {}
Car::Car(Engine* engine, Wheels* wheels, Fuel* fuel, Gearbox* gearbox, std::string model, int passengers) : Vehicle(fuel, gearbox, model, passengers) {
	this->engine = engine;
	this->wheels = wheels;
}
Car::Car(Engine* engine, Wheels* wheels, Fuel* fuel, Gearbox* gearbox, std::string model, int passengers, Audio* audio, AirConditioner* conditioner,Weapon* weapon) : Vehicle(fuel, gearbox, model, passengers, audio, conditioner,weapon) {
	this->engine = engine;
	this->wheels = wheels;
}
Car::Car(const Car& car)
{
	this->engine = car.engine;
	this->audio = car.audio;
	this->wheels = car.wheels;
	this->passengers = car.passengers;
	this->fuel = car.fuel;
	this->gearbox = car.gearbox;
	this->model = car.model;
}
std::string Car::drive(bool road) {
	double speed = engine->getSpeed(*fuel, *wheels, *gearbox, road);
	fuel->use(gearbox);
	
	if (road ? speed > wheels->getMaxRoadSpeed() : speed > wheels->getMaxOffRoadSpeed()) {
		throw "WHEELS FELL OFF";
	}
	total += speed;
	return("Current speed: " + std::to_string(speed));
}
Gearbox* Car::gear() { return gearbox; }
double Car::volume() { return fuel->getVolume(); }
void Car::info() {
	std::vector<std::string> info;
	info.push_back("Car model: " + model);
	info.push_back(engine->info(*fuel, *wheels, *gearbox));
	info.push_back(engine->maxRoadspeed(*fuel, *wheels));
	info.push_back(engine->maxOffroadspeed(*fuel, *wheels));
	info.push_back(fuel->info());
	info.push_back(fuel->MaxVolumeinfo());
	info.push_back(fuel->Volumeinfo());
	info.push_back(wheels->info());
	info.push_back(wheels->maxRoadSpeed());
	info.push_back(wheels->maxOffRoadSpeed());
	info.push_back("Total distance driven: " + std::to_string(total));
	info.push_back(audio == nullptr ? "No audio system" : audio->info());
	info.push_back(airConditioner == nullptr ? "No Conditioner" : airConditioner->info());

	info.push_back("Max passengers: " + std::to_string(passengers));	
	info.push_back(weapon == nullptr ? "No weapon" : weapon->info());
	WriteNice(info, YELLOW_FADE);
}
std::string Vehicle::getmodel()
{
	return this->model;
}
void Car::setWheels(Wheels* wheels) {
	this->wheels = wheels;
}
Car::~Car()
{
	delete engine;
	delete wheels;
}
void Car::setEngine(Engine* engine) {
	this->engine = engine;
}
void Car::setTurbine(Turbine* turbine)
{
	this->engine->setTurbine(turbine);
}
Vehicle* Car::clone()
{
	return new Car(engine->clone(), wheels->clone(), fuel->clone(), gearbox->clone(), model, passengers, audio == nullptr ? nullptr : audio->clone(), airConditioner == nullptr ? nullptr : airConditioner->clone(),weapon == nullptr ? nullptr : weapon->clone());
}
void Vehicle::setWeapon(Weapon* weapon)
{
	this->weapon = weapon;
}
void Car::testDrive() {
	try {
		std::vector<std::string> speeds;
		for (;; gearbox->up())
		{
			speeds.push_back("Testing on " + std::to_string(gearbox->getcurrent()) + " gear\n");
			speeds.push_back("Road " + drive(true));
			speeds.push_back("Offroad " + drive(false));
			speeds.push_back(fuel->Volumeinfo());
			if (gearbox->getcurrent() == gearbox->getmax()) break;
		}
		speeds.push_back("Test successful!");
		WriteNice(speeds, RED_FADE);
	}
	catch (const char* e) {
		cout << "\nError: " << endl;
		cout << e << endl;
	}
}
Motorbike::Motorbike() {}
Motorbike::Motorbike(Engine* engine, Wheels* wheels, Fuel* fuel, Gearbox* gearbox, std::string model, int passengers) : Car(engine, wheels, fuel, gearbox, model, passengers) {}
Motorbike::Motorbike(Engine* engine, Wheels* wheels, Fuel* fuel, Gearbox* gearbox, std::string model, int passengers, Audio* audio, AirConditioner* conditioner,Weapon* weapon) : Car(engine, wheels, fuel, gearbox, model, passengers, audio, conditioner,weapon) {}
void Motorbike::info() {
	std::vector<std::string> info;
	info.push_back("Motorbike model: " + model);
	info.push_back(engine->info(*fuel, *wheels, *gearbox));
	info.push_back(engine->maxRoadspeed(*fuel, *wheels));
	info.push_back(engine->maxOffroadspeed(*fuel, *wheels));
	info.push_back(fuel->info());
	info.push_back(fuel->MaxVolumeinfo());
	info.push_back(fuel->Volumeinfo());
	info.push_back(wheels->info());
	info.push_back(wheels->maxRoadSpeed());
	info.push_back(wheels->maxOffRoadSpeed());
	info.push_back(audio == nullptr ? "No audio system" : audio->info());
	info.push_back(airConditioner == nullptr ? "No Conditioner" : airConditioner->info());
	info.push_back("Max passengers: " + std::to_string(passengers));
	WriteNice(info, YELLOW_FADE);
}
Vehicle* Motorbike::clone()
{
	return new Motorbike(engine->clone(), wheels->clone(), fuel->clone(), gearbox->clone(), model, passengers, audio == nullptr ? nullptr : audio->clone(), airConditioner == nullptr ? nullptr : airConditioner->clone(),weapon == nullptr ? nullptr : weapon->clone());
}
Boat::Boat(BoatEngine* engine, Fuel* fuel, Gearbox* gearbox, std::string model, int passengers) : Vehicle(fuel, gearbox, model, passengers) {}
Boat::Boat(BoatEngine* engine, Fuel* fuel, Gearbox* gearbox, std::string model, int passengers, Audio* audio, AirConditioner* conditioner,Weapon* weapon) : Vehicle(fuel, gearbox, model, passengers, audio, conditioner,weapon) { this->engine = engine; }
Boat::Boat() {}
std::string Boat::drive() { return drive(true); }
std::string Boat::drive(bool road) {
	double speed = engine->getSpeed(*fuel, *gearbox);
	fuel->use(gearbox);
	total += speed;
	return "Current speed: " + std::to_string(speed);
}
void Boat::info()
{
	std::vector<std::string> info;
	info.push_back("Car model: " + model);
	info.push_back(engine->info(*fuel, *gearbox));
	info.push_back(engine->getmaxspeed(*fuel,*gearbox));
	info.push_back(engine->getpropeller()->getinfo());
	info.push_back(fuel->info());
	info.push_back(fuel->MaxVolumeinfo());
	info.push_back(fuel->Volumeinfo());
	info.push_back("Total distance driven: " + std::to_string(total));
	info.push_back(audio == nullptr ? "No audio system" : audio->info());
	info.push_back(airConditioner == nullptr ? "No Conditioner" : airConditioner->info());
	
	info.push_back("Max passengers: " + std::to_string(passengers));
	info.push_back(weapon == nullptr ? "No weapon" : weapon->info());
	WriteNice(info, BLUE);
}
void Boat::setEngine(BoatEngine* engine) {
	this->engine = engine;
}
Boat::~Boat()
{
	delete engine;
}
Vehicle* Boat::clone()
{
	return new Boat(engine->clone(), fuel->clone(), gearbox->clone(), model, passengers, audio == nullptr ? nullptr : audio->clone(), airConditioner == nullptr ? nullptr : airConditioner->clone(), weapon == nullptr ? nullptr : weapon->clone());
}
void Boat::testDrive() {
	try {
		std::vector<std::string> speeds;
		for (;; gearbox->up())
		{
			speeds.push_back("Testing on " + std::to_string(gearbox->getcurrent()) + " gear\n");
			speeds.push_back(drive());
			speeds.push_back(fuel->Volumeinfo());
			if (gearbox->getcurrent() == gearbox->getmax()) break;
		}
		speeds.push_back("Test successful!");
		WriteNice(speeds, RED_FADE);
	}
	catch (const char* e) {
		cout << "\nError: " << endl;
		cout << e << endl;
	}
}
std::vector<std::string> Boat::getdriveinfo()
{
	std::vector<std::string>driveinfo;
	driveinfo.push_back(fuel->Volumeinfo() + '/' + std::to_string(fuel->getMaxVolume()));
	driveinfo.push_back("Current gear: " + std::to_string(gearbox->getcurrent()) + '/' + std::to_string(gearbox->getmax()));
	return driveinfo;
}