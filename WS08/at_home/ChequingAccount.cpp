// OOP244 Workshop 8: Virtual Functions and Abstract Base Classes
// File: ChequingAccount.cpp
// Version: 2.0
// Date: 2017/12/11
// Author: Chris Szalwinski, based on previous work by Heidar Davoudi
// Description:
// This file implements the ChequingAccount class
///////////////////////////////////////////////////

/*Name: Alisa Tam
Student #: 131580177
Email: abramovici@myseneca.ca
Section: OOP244 A */


#include <iomanip>
#include "ChequingAccount.h"

using namespace std;

namespace sict {
	// constructor initializes balance and transaction fee
	//



	// credit (add) an amount to the account balance and charge fee
	// returns bool indicating whether money was credited
	//




	// debit (subtract) an amount from the account balance and charge fee
	// returns bool indicating whether money was debited
	//



	// monthEnd debits month end fee
	//



	// display inserts account information into ostream os
	//




	ChequingAccount::ChequingAccount(double ab, double tf, double mef) : Account(ab)
	{
		if (tf > 0.0) {
			transaction_fee = tf;
		}
		else {
			transaction_fee = 0.0;
		}

		if (mef > 0.0) {
			month_end_fee = mef;
		}
		else {
			month_end_fee = 0.0;
		}
	}

	ChequingAccount::~ChequingAccount()
	{
	}

	bool ChequingAccount::credit(double c)
	{
		if (Account::credit(c)) {
			Account::debit(transaction_fee);
			return true;
		}
		return false;
	}

	bool ChequingAccount::debit(double d)
	{
		if (Account::debit(d)) {
			Account::debit(transaction_fee);
			return true;
		}
		return false;
	}

	void ChequingAccount::monthEnd()
	{
		debit(month_end_fee);
	}

	void ChequingAccount::display(std::ostream &os) const
	{
		os << "Account type: Chequing" << std::endl;
		os << "Balance: $" << std::fixed << std::setw(6) << std::setprecision(2) << std::setfill('0') << balance() << std::endl;
		os << "Per Transaction Fee: " << std::fixed << std::setw(3) << std::setprecision(2) << std::setfill('0') << transaction_fee << std::endl;
		os << "Monthly Fee: " << std::fixed << std::setw(3) << std::setprecision(2) << std::setfill('0') << month_end_fee << std::endl;
	}


}