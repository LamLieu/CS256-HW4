#pragma once
#include "stdafx.h"
#include <string>
using namespace std;

class Ship {
private:
	string shipName;
	string shipBuiltYear;
protected:
	Ship();
public:
	void setShipName(string shipName);
	void setShipBuiltYear(string shipYearBuilt);

	string & getShipName();
	string & getShipBuiltYear();

	virtual void print();
};

class CruiseShip : public Ship {
private:
	int maxNumberOfPassengers;
public:
	CruiseShip();

	void setMaxNumberOfPassengers(int maxNumberOfPassengers);
	int getMaxNumberOfPassengers();

	virtual void print() override;
};

class CargoShip : public Ship {
private:
	int cargoCapacity;
public:
	CargoShip();
	void setCargoCapacity(int cargoCapacity);
	int getCargoCapacity();
	virtual void print() override;
};