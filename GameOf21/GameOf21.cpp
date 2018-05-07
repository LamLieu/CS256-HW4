#include "stdafx.h"
#include "Die.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{
	int scoreComputer = 0;
	int scoreUser = 0;
	string userChoice;

	Die die1(6);
	Die die2(6);

	while (scoreUser <= 21) {
		cout << "Your current score is: " << scoreUser << endl;
		cout << "Would you like to keep rolling? (Y/N)" << endl << "-->";
		cin >> userChoice;

		if (userChoice.at(0) == 'n' || userChoice.at(0) == 'N') {
			cout << endl;
			break;
		}

		if (userChoice.at(0) != 'y' && userChoice.at(0) == 'Y') {
			cout << "Invalid input, ending program." ;
			return 1;
		}

		die1.roll();
		die2.roll();
		scoreComputer += die1.getValue() + die2.getValue();

		die1.roll();
		die2.roll();
		scoreUser += die1.getValue() + die2.getValue();
		cout << endl;
	}

	// Cases for when user or computer went over 21 and the other didn't
	if (scoreComputer > 21 && scoreUser <= 21) {
		cout << "The computer lost with a score of " << scoreComputer << "." << endl;
		cout << "You won with a score of " << scoreUser << "." << endl;
	}
	else if (scoreComputer <= 21 && scoreUser > 21) {
		cout << "The computer won with a score of " << scoreComputer << "." << endl;
		cout << "You lost with a score of " << scoreUser << "." << endl;
	}
	// Cases for when user or computer has a higher number than the other
	else if (scoreComputer > scoreUser) {
		cout << "The computer won with a score of " << scoreComputer << "." << endl;
		cout << "You lost with a score of " << scoreUser << "." << endl;
	}
	else if (scoreComputer < scoreUser) {
		cout << "The computer lost with a score of " << scoreComputer << "." << endl;
		cout << "You won with a score of " << scoreUser << "." << endl;
	}
	// Case for when user and computer are equal
	else if (scoreComputer == scoreUser) {
		cout << "You and the computer are tied with a score of " << scoreComputer << "." << endl;
	}
    return 0;
}

