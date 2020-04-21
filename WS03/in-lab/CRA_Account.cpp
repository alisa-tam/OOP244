/**********************************************************
Name: Alisa Abramovici
Student #: 131580177
Section: OOP244 SAB
Date: June 5, 2018
**********************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "CRA_Account.h"
#include <cstring>
#include <iomanip>

using namespace sict;
using namespace std;

namespace sict {

	void sict::CRA_Account::set(const char* fName, const char* gName, int si) {
		familyName[0] = '\0';
		givenName[0] = '\0';
		sin = 0;
		sin = si;
		if (isEmpty() == false && familyName[0] != '\0' && givenName[0] != '\0') {
			int sum = 0;
			int i;
			for (i = 0; i < max_yrs + 1; ++i); {
				int temp = sin % 100;
				int even = temp / 10 * 2;
				sum += temp % 10 + even / 10 + even % 10;
				sin /= 100;
			}

			if (sum % 10 == 0) {
				sin = si;
				strncpy(familyName, fName, max_name_length);
				familyName[max_name_length] = '\0';
				strncpy(givenName, gName, max_name_length);
				givenName[max_name_length] = '\0';

			}
			 
		}
		for (int i = 0; i < max_yrs; ++i) {
			balance_owed[i] = 0;
			tax_yr_return = 0;
		}
		//else {
			//sin = -1;
		//}
		
	}

	bool sict::CRA_Account::isEmpty()const {
		if (sin > min_sin && sin < max_sin) {
			return false;
		}
	
			return true;

		
	}
	void sict::CRA_Account::display()const {

		if (sin != -1) {
			cout << "Family Name: " << familyName << endl;
			cout << "Given Name : " << givenName << endl;
			cout << "CRA Account: " << sin << endl;
			cout << fixed << setprecision(2);

			for (int i = 0; i < tax_yr_return; ++i) {
				cout << "Year (" << balance_owed[i] << ") ";
			}
		}
		else {
			cout << "Account object is empty!" << endl;
		}

	}

	void sict::CRA_Account::set(int year, double balance) {
		if (isEmpty() == false && tax_yr_return < max_yrs) {
			taxYrs[tax_yr_return] = year;
			balance_owed[tax_yr_return] = balance;
			storeData++;
			


		}

	}
}