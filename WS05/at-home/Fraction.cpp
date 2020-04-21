/*Name: Alisa Abramovici
Student ID: 131580177
Date: 2018-06-18 
Section: OOP244 AB*/


#include<iostream>
#include"Fraction.h"
using namespace std;

// TODO: continue the namespace
namespace sict {
	// set (empty state)
	void Fraction::set() {
		flag = false;
		numerator = 0;
		denominator = 1;
	}

	// TODO: implement the default constructor
	Fraction::Fraction() {
		set();
	}

	// TODO: implement the two-argument constructor
	Fraction::Fraction(int n, int d) {
		if (n >= 0 && d > 0) {
			numerator = n;
			denominator = d;
			reduce();
		}
		else {
			set();
		}
	}

	// TODO: implement the max query
	int Fraction::max() const {
		if (numerator > denominator) {
			return numerator;
		}
		else {
			return denominator;
		}
	}


	// TODO: implement the min query

	int Fraction::min() const {
		if (numerator < denominator)
			return numerator;
		else
			return denominator;
	}

	// gcd returns the greatest common divisor of num and denom
	//
	int Fraction::gcd() const {
		int mn = min();  // min of numerator and denominator
		int mx = max();  // max of numerator and denominator
		int g_c_d = 1;
		bool found = false;

		for (int x = mn; !found && x > 0; --x) { // from mn decrement until divisor found
			if (mx % x == 0 && mn % x == 0) {
				found = true;
				g_c_d = x;
			}
		}
		return g_c_d;
	}

	// TODO: implement the reduce modifier


	void Fraction::reduce() {
		int divisor = gcd();
		numerator /= divisor;
		denominator /= divisor;
	}
	// TODO: implement the display query

	void Fraction::display() const {

		if (numerator > 0 && denominator == 1) {
			cout << numerator;
		}
		else {
			if (numerator >= 0 && denominator > 1) {
				cout << numerator << "/" << denominator;
			}
			else {
				cout << "no fraction stored";
			}
		}
	}



	// TODO: implement the isEmpty query
	bool Fraction::isEmpty() const {
		return !flag;
	}


	// TODO: implement the + operator (friend function)

	Fraction operator+ (const Fraction& rhs, const Fraction& lhs) {
		Fraction Result;
		if ((lhs.numerator >= 0 && lhs.denominator > 0) && (rhs.numerator >= 0 && rhs.denominator > 0) && !lhs.isEmpty() && !rhs.isEmpty()) {
			Result.numerator = (lhs.numerator*rhs.denominator) + (lhs.denominator*rhs.numerator);
			Result.denominator = lhs.denominator * rhs.denominator;
			Result.reduce();
		}
		else {
			Result.numerator = 0;
			Result.denominator = 1;
		}

		return Result;
	}


	//TODO: implement the * operator
	Fraction Fraction :: operator * (const Fraction& rhs) const {

		Fraction Result;
		if ((numerator >= 0 && denominator > 0) && (rhs.numerator >= 0 && rhs.denominator > 0) && !isEmpty() && !rhs.isEmpty()) {
			Result.numerator = (numerator*rhs.numerator);
			Result.denominator = (denominator * rhs.denominator);
			Result.reduce();
		}
		else {
			isEmpty();
		}

		return Result;
	}



	bool operator == (const Fraction& rhs, const Fraction& lhs) {
		bool result = false;
		if ((lhs.numerator >= 0 && lhs.denominator > 0) && (rhs.numerator >= 0 && rhs.denominator > 0) && (lhs.numerator == rhs.numerator) && (lhs.denominator == rhs.denominator) && !lhs.isEmpty() && !rhs.isEmpty()) {
			result = true;
		}
		else {
			result = false;
		}
			return result;
		
	}



	bool operator != (const Fraction& rhs, const Fraction& lhs)  {
		bool result = false;
		if ((lhs.numerator >= 0 && lhs.denominator > 0) && (rhs.numerator >= 0 && rhs.denominator > 0) && (lhs.numerator != rhs.numerator) && (lhs.denominator != rhs.denominator) && !lhs.isEmpty() && !rhs.isEmpty()) {
			result = true;
		}
		else {
			result = false;
		}
			return result;
		}
	



	Fraction Fraction :: operator += (const Fraction& rhs) {
	Fraction obj;
	if ((numerator >= 0 && denominator > 0) && (rhs.numerator >= 0 && rhs.denominator > 0) && !isEmpty() && !rhs.isEmpty()) {
	*this = *this + rhs;
	obj.reduce();
	}
	else {
		*this = obj;
	}
	return *this;
}

	}











