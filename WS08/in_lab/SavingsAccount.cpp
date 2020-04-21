/*Name: Alisa Tam
Student #: 131580177
Email: abramovici@myseneca.ca
Section: OOP244 A */

#include <iomanip>
#include "SavingsAccount.h"


sict::SavingsAccount::SavingsAccount(double b, double i) : Account(b)
{
	if (i > 0.0) {
		savings_interest = i;
	}
	else {
		savings_interest = 0.0;
	}
}

sict::SavingsAccount::~SavingsAccount()
{
}

void sict::SavingsAccount::monthEnd()
{
	credit(balance() * savings_interest);
}

void sict::SavingsAccount::display(std::ostream &os) const
{
	os << "Account type: Savings" << std::endl;
	os << "Balance: $" << std::fixed << std::setw(6) << std::setprecision(2) << std::setfill('0') << balance() << std::endl;
	os << "Interest Rate (%): " << std::fixed << std::setw(3) << std::setprecision(2) << std::setfill('0') << savings_interest * 100.0 << std::endl;
}
