#pragma once
#include"Creator.h"
class VehicleManager
{
protected:
	std::vector<Vehicle*>vehicles;
	bool work = true;
public:
	Vehicle* Select()
	{
		Selector select;
		return select.run();
	}
	Vehicle* Create()
	{
		VehicleCreator* creator = nullptr;
		switch (mainmenu({ "Car","Motorbike","Boat" }, "Select vehicle"))
		{
		case 0:
			creator = new CarCreator;
			break;
		case 1:
			creator = new MotorBikeCreator;
			break;
		case 2:
			creator = new BoatCreator;
			break;
		}
		return creator->createVehicle();
	}
	Vehicle* createtypes()
	{
		switch (mainmenu({ "Create car","Select one of ready cars" }, "Select creation type"))
		{
		case 0:
			return Create();
		case 1:
			return Select();
		}
	}
	std::vector<std::string> getnames()
	{
		std::vector<std::string> names;
		for (auto& i : vehicles)
		{
			names.push_back(i->getmodel());
		}
		return names;
	}
	void shootmode(size_t idx)
	{
		system("cls");
		std::cout << "Shooting mode, press Enter to shoot, ESC to leave\n";
		while (true)
		{
			switch (keymenu())
			{
			case ENTER:
				vehicles[idx]->shoot();
				break;
			case ESC:
				system("cls");
				work = false;
			}
			if (!work) { break; }
		}
	}
	void fuelmenu(size_t idx)
	{
		system("cls");
		switch (mainmenu({ "refill", "change" }, "Fuel menu"))
		{
		case 0:
			vehicles[idx]->setFuel(vehicles[idx]->getfuel()->clone());
			break;
		case 1:
			switch (mainmenu({ "Gasoline 92","Gasoline 95","Gasoline 98","Gasoline 100","Gas","Diesel","Electric" }, "Select fuel"))
			{
			case 0:
				vehicles[idx]->setFuel(new Gasoline92(vehicles[idx]->getfuel()->getMaxVolume()));
				break;
			case 1:
				vehicles[idx]->setFuel(new Gasoline95(vehicles[idx]->getfuel()->getMaxVolume()));
				break;
			case 2:
				vehicles[idx]->setFuel(new Gasoline98(vehicles[idx]->getfuel()->getMaxVolume()));
				break;
			case 3:
				vehicles[idx]->setFuel(new Gasoline100(vehicles[idx]->getfuel()->getMaxVolume()));
				break;
			case 4:
				vehicles[idx]->setFuel(new Gas(vehicles[idx]->getfuel()->getMaxVolume()));
				break;
			case 5:
				vehicles[idx]->setFuel(new Diesel(vehicles[idx]->getfuel()->getMaxVolume()));
				break;
			case 6:
				vehicles[idx]->setFuel(new Electric(vehicles[idx]->getfuel()->getMaxVolume()));
				break;
			}
			break;
		}
	}
	void drivemode(size_t idx)
	{
		bool road = true;
		system("cls");
		std::vector<std::string> driveinfo;

		while (true)
		{
			system("cls");
			std::vector<std::string> temp = vehicles[idx]->getdriveinfo();
			driveinfo.insert(driveinfo.end(), temp.begin(), temp.end());
			WriteNice(driveinfo, YELLOW_FADE);
			drawDriveControls(driveinfo);
			switch (keymenu())
			{
			case VK_UP:
				vehicles[idx]->gear()->up();
				break;
			case VK_DOWN:
				vehicles[idx]->gear()->down();
				break;
			case ESC:
				system("cls");
				return;
			case VK_SHIFT:
				road = !road;
				break;
			case VK_TAB:
				fuelmenu(idx);
				driveinfo.clear();
				break;
			case VK_RETURN:
				driveinfo.push_back(vehicles[idx]->drive(road));
				break;
			case VK_BACK:
				driveinfo.clear();
				break;
			}
		}
	}
	void run()
	{
		Menu menu({ getnames(),"Welcome!" });
		while (true)
		{
			menu.generate(getnames(), "Welcome!");
			menu.drawOptions();
			menu.drawControls();
			switch (keymenu())
			{
			case VK_F1:
				system("cls");
				vehicles.push_back(Create());
				break;
			case VK_F2:
				system("cls");
				vehicles.push_back(Select());
				break;
			case VK_F3:
				vehicles.erase(vehicles.begin() + menu.getSelectedOption());
				break;
			case VK_F4:
				system("cls");
				vehicles.push_back(vehicles[menu.getSelectedOption()]->clone());
				vehicles[vehicles.size() - 1]->setModel(inputbox(BLUE, "Enter model name: "));
				break;
			case VK_F5:
				system("cls");
				vehicles[menu.getSelectedOption()]->testDrive();
				wait();
				break;
			case VK_F6:
				system("cls");
				vehicles[menu.getSelectedOption()]->info();
				wait();
				break;
			case VK_F7:
				shootmode(menu.getSelectedOption());
				break;
			case VK_F8:
				drivemode(menu.getSelectedOption());
				break;
			case VK_UP:
				menu.up();
				break;
			case VK_DOWN:
				menu.down();
				break;
			case ESC:
				system("cls");
				return;
			}
		}
	}
};