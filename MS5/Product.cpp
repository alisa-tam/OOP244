/*
Name: Alisa Tam
Student #: 131580177
Email: aabramovici@myseneca.ca
Section: OOP244 A
*/

#include <iomanip>
#include <fstream>
#include <cstring>
#include "Product.h"

void AMA::Product::copy(char p, const char * sku, const char * n, const char * unit, int qty, bool isTaxed, double price, int qtyNeeded)
{
	product = p;
	std::strncpy(sku_, sku, max_sku_length);
	sku_[max_sku_length] = '\0';
	std::strncpy(unit_, unit, max_unit_length);
	unit_[max_unit_length] = '\0';
	current_units = qty;
	taxable = isTaxed;
	price_single_unit = price;
	units_needed = qtyNeeded;

	name(n);
}

void AMA::Product::name(const char * np)
{
	if (name_product != nullptr){

		delete[] name_product;
		name_product = nullptr;
	}
	if (np != nullptr) {
		
		name_product = new char[max_unit_length];
		strcpy(name_product, np);
	}
	
}

const char * AMA::Product::name() const
{
	return name_product;

}

const char * AMA::Product::sku() const
{

	return &sku_[0];
}

const char * AMA::Product::unit() const
{
	return &unit_[0];
}

bool AMA::Product::taxed() const
{
	return taxable;
}

double AMA::Product::price() const
{
	return price_single_unit;
}

double AMA::Product::cost() const
{
	if (taxed()) {
		return price() * (1.0 + TAX);
	}

	return price();
	//return price_single_unit += (price_single_unit * TAX);
}

void AMA::Product::message(const char * error)
{
	error_.message(error);
}

bool AMA::Product::isClear() const
{
	return error_.isClear();
}

AMA::Product::Product(char p)
{
	copy(p, "", nullptr, "", 0, true, 0, 0);

}

AMA::Product::Product(const char * sku, const char * n, const char * unit, int qty, bool isTaxed, double price, int qtyNeeded)
{
	copy('N', sku, n, unit, qty, isTaxed, price, qtyNeeded);
}

AMA::Product::Product(const Product &prod)
{
	copy(prod.product, prod.sku_, prod.name_product, prod.unit_, 
		prod.current_units, prod.taxable, prod.price_single_unit, prod.units_needed);
	
}

AMA::Product & AMA::Product::operator=(const Product & prod)
{
	
	copy(product, prod.sku_, prod.name_product, prod.unit_,
		prod.current_units, prod.taxable, prod.price_single_unit, prod.units_needed);

	return *this;

}

AMA::Product::~Product()
{
	if (name_product != nullptr) {
		delete[] name_product;
	}
	
}

std::fstream & AMA::Product::store(std::fstream & file, bool newLine) const
{
	file << product << ',' << sku_ << ',' << (name_product ? name_product : "") << ',' << unit_ << ','
		<< taxable << ',' << price_single_unit << ',' << current_units << ',' << units_needed <<(newLine ? "\n" : "");
	
	return file;
}

std::fstream & AMA::Product::load(std::fstream & file)
{
	
	Product temp;
	char t;
	//file >> temp.product >> t;
	file.getline(temp.sku_, max_sku_length + 1, ',');
	
	temp.name_product = new char[max_name_length + 1];
	file.getline(temp.name_product, max_name_length + 1, ',');
	file.getline(temp.unit_, max_unit_length + 1, ',');
	file >> temp.taxable >> t >> temp.price_single_unit >> t >> temp.current_units >> t >>temp.units_needed;
	
	*this = temp;

	return file;
}

std::ostream & AMA::Product::write(std::ostream & os, bool linear) const
{
	if (!isClear()) {
		return os << error_;
	}
	if (linear) {
		os << std::setw(max_sku_length)<<std::left << sku_ << '|' << std::setw(20) << (name_product ? name_product : "")
			<< '|' << std::setw(7) << std::fixed << std::setprecision(2)<<std::right << cost() << '|' << std::setw(4) << current_units
			<< '|' << std::setw(10) <<std::left<< unit_ << '|' << std::setw(4) <<std::right<< units_needed << '|';
	}
	else {
		os << " Sku: " << sku_ << std::endl;
		os << " Name (no spaces): " << (name_product ? name_product : "") << std::endl;
		os << " Price: " << std::setprecision(2) << price_single_unit << std::endl;
		if (taxable) {
			os << " Price after tax: " << std::setprecision(2) << cost() << std::endl;
		}
		else {
			os << " Price after tax: N/A" << std::endl;
		}
		os << " Quantity on Hand: " << current_units << " " << unit_ << std::endl;
		os << " Quantity needed: " << qtyNeeded();
	}
	
	return os;
}

std::istream & AMA::Product::read(std::istream & is)
{
	Product t;
	char temp[max_name_length + 1];

	error_.clear();
	std::cout << " Sku: ";
	//is.ignore(1000000, ':').get();
	
	is.getline(t.sku_, max_sku_length);
	std::cout << " Name (no spaces): ";
	//is.ignore(1000000, ':').get();
	is.getline(temp, max_name_length);
	t.name(temp);
	//is.ignore(1000000, ':').get();
	std::cout << " Unit: ";
	is.getline(t.unit_, max_unit_length);
	std::cout << " Taxed? (y/n): ";
	//is.ignore(1000000, ':').get();
	is >> temp[0];
	//is.getline(temp, 2);
	if (temp[0] == 'y' || temp[0] == 'Y') {
		t.taxable = true;
	}
	else if (temp[0] == 'n' || temp[0] == 'N') {
		t.taxable = false;
	}
	else {
		message("Only (Y)es or (N)o are acceptable");
		is.setstate(std::ios::failbit);
		return is;
	}
	//is.ignore(1000000, ':').get();
	std::cout << " Price: ";
	is >> t.price_single_unit;
	if (is.fail()) {
		message("Invalid Price Entry");
		return is;
	}
	//is.ignore(1000000, ':').get();
	std::cout << " Quantity on hand: ";
	is >> t.current_units;
	if (is.fail()) {
		message("Invalid Quantity Entry");
		return is;
	}
	//is.ignore(1000000, ':').get();
	std::cout << " Quantity needed: ";
	is >> t.units_needed;
	if (is.fail()) {
		message("Invalid Quantity Needed Entry");
		return is;
	}
	is.ignore(100000, '\n');

	*this = t;

	return is;
}

bool AMA::Product::operator==(const char *tsku) const
{
	return !std::strcmp(tsku, sku_);
}

double AMA::Product::total_cost() const
{
	
	return cost() * current_units;
}

void AMA::Product::quantity(int poh)
{
	current_units = poh;
}

bool AMA::Product::isEmpty() const
{
	return  sku_[0] == '\0';

}

int AMA::Product::qtyNeeded() const
{
	return units_needed;
}

int AMA::Product::quantity() const
{
	return current_units;
}

bool AMA::Product::operator>(const char *sku) const
{
	if (sku) {
		return std::strcmp(sku_, sku) > 0;
	}

	return false;
	
}

bool AMA::Product::operator>(const iProduct &prod) const
{
	if (name_product && prod.name()) {
		return std::strcmp(name_product, prod.name()) > 0;
	}
	return false;
}

int AMA::Product::operator+=(int needed)
{
	if (needed > 0) {

		current_units += needed;
	
	}
	
	return current_units;
	
}

std::ostream & AMA::operator<<(std::ostream &os, const iProduct &p)
{
	return p.write(os, true);
	
}

std::istream & AMA::operator>>(std::istream &is, iProduct &p)
{
	return p.read(is);
}

double AMA::operator+=(double &d, const iProduct &p)
{
	
	return d += p.total_cost();
	
}
