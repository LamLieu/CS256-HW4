#include "stdafx.h"
#include "Ship.h"
#include <iostream>
#include <string>
using namespace std;

int main() {
	Ship *ships[4] = 
	{	new CruiseShip,
		new CargoShip,
		new CruiseShip,
		new CargoShip
	};

	for (int count = 0; count < 4; count++) {
		cout << endl << "Ship " << count + 1 << " Information" << endl;
		ships[count]->print();
	}

	return 0;
}
