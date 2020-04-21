/**********************************************************
Name: Alisa Abramovici
Student #: 131580177
Section: OOP244 SAB
Date: June 5, 2018
**********************************************************/


#include <cstring>
#include <iostream>
#include <iomanip>
#include "CRA_Account.h"

using namespace std;


namespace sict {

	void CRA_Account::set(const char* familyName, const char* givenName, int sin) {
		
		f_name[0] = '\0';
		g_name[0] = '\0';
		sin_num = 0;
		int temp_sin = sin;

		if (temp_sin >= min_sin && temp_sin <= max_sin && familyName[0] != '\0' && givenName[0] != '\0') {
			int sum = 0;
			for (int i = 0; i < 5; ++i)
			{
				int x = temp_sin % 100;
				int y = x / 10 * 2;
				sum += x % 10 + y / 10 + y % 10;
				temp_sin /= 100;
			}
			if (sum % 10 == 0) {
				sin_num = sin;
				strncpy(f_name, familyName, max_name_length);
				f_name[max_name_length] = '\0';
				strncpy(g_name, givenName, max_name_length);
				g_name[max_name_length] = '\0';
			}
		}
		for (int i = 0; i < max_yrs; ++i) {
			balance[i] = 0;
		}
		taxYearRe = 0;
	}

	bool CRA_Account::isEmpty()const {
		return sin_num < min_sin || sin_num > max_sin;
		}

	}

	
	void sict::CRA_Account::set(int y, double b)
	{
		if (!isEmpty() && taxYearRe < max_yrs) {
			taxReturn[taxYearRe] = y;
			balance[taxYearRe++] = b;
		}
	}

	void sict::CRA_Account::display() const
	{
		if (!isEmpty()) {
			cout << "Family Name: " << f_name << endl;
			cout << "Given Name : " << g_name << endl;
			cout << "CRA Account: " << sin_num << endl;
			cout << fixed << setprecision(2);
			for (int i = 0; i < taxYearRe; i++) {
				cout << "Year (" << taxReturn[i] << ") ";
				if (balance[i] > 2.00) {
					cout << "balance owing: " << balance[i] << endl;
				}
				else if (balance[i] < -2.00) {
					cout << "refund due: " << -balance[i] << endl;
				}
				else {
					cout << "No balance owing or refund due!" << endl;
				}
			}
		}
		else {
			cout << "Account object is empty!" << endl;
		}
	}

	




