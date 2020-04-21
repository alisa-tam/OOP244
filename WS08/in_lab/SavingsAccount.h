/*Name: Alisa Tam
Student #: 131580177
Email: abramovici@myseneca.ca
Section: OOP244 A */

#ifndef SICT_SAVINGSACCOUNT_H__
#define SICT_SAVINGSACCOUNT_H__

#include "Account.h"

namespace sict {
	class SavingsAccount : public Account{
		double savings_interest;

	
	public:
			// TODO: constructor initializes balance and interest rate
		SavingsAccount(double, double);

		virtual ~SavingsAccount();

			// TODO: perform month end transactions
		virtual void monthEnd() override;

			// TODO: display inserts the account information into an ostream			
		virtual void display(std::ostream&) const override;
	};
}
#endif
