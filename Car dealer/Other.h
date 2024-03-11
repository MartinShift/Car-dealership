#pragma once
#include "Shift.h"
class Audio {
public:
	virtual std::string info() = 0;
	virtual Audio* clone() = 0;
};
class Realtek_R_Audio : public Audio
{
public:
	Realtek_R_Audio();

	std::string info() override;
	Audio* clone() override;
};
class HiFiAudioSystem : public Audio {
public:
	HiFiAudioSystem();

	std::string info() override;
	Audio* clone() override;
};

class AirConditioner {
public:
	virtual std::string info() = 0;
	virtual AirConditioner* clone() = 0;
};
class VintageAirConditioner : public AirConditioner
{
public:
	VintageAirConditioner();

	std::string info() override;
	AirConditioner* clone() override;
};
class TwoZoneClimateControl : public AirConditioner {
public:
	TwoZoneClimateControl();

	std::string info() override;
	AirConditioner* clone() override;
};

class Propeller
{
public:
	virtual std::string getinfo() = 0;
	virtual double getAccelerator() = 0;
	virtual Propeller* clone() = 0;
};
class StandardPropeller : public Propeller
{
	std::string getinfo() override;
	double getAccelerator() override;
	Propeller* clone() override;
};
class CarbonPropeller : public Propeller
{
	std::string getinfo() override;
	double getAccelerator() override;
	Propeller* clone() override;
};
class RTX4090 : public Propeller
{
	std::string getinfo() override;
	double getAccelerator() override;
	Propeller* clone() override;
};

class Weapon
{
protected:
	float lat = 0;
	float lng = 0;
	bool loaded = 0;
public:
	virtual void shoot(std::pair<float, float>coords) = 0;
	virtual std::string info() = 0;
	virtual Weapon* clone() = 0;
	virtual int rechargetime() = 0;
	virtual void fire() = 0;
	void setTarget(float lat, float lng);
	void loadAmmo();

};
class Minigun : public Weapon
{

public:
	void shoot(std::pair<float, float>coords) override;
	std::string info() override;
	Weapon* clone() override;
	int rechargetime() override;
	void fire() override;
};
class Artillery : public Weapon
{
public:
	void shoot(std::pair<float, float>coords) override;
	std::string info() override;
	Weapon* clone() override;
	int rechargetime() override;
	void fire() override;
};
class Flamethrower : public Weapon
{
public:
	void shoot(std::pair<float, float>coords) override;
	std::string info() override;
	Weapon* clone() override;
	int rechargetime() override;
	void fire() override;
};
class M777Howitzer {
	bool loaded = false;
	float lat = 0;
	float lng = 0;
public:
	void setTarget(float lat, float lng) {
		this->lat = lat;
		this->lng = lng;
	}
	void loadAmmo() {
		loaded = true;
	}

	void fire() {
		if (!loaded) {
			throw "Not loaded";
		}
		if (lat == 0 || lng == 0) {
			throw "Invalid target";
		}
		std::cout << "Target destroyed" << std::endl;
		loaded = false;
		lat = 0;
		lng = 0;
	}
};
class M777HowitzerWeaponAdapter : public Weapon {
private:
	M777Howitzer* howitzer;
public:
	M777HowitzerWeaponAdapter();
	void shoot(std::pair<float, float> coords) override;
	~M777HowitzerWeaponAdapter();
	std::string info() override;
	int rechargetime() override;
	M777HowitzerWeaponAdapter* clone() override;
	void fire() override;
};
class NeonCatLauncher : public Weapon
{
public:
	std::string info() override;
	virtual int rechargetime() override;
	void shoot(std::pair<float, float> coords) override;
	Weapon* clone() override;
	void fire() override;
};
class MultiWeapon : public Weapon
{
protected:
	std::vector<Weapon*> weapons;
public:
	MultiWeapon(std::vector<Weapon*>weapons);
	int rechargetime() override;
	std::string info() override;
	virtual Weapon* clone();
	void shoot(std::pair<float, float> coords) override;
	~MultiWeapon();
	void fire() override;
};