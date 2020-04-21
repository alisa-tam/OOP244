/*Name: Alisa Tam
Student #: 131580177
Email: abramovici@myseneca.ca
Section: OOP244 A */

#ifndef SICT_ACCOUNT_H__
#define SICT_ACCOUNT_H__

#include "iAccount.h"

namespace sict {
   
	class Account : public iAccount{ 
		
		double account_balance;
		

	protected:
		double balance() const;

	public:
		// TODO: constructor initializes account balance, defaults to 0.0 
		Account(double d = 0.0);

		virtual ~Account();

		// TODO: credit adds +ve amount to the balance 
		virtual bool credit(double) override;

		// TODO: debit subtracts a +ve amount from the balance
		virtual bool debit(double) override;
	};

	


}
#endif
