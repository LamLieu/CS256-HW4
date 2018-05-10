#include "stdafx.h"
#include "PoliceOfficer.h"
#include <string>
#include <iostream>
using namespace std;

int main()
{
	PoliceOfficer officer;
	ParkingMeter meter;

	bool timeExpired = officer.checkIfTimeExpired(meter);
	if (timeExpired) {
		officer.issueParkingTicket(meter, officer);
	}
	else { 
		cout << "Officer didn't isuse ticket" << endl;
	}

    return 0;
}

