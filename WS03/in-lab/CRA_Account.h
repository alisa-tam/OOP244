/**********************************************************
Name: Alisa Abramovici
Student #: 131580177
Section: OOP244 SAB
Date: June 5, 2018
**********************************************************/

#ifndef SICT_CRA_ACCOUNT_H
#define SICT_CRA_ACCOUNT_H

namespace sict {

	const int max_name_length = 40; 
	const int min_sin = 100000000; 
	const int max_sin = 999999999;  
	const int max_yrs = 4;

	class CRA_Account {
		char family_name[max_name_length + 1];
		char given_name[max_name_length + 1];
		int  sin;
		int tax_return[max_yrs];
		double balance_owed[max_yrs];
		int tax_yr_return;

	public:
		void set(const char*, const char*, int);
		void set(int, double);
		bool isEmpty() const;
		void display() const;
	};
}

#endif

