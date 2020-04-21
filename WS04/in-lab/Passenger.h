// TODO: add file header comments here
/**********************************************************
Name: Alisa Abramovici
Student #: 131580177
Section: OOP244 SAB
Date: June 6, 2018
**********************************************************/

// TODO: add header file guard here

#ifndef _SICT_PASSENGER_H
#define _SICT_PASSENGER_H

// TODO: declare your namespace here

namespace sict {

	// TODO: define the Passenger class here

	const int max_size = 32;

	class Passenger {
		char passengerName[max_size + 1];
		char destination[max_size + 1];

	public:
		Passenger();
		Passenger(const char*, const char*);
		bool isEmpty() const;
		void display() const;



	};


}
#endif