/*
Name: Alisa Tam
Student #: 131580177
Email: aabramovici@myseneca.ca
Section: OOP244 A
*/

#include <iomanip>
#include <fstream>
#include <cstring>
#include "Perishable.h"

AMA::Perishable::Perishable() : Product('P')
{
	
}

std::fstream & AMA::Perishable::store(std::fstream & file, bool newLine) const
{
	
	Product::store(file, false) << ',' << date_ << (newLine ? "\n" : "");
	return file;
	// TODO: insert return statement here
}

std::fstream & AMA::Perishable::load(std::fstream & file)
{
	char c;
	Perishable temp;
	temp.Product::load(file);
	*this = temp;
	
	file >> c >> date_;

	return file;
	// TODO: insert return statement here
}

std::ostream & AMA::Perishable::write(std::ostream & os, bool linear) const
{
	
	Product::write(os, linear);
	if (!isClear()) {
		return os;
	}
	if (linear) {
		os << std::left << date_;
	}
	else {
		os << std::endl << " Expiry date: " << date_;
	}

	return os;
	// TODO: insert return statement here
}

std::istream & AMA::Perishable::read(std::istream & is)
{
	Date temp;

	Product::read(is);
	if (isClear()) {
		std::cout << " Expiry date (YYYY/MM/DD): ";
		is >> temp;

		switch (temp.errCode()) {
		case CIN_FAILED:
			message("Invalid Date Entry");
			break;

		case YEAR_ERROR:	
			message("Invalid Year in Date Entry");
			break;
		
		case MON_ERROR : 
			message("Invalid Month in Date Entry");
			break;

		case DAY_ERROR : 
			message("Invalid Day in Date Entry");
			break;
		}

		if (isClear() && !is.fail()) {
			date_ = temp;
		}
		else {
			is.setstate(std::ios::failbit);
		}
	}
	
	return is;

		// TODO: insert return statement here
}

const AMA::Date & AMA::Perishable::expiry() const
{
	return date_;
	// TODO: insert return statement here
}
