/**********************************************************
Name: Alisa Abramovici
Student #: 131580177
Section: OOP244 SAB
Date: June 12, 2018
**********************************************************/


// TODO: add header file guard here
#ifndef SICT_PASSENGER_H_
#define SICT_PASSENGER_H_

// TODO: declare your namespace here
namespace sict {
	const int NameMax = 32;
	const int YearMax = 2020;
	const int YearMin = 2017;
	const int MonthMax = 12;
	const int MonthMin = 1;
	const int DayMax = 31;
	const int DayMin = 1;
	
	// TODO: define the Passenger class here
		class Passenger {
		private:
			bool flag;
			char pass_Name[NameMax];
			char destination[NameMax];
			int yearDep;
			int monthDep;
			int dayDep;
			void set();

		public:
			Passenger();
			Passenger(const char *, const char *);
			bool isEmpty() const;
			void display() const;
			Passenger(const char *, const char *, const int, const int, const int);
			const char* name() const;
			bool canTravelWith(const Passenger&) const;
	};
}
#endif // !SICT_PASSENGER_H_