/*Name: Alisa Tam
Student #: 131580177
Email: abramovici@myseneca.ca
Section: OOP244 A */

#ifndef SICT_CHEQUINGACCOUNT_H__
#define SICT_CHEQUINGACCOUNT_H__

#include "Account.h"

namespace sict {
	class ChequingAccount : public Account  {

		double transaction_fee;
		double month_end_fee;


		public:
			// TODO: constructor initializes account balance and transaction fee
			ChequingAccount(double, double, double);
			virtual ~ChequingAccount();

			// TODDO: credit adds +ve amount to the balance
			virtual bool credit(double);

			// TODO: debit subtracts a +ve amount from the balance
			virtual bool debit(double);

			// TODO: month end
			virtual void monthEnd();

			// TODO: display inserts the account information into an ostream
			virtual void display(std::ostream&) const;

	};
}
#endif
