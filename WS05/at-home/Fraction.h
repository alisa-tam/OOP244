/*Name: Alisa Abramovici
Student ID: 131580177
Date: 2018-06-18
Section: OOP244 AB*/



//TODO: header file guard
#ifndef SICT_FRACTION_H
#define SICT_FRACTION_H


// TODO: create namespace
namespace sict {


	// TODO: define the Fraction class
	class Fraction {
		// TODO: declare private member function
		int numerator;
		int denominator;
		bool flag;				
		int max() const;
		int min() const;
		void reduce();
		int gcd() const;
	public:
		// TODO: declare private member functions
		void set();
		Fraction();
		Fraction(int, int);
		bool isEmpty() const;
		void display() const;
		// TODO: declare the + operator overload
		friend  Fraction operator + (const Fraction& rhs, const Fraction& lhs);
		Fraction operator * (const Fraction& rhs) const;
		friend bool operator == (const Fraction& rhs, const Fraction& lhs);
		friend bool operator != (const Fraction& rhs, const Fraction& lhs);
		Fraction operator += (const Fraction& rhs);

		

	};
}

#endif // 
