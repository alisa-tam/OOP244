/*Name: Alisa Tam
Student ID: 131580177
Date: 2018-07-04
Section: OOP244 AB*/



#include <iostream>
#include <cstring>
#include <iomanip>
#include "Contact.h"


using namespace std;

bool sict::Contact::breakDownPhone(long long fullNum, long long & cc, long long & ac, long long & num3, long long & num4) const
{
	num4 = fullNum % 10000;
	fullNum /= 10000;

	num3 = fullNum % 1000;
	fullNum /= 1000;

	ac = fullNum % 1000;
	fullNum /= 1000;

	cc = fullNum % 100;
	fullNum /= 100;

	return fullNum == 0 && cc > 0 && ac > 99 && num3 > 99;
	

}

void sict::Contact::set(const char * n, const long long * p, int nop)
{
	numOfPhone = 0;

	if (n != nullptr) {
		strncpy(name, n, MAX_LENGTH);
		name[MAX_LENGTH -1] = '\0';
	}
	else {
		name[0] = '\0';
	}

	if (p != nullptr && nop > 0) {
		phone = new long long[nop];

		long long cc, ac, num3, num4;

		for (int i = 0; i < nop; i++) {
			if (breakDownPhone(p[i], cc, ac, num3, num4)) {
				phone[numOfPhone++] = p[i];
			}
		}

	}
	else {

		phone = nullptr;
	}


	
	

}

void sict::Contact::copy(const Contact &c)
{
	strncpy(name, c.name, MAX_LENGTH);
	name[MAX_LENGTH - 1] = '\0';
	numOfPhone = c.numOfPhone;
	if (phone != nullptr) {
		delete[] phone;
		phone = nullptr;
	}
	if (c.phone != nullptr) {
		phone = new long long[numOfPhone];
		for (int i = 0; i < numOfPhone; i++) {
			phone[i] = c.phone[i];
		}
	}
	else {
		phone = nullptr;
	}
}

sict::Contact::Contact()
{
	set(nullptr, nullptr, 0);
}


sict::Contact::Contact(const char * n, const long long * p, int nop)
{
	set(n, p, nop);

}

sict::Contact::~Contact()
{
	if (phone != nullptr) {
		delete[] phone;
	}
	
}

bool sict::Contact::isEmpty() const
{
	return phone == nullptr && name[0] == '\0';
}

void sict::Contact::display() const
{
	if (isEmpty()) {
		cout << "Empty contact!" << endl;
	}
	else {
		cout << name << endl;
		long long cc, ac, num3, num4;
		for (int i = 0; i < numOfPhone; i++) {
			breakDownPhone(phone[i], cc, ac, num3, num4);

			cout << "(+" << cc << ") " << ac << " " << num3 << "-" << setfill('0') << setw(4) << num4 << endl;

		}
	}
}

sict::Contact::Contact(const Contact & c)
{
	phone = nullptr;
	copy(c);
}

sict::Contact & sict::Contact::operator=(const Contact & c)
{
	if (this != &c) {
		copy(c);
	}
	
	return *this;
	// TODO: insert return statement here
}

sict::Contact & sict::Contact::operator+=(long long p)
{
	if (!isEmpty()) {
		long long ccode, acode, newNum3, newNum4;

		if (breakDownPhone(p, ccode, acode, newNum3, newNum4)) {
			long long *temp = new long long[numOfPhone + 1];
			for (int i = 0; i < numOfPhone; i++) {
				temp[i] = phone[i];
			}

			temp[numOfPhone] = p;

			if (phone != nullptr) {
				delete[] phone;
			}

			phone = temp;
			numOfPhone++;
		}
	}
	// TODO: insert return statement here
	return *this;
}
