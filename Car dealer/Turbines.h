#include "Shift.h"
enum turbinetypes {
	STANDART,TURBO,DUAL,BOOST
};
const std::string turbines[]{"Standard","Turbo","Dual","Boost"};
class Turbine  {
public:
	virtual std::string getinfo() = 0;
	virtual double getRoadSpeedMultiplier() = 0;
	virtual double getOffRoadSpeedMultiplier() = 0;
	virtual Turbine* clone() = 0;
};
class StandardTurbine : public Turbine {
public:
	std::string getinfo() override;
	double getRoadSpeedMultiplier() override;
	double getOffRoadSpeedMultiplier() override;
	Turbine* clone() override;
};
class TurboTurbine : public Turbine {
public:
	std::string getinfo() override;
	double getRoadSpeedMultiplier() override;
	double getOffRoadSpeedMultiplier() override;
	Turbine* clone() override;
};
class DualTurbine : public Turbine {
public:
	std::string getinfo() override;
	double getRoadSpeedMultiplier() override;
	double getOffRoadSpeedMultiplier() override;
	Turbine* clone() override;
};
class BoostTurbine : public Turbine {
public:
	std::string getinfo() override;
	double getRoadSpeedMultiplier() override;
	double getOffRoadSpeedMultiplier() override;
	Turbine* clone() override;
};
