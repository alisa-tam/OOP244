/***********************************************************
// OOP244 Workshop 2: Dynamic Memory
// File Kingdom.cpp
//Name: Alisa Abramovici
//Student #: 131580177
//Date: 2018-05-30
//Section OOP244SAB*/

// HEADER SAFEGAURDS
#ifndef SICT_KINGDOM_H
#define SICT_KINGDOM_H



// NAMESPACE CREATED
namespace sict {

	//STRUCTURE DEFINITION FOR KINGDOM
	struct Kingdom {
		char m_name[32];
		int m_population;
	};

	//DECLERATION OF FUNCTION DISPLAY
	void display(Kingdom&);
	void display(Kingdom kingdom[], int s);

}


#endif

