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
using namespace sict;
using namespace std;

namespace sict {

    // TODO: implement the default constructor here
	Passenger::Passenger() {
		passengerName[max_size] = '/0';
		destination[maz_size] = '0/';

	}

	// TODO: implement the constructor with 2 parameters here
	Passenger::Passenger(const char* passenger_name, const char* destintation_name) {
		if (passengerName[0] = '/0'; || destination[0] = '0/'; ) {

				Passenger::Passenger();
		}
			else{
				
				strncpy(passengerName, passenger_name, max_size);
				passengerName[max_size] = '\0';
				strncpy(destination, destination_name, max_size);
				destination[max_size] = '\0';

			}

	}

    // TODO: implement isEmpty query here
	bool sict::Passenger::isEmpty() const {
		if (passengerName[0] != '/0' && destination[0] != '/0'){
			return false;
	}
	


    // TODO: implement display query here
	void sict::Passenger::display() const {
		if (Passenger = 1){
			cout << "PASSENGER-NAME -  " << passengerName << " DESTINATION" << endl;
		}else{
			cout << "No passenger!" << endl;	

	}

}

