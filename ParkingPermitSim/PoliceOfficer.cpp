#include "stdafx.h"
#include "PoliceOfficer.h"
#include <string>
#include <iostream>
using namespace std;

// ParkedCar default constructor
ParkedCar::ParkedCar() {

	cout << "What is the make of the car?" << endl << "-->";
	cin >> carMake;
	cout << "What is the model of the car?" << endl << "-->";
	cin >> carModel;
	cout << "What is the color of the car?" << endl << "-->";
	cin >> carColor;
	cout << "What is the license number of the car?" << endl << "-->";
	cin >> carLicenseNumber;
	cout << "How many minutes was the car been parked?" << endl << "-->";
	cin >> numberOfMinutesParked;
}

ParkedCar::ParkedCar(string carMake, string carModel, string carColor, string carLicenseNumber, int numberOfMinutesParked) {
	this->carMake = carMake;
	this->carModel = carModel;
	this->carColor = carColor;
	this->carLicenseNumber = carLicenseNumber;
	this->numberOfMinutesParked = numberOfMinutesParked;
}

// ParkedCar getters
string & ParkedCar::getCarMake() { return carMake; }
string & ParkedCar::getCarModel() { return carModel; }
string & ParkedCar::getCarColor() { return carColor; }
string & ParkedCar::getCarLicenseNumber() { return carLicenseNumber; }
int ParkedCar::getNumberOfMinutesParked() { return numberOfMinutesParked; }

// ParkingMeter copy constructor
ParkingMeter::ParkingMeter(ParkingMeter &meter) 
	: ParkedCar(meter.getCarMake(), meter.getCarModel(), meter.getCarColor(), 
		meter.getCarLicenseNumber(), meter.getNumberOfMinutesParked()) {
	cout << "Parking Meter copied!" << endl;
}

// ParkingMeter constructor
ParkingMeter::ParkingMeter() : ParkedCar() {
	cout << "How much parking time (minutes) has been purchased?" << endl << "-->";
	cin >> numberOfMinutesPurchased;
}

// ParkingTicket constructor
ParkingTicket::ParkingTicket(ParkingMeter &meter, PoliceOfficer &officer) {
	calculateFine(meter);

	cout << "\t\t Parking Ticket" << endl;

	cout << endl << "\t\tCar Information" << endl;
	cout << "\t------------------------------" << endl;
	cout << "\tCar Make: " << meter.carMake << endl;
	cout << "\tCar Model: " << meter.carModel << endl;
	cout << "\tCar Color: " << meter.carColor << endl;
	cout << "\tLicense Number: " << meter.carLicenseNumber << endl << endl;

	cout << "\tFine: " << getTotalFine() << endl << endl;

	cout << "\t\tOfficer Information" << endl;
	cout << "\t------------------------------" << endl;
	cout << "\tOfficer Name: " << officer.firstName << " " << officer.lastName << endl;
	cout << "\tOfficer Badge Number: " << officer.badgeNumber << endl << endl;
}

void ParkingTicket::calculateFine(ParkingMeter &meter) {
	if (meter.numberOfMinutesParked > meter.numberOfMinutesPurchased) {
		totalFine = firstHourFine + (additionalHourFine * ((meter.numberOfMinutesParked - meter.numberOfMinutesPurchased)/60));
	}
}

double ParkingTicket::getTotalFine() { return totalFine; }

// PoliceOfficer constructor
PoliceOfficer::PoliceOfficer() {
	cout << "What is the officer's first name and last name?" << endl << "-->";
	cin >> firstName >> lastName;
	cout << "What is the officer's badge number?" << endl << "-->";
	cin >> badgeNumber;
}

// PoliceOfficer copy constructor
PoliceOfficer::PoliceOfficer(const PoliceOfficer &officer) {
	firstName = officer.firstName;
	lastName = officer.lastName;
	badgeNumber = officer.badgeNumber;
}

// PoliceOfficer getters
string & PoliceOfficer::getOfficerFirstName() { return firstName; }
string & PoliceOfficer::getOfficerLastName() { return lastName; }
string & PoliceOfficer::getOfficerBadgeNumber() { return badgeNumber; }

bool PoliceOfficer::checkIfTimeExpired(const ParkingMeter &meter) {
	if (meter.numberOfMinutesParked > meter.numberOfMinutesPurchased) {
		return true;
	}
	else {
		return false;
	}
}

// Generates ParkingTicket
void PoliceOfficer::issueParkingTicket(ParkingMeter &meter, PoliceOfficer &officer) { 
	ParkingTicket ticket(meter, officer);
}
