// TODO: add file header comments here
/**********************************************************
Name: Alisa Abramovici
Student #: 131580177
Section: OOP244 SAB
Date: June 6, 2018
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
		passengerName[0] = '\0';
		destination[0] = '\0';
		
	}

	// TODO: implement the constructor with 2 parameters here
	Passenger::Passenger(const char* passenger_name, const char* destination_name) {
		if (passenger_name != nullptr && destination_name != nullptr && passenger_name[0] != '\0' && destination_name[0] != '\0') {

			strncpy(passengerName, passenger_name, max_size);
			passengerName[max_size] = '\0';
			strncpy(destination, destination_name, max_size);
			destination[max_size] = '\0';

		}
		else {
			*this = Passenger();
		}
	}

		// TODO: implement isEmpty query here
		bool Passenger:: isEmpty() const{
			return (passengerName[0] == '\0' && destination[0] == '\0');
		
		}



		// TODO: implement display query here

		void Passenger::display() const {
			if (isEmpty()) {
				cout << "No passenger!" << endl;
			}
			else {
				cout << passengerName << " - " << destination << endl;
			}
		}

	
}

