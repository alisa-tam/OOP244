/**********************************************************
Name: Alisa Abramovici
Student #: 131580177
Section: OOP244 SAB
Date: June 12, 2018
**********************************************************/

// TODO: add your headers here
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Passenger.h"

// TODO: continue your namespace here
using namespace std;

namespace sict {

	// TODO: implement the default constructor here
	Passenger::Passenger() {
		set();
	}

	void Passenger::set() {
		flag = false;
		strncpy(pass_Name, "no data", 7);
		pass_Name[7] = char(0);
		strncpy(destination, "no data", 7);
		destination[7] = char(0);

		yearDep = 0;
		monthDep = 0;
		dayDep = 0;
	}

	// TODO: implement the constructor with 2 parameters here
	Passenger::Passenger(const char * passName, const char * passDestination) {
		if (passName != nullptr && passDestination != nullptr && passName[0] != char(0) && passDestination[0] != char(0)) {
			flag = true;
			strncpy(pass_Name, passName, strlen(passName));
			pass_Name[strlen(passName)] = char(0);
			strncpy(destination, passDestination, strlen(passDestination));
			destination[strlen(passDestination)] = char(0);
			yearDep = 2017;
			monthDep = 7;
			dayDep = 1;
		}
		else {
			set();
		}

	}

	Passenger::Passenger(const char * passName, const char * passDestination, const int year, const int month, const int day) {
		if (passName != nullptr && passDestination != nullptr && passName[0] != char(0) && passDestination[0] != char(0) && year <= YearMax && year >= YearMin && month <= MonthMax && month >= MonthMin && day <= DayMax && day >= DayMin) {
			flag = true;
			strncpy(pass_Name, passName, strlen(passName));
			pass_Name[strlen(passName)] = char(0);
			strncpy(destination, passDestination, strlen(passDestination));
			destination[strlen(passDestination)] = char(0);
			dayDep = day;
			yearDep = year;
			monthDep = month;
		}
		else {
			set();
		}
	}
	// TODO: implement isEmpty query here
	bool Passenger::isEmpty() const {
		return !flag;
	}
	// TODO: implement display query here
	void Passenger::display() const {
		if (!isEmpty()) {
			cout << pass_Name << " - " << destination << " on " << yearDep << "/";
			cout.width(2);
			cout.fill('0');
			cout << monthDep;
			cout << "/";
			cout.width(2);
			cout.fill('0');
			cout << dayDep << endl;
		}
		else {
			cout << "No passenger!" << endl;
		}
	}

	const char* Passenger::name() const {

		return (!isEmpty() ? pass_Name : nullptr);

	}
	bool Passenger::canTravelWith(const Passenger& passenger) const {
		bool result = false;
		if (!strcmp(passenger.destination, destination) && passenger.yearDep == yearDep && passenger.monthDep == monthDep && passenger.dayDep == dayDep) {
			result = true;
		}
		return result;
	}
}
