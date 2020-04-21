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

	public:
		Contact();
		Contact(const char * n, const long long * p, int nop);
		~Contact();
		bool isEmpty() const;
		void display() const;
	};
}






#endif 