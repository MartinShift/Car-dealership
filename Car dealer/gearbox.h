#pragma once
class Gearbox
{
private:
	int maxgears;
	int current;
public:
	Gearbox(int max);
	void up();
	void down();
	double getmultiplier();
	int getcurrent();
	int getmax();
	void set(int gear);
	Gearbox* clone();
};