/***********************************************************
// OOP244 Workshop 2: Dynamic Memory
// File Kingdom.cpp
//Name: Alisa Abramovici
//Student #: 131580177
//Date: 2018-05-30
//Section OOP244SAB*/


// HEADER FILES
#include <iostream>
#include "Kingdom.h"
using namespace sict;
using namespace std;

//NAMESPACE CREATION
namespace sict {

	//DEFINITION FOR DISPLAY
	void display(struct Kingdom &pKingdom) {
		cout << pKingdom.m_name << ", population " << pKingdom.m_population << endl;
	}

	void display(Kingdom kingdom[], int s) {

		cout << "------------------------------" << endl;
		cout << "Kingdoms of SICT" << endl;
		cout << "------------------------------" << endl;
		
		int tp = 0;
		int i;

		for (i = 0; i < s; i++) {
			cout << i + 1 << ". ";
			display(kingdom[i]);

			tp += kingdom[i].m_population;
		}
		cout << "------------------------------" << endl;
		cout << "Total population of SICT: " << tp << endl;
		cout << "------------------------------" << endl;

	}
}
	


    
