/*
Name: Alisa Tam
Student #: 131580177
Email: aabramovici@myseneca.ca
Section: OOP244 A
*/

#ifndef AMA_PERISHABLE_H
#define AMA_PERISHABLE_H
#include "Product.h"
#include "Date.h"

namespace AMA {

	class Perishable : public Product {
	private:
		Date date_;

	public:
		Perishable();
		std::fstream& store(std::fstream& file, bool newLine = true) const override;
		std::fstream& load(std::fstream& file) override;
		std::ostream& write(std::ostream& os, bool linear) const override;
		std::istream& read(std::istream& is) override;
		const Date& expiry()const;
	};

}
#endif
