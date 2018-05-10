#include "stdafx.h"
#include "PoliceOfficer.h"
#include <string>
#include <iostream>
using namespace std;

ParkedCar::ParkedCar(const string carMake, const string carModel, const string carColor, 
	const string carLicenseNumber, const int numberOfMinutesParked) {

	this->carMake = carMake;
	this->carModel = carModel;
	this->carColor = carColor;
	this->carLicenseNumber = carLicenseNumber;
	this->numberOfMinutesParked = numberOfMinutesParked;
}

string & ParkedCar::getCarMake() { return carMake; }
string & ParkedCar::getCarModel() { return carModel; }
string & ParkedCar::getCarColor() { return carColor; }
string & ParkedCar::getCarLicenseNumber() { return carLicenseNumber; }
int ParkedCar::getNumberOfMinutesParked() { return numberOfMinutesParked; }

void ParkedCar::setCarMake(string carMake) {
	this->carMake = carMake;
}
void ParkedCar::setCarModel(string carModel) {
	this->carModel = carModel;
}
void ParkedCar::setCarColor(string carColor) {
	this->carColor = carColor;
}
void ParkedCar::setCarLicenseNumber(string carLicenseNumber) {
	this->carLicenseNumber = carLicenseNumber;
}

void ParkedCar::setNumberOfMinutesParked(int numOfMinutesParked) {
	this->numberOfMinutesParked = numOfMinutesParked;
}

ParkingMeter::ParkingMeter(const ParkingMeter &meter) 
	: ParkedCar(meter.getCarMake(), meter.getCarModel(), meter.getCarColor(), meter.getCarLicenseNumber, meter.getNumberOfMinutesParked) {
	cout << "Parking Meter copied!" << endl;
}

ParkingMeter::ParkingMeter(const string carMake, const string carModel, const string carColor, 
	const string carLicenseNumber, const int numOfMinutesParked)
	: ParkedCar(carMake, carModel, carColor, carLicenseNumber, numOfMinutesParked) {
	cout << "How much parking time (minutes) has been purchased?";
	cin >> numberOfMinutesPurchased;
}

ParkingTicket::ParkingTicket(const ParkingMeter &meter, const PoliceOfficer &officer) 
	: ParkingMeter(meter), PoliceOfficer(officer) {
	carMake = meter.carMake;
	carModel = meter.carModel;
	carColor = meter.carColor;
	carLicenseNumber = meter.carLicenseNumber;
	numberOfMinutesParked = meter.numberOfMinutesParked;
	numberOfMinutesPurchased = meter.numberOfMinutesPurchased;

	firstName = officer.firstName;
	lastName = officer.lastName;
	badgeNumber = officer.badgeNumber;
}

void ParkingTicket::calculateFine() {
	if (numberOfMinutesParked > numberOfMinutesPurchased) {
		totalFine = firstHourFine + (additionalHourFine * numberOfMinutesParked - numberOfMinutesPurchased);
	}
}

double ParkingTicket::getTotalFine() { return totalFine; }

PoliceOfficer::PoliceOfficer(const string f_name, const string l_name, const string badgeNumber) {
	firstName = f_name;
	lastName = l_name;
	this->badgeNumber = badgeNumber;
}

PoliceOfficer::PoliceOfficer(const PoliceOfficer &officer) {
	firstName = officer.firstName;
	lastName = officer.lastName;
	badgeNumber = officer.badgeNumber;
}

string & PoliceOfficer::getOfficerFirstName() { return firstName; }
string & PoliceOfficer::getOfficerLastName() { return lastName; }
string & PoliceOfficer::getOfficerBadgeNumber() { return badgeNumber; }

bool PoliceOfficer::checkIfTimeExpired(ParkingMeter &meter) {
	if (meter.numberOfMinutesParked > meter.numberOfMinutesPurchased) {
		return true;
	}
	else {
		return false;
	}
}

void PoliceOfficer::issueParkingTicket() { 
	ParkingTicket ticket(ParkingMeter &meter);
}