/*
Name: Alisa Tam
Student #: 131580177
Email: aabramovici@myseneca.ca
Section: OOP244 A
*/

#ifndef AMA_PRODUCT_H
#define AMA_PRODUCT_H
#include "ErrorState.h"
#include "iProduct.h"

namespace AMA {

	const int max_sku_length = 7;
	const int max_unit_length = 10;
	const int max_name_length = 75;
	const double TAX = 0.13;

	class Product : public iProduct {
	private:
		char product;
		char sku_[max_sku_length + 1];
		char unit_[max_unit_length + 1];
		char * name_product = nullptr;
		int current_units;
		int units_needed;
		double price_single_unit;
		bool taxable;
		ErrorState error_;
		void copy(char p, const char* sku, const char* n, const char* unit, 
			int qty, bool isTaxed, double price, int qtyNeeded);


	protected:
		void name(const char*); 
		const char* name() const; 
		const char* sku() const; 
		const char* unit() const; 
		bool taxed() const; 
		double price() const;
		double cost() const;
		void message(const char*);
		bool isClear() const; 

	public:
		Product(char p = 'N');
		Product(const char* sku, const char* n, const char* unit, int qty = 0,bool isTaxed = true, double price = 0.0, int qtyNeeded = 0);
		Product(const Product &);
		Product& operator= (const Product &);
		virtual~Product(); //frees dynamically allocated memory
		std::fstream& store(std::fstream& file, bool newLine = true) const;
		std::fstream& load(std::fstream& file);
		std::ostream& write(std::ostream& os, bool linear) const;
		std::istream& read(std::istream& is);
		bool operator==(const char*)const;
		double total_cost()const;
		void quantity(int);
		bool isEmpty()const;
		int qtyNeeded() const;
		int quantity()const;
		bool operator>(const char*)const;
		bool operator>(const iProduct&)const;
		int operator+=(int);
		
		
	};

	std::ostream& operator<<(std::ostream&, const iProduct&);
	std::istream& operator>>(std::istream&, iProduct&);
	double operator+=(double&, const iProduct&);


}
#endif
