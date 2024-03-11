#pragma once
#include <iostream>
#include <string>
enum WheelTypes
{
	STANDARD, TRACK, OFFROAD, DRIFT
};
const std::string wheeltypes[]{ "standard","track","offroad","drift" };
class Wheels {
public:
	std::string info();
	virtual int getMaxRoadSpeed() = 0;
	virtual int getMaxOffRoadSpeed() = 0;
	virtual std::string gettype() = 0;
	virtual double getRoadSpeedMultiplier() = 0;
	virtual double getOffRoadSpeedMultiplier() = 0;
	virtual Wheels* clone() = 0;
	std::string maxRoadSpeed();
	std::string maxOffRoadSpeed();
};
class StandardWheels : public Wheels
{
	int getMaxRoadSpeed() override;
	int getMaxOffRoadSpeed() override;
	double getRoadSpeedMultiplier() override;
	double getOffRoadSpeedMultiplier() override;
	std::string gettype() override;
	Wheels* clone() override;
};
class TrackWheels : public Wheels
{
	int getMaxRoadSpeed() override;
	int getMaxOffRoadSpeed() override;
	double getRoadSpeedMultiplier() override;
	double getOffRoadSpeedMultiplier() override;
	std::string gettype() override;
	Wheels* clone() override;
};
class OffRoadWheels : public Wheels
{
	int getMaxRoadSpeed() override;
	int getMaxOffRoadSpeed() override;
	double getRoadSpeedMultiplier() override;
	double getOffRoadSpeedMultiplier() override;
	std::string gettype() override;
	Wheels* clone() override;
};
class DriftWheels : public Wheels
{
	int getMaxRoadSpeed() override;
	int getMaxOffRoadSpeed() override;
	double getRoadSpeedMultiplier() override;
	double getOffRoadSpeedMultiplier() override;
	std::string gettype() override;
	Wheels* clone() override;
};
