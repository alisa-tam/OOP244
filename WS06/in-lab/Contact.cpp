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
