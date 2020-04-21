/*Name: Alisa Tam
Student #: 131580177
Email: abramovici@myseneca.ca
Section: OOP244 A */

#include "Account.h"

double sict::Account::balance() const
{
	return account_balance;
}

sict::Account::Account(double d)
{
	
	if (d > 0.0) {
		account_balance = d;
	}
	else {
		account_balance = 0.0;
	}
	
}

sict::Account::~Account()
{
}

bool sict::Account::credit(double c)
{
	if (c > 0.0) {
		account_balance += c;

		return true;
	}

	return false;
}

bool sict::Account::debit(double d)
{
	if (d > 0.0) {
		account_balance -= d;
		return true;
	}
	return false;
}
