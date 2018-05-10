#include "stdafx.h"
#include "Ship.h"
#include <iostream>
#include <string>
using namespace std;

Ship::Ship() {
	cout << "What is the name of the ship?" << endl << "-->";
	cin >> shipName;
	cout << "What year was the ship built?" << endl << "-->";
	cin >> shipBuiltYear;
}

string & Ship::getShipName() { return shipName; }
string & Ship::getShipBuiltYear() { return shipBuiltYear; }

void Ship::setShipName(string shipName) {
	this->shipName = shipName;
}

void Ship::setShipBuiltYear(string shipBuiltYear) {
	this->shipBuiltYear = shipBuiltYear;
}

void Ship::print() {
	cout << "Ship Name: " << getShipName() << endl;
	cout << "The ship was built in the year: " << shipBuiltYear << endl;
}

CruiseShip::CruiseShip() : Ship() {
	cout << "What is the maximum amount of passengers?" << endl << "-->";
	cin >> maxNumberOfPassengers;
}

void CruiseShip::setMaxNumberOfPassengers(int maxNumberOfPassengers) {
	this->maxNumberOfPassengers = maxNumberOfPassengers;
}

int CruiseShip::getMaxNumberOfPassengers() { return maxNumberOfPassengers; }

void CruiseShip::print() {
	cout << "Ship Name: " << getShipName() << endl;
	cout << "Maximum number of Passengers: " << maxNumberOfPassengers << endl;
}

CargoShip::CargoShip() : Ship() {
	cout << "What is the max cargo capacity of the ship?" << endl << "-->";
	cin >> cargoCapacity;
}

void CargoShip::setCargoCapacity(int cargoCapacity) {
	this->cargoCapacity = cargoCapacity;
}
int CargoShip::getCargoCapacity() { return cargoCapacity; }

void CargoShip::print() {
	cout << "Ship Name: " << getShipName() << endl;
	cout << "The cargo capacity of the ship is: " << cargoCapacity << endl;
}
