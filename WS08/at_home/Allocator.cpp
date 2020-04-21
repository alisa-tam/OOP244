/*Name: Alisa Tam
Student #: 131580177
Email: abramovici@myseneca.ca
Section: OOP244 A */

#include "SavingsAccount.h" 
#include "ChequingAccount.h"

namespace sict {

	// define interest rate
	//

	const double interest_rate = 0.05;
	const double transaction_fee = 0.50;
	const double monthly_fee = 2.00;


	// TODO: Allocator function
	//
	iAccount* CreateAccount(const char* a, double ib) {
		if (a == nullptr) {
			return nullptr;
		}

		switch (a[0]) {
		case 'S':
			return new SavingsAccount(ib, interest_rate);
		case 'C':
			return new ChequingAccount(ib, transaction_fee, monthly_fee);
		}

		return nullptr;

	}








}
