#pragma once
#include "stdafx.h"
#include <string>
using namespace std;

class ParkedCar {
// To know the car's make, model, color, license number, and the number of minutes that the car has been parked
private:
	string carMake, carModel, carColor, carLicenseNumber;
	int numberOfMinutesParked;
protected:
	ParkedCar();
public:
	ParkedCar(string carMake, string carModel, string carColor, string carLicenseNumber, int numberOfMinutesParked);
	string & getCarMake();
	string & getCarModel();
	string & getCarColor();
	string & getCarLicenseNumber();
	int getNumberOfMinutesParked();

	friend class PoliceOfficer;
	friend class ParkingTicket;
};

class ParkingMeter : public ParkedCar {
// To know the number of minutes of parking time that has been purchased
private:
	int numberOfMinutesPurchased;
public:
	ParkingMeter(ParkingMeter &meter); //Copy constructor
	ParkingMeter();
	friend class PoliceOfficer;
	friend class ParkingTicket;
};

class ParkingTicket {
/*To report the make, model, color, and license number of the illegally parked car
 To report the amount of the fine, which is $25 for the first hour or part of an
 hour that the car is illegally parked, plus $10 for every additional hour or part of
 an hour that the car is illegally parked
 To report the name and badge number of the police officer issuing the ticket
*/
private:
	const double firstHourFine = 25;
	const double additionalHourFine = 10;
	double totalFine = 0;

public:
	ParkingTicket(ParkingMeter &meter, PoliceOfficer &officer);
	void calculateFine(ParkingMeter &meter);
	double getTotalFine();
};

class PoliceOfficer {
	/*
	– To know the police officer’s name and badge number
	– To examine a ParkedCar object and a ParkingMeter object, and determine
	whether the car's time has expired
	– To issue a parking ticket (generate a ParkingTicket object) if the car’s time has
	expired
	*/
private:
	string firstName, lastName, badgeNumber;
public:
	PoliceOfficer();
	PoliceOfficer(const PoliceOfficer &officer);

	string & getOfficerFirstName();
	string & getOfficerLastName();
	string & getOfficerBadgeNumber();

	bool checkIfTimeExpired(const ParkingMeter &meter);
	void issueParkingTicket(ParkingMeter &meter, PoliceOfficer &officer);

	friend class ParkingTicket;
};
