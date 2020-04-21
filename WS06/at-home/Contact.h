/*Name: Alisa Tam
Student ID: 131580177
Date: 2018-06-18
Section: OOP244 AB*/


#ifndef _SICT_CONTACT_H
#define _SICT_CONTACT_H

namespace sict {

	const int MAX_LENGTH = 20;

	class Contact {
		
		char name[MAX_LENGTH];
		long long * phone;
		int numOfPhone;
		bool breakDownPhone(long long, long long&, long long&, long long&, long long&) const;
		void set(const char * n, const long long * p, int nop);
		void copy(const Contact&);
	public:
		Contact();
		Contact(const char * n, const long long * p, int nop);
		~Contact();
		bool isEmpty() const;
		void display() const;
		Contact(const Contact &c);
		Contact& operator =(const Contact &c);
		Contact& operator +=(long long);

	};
}






#endif 