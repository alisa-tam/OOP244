/*Name: Alisa Tam
Student ID: 131580177
Date: 2018-07-11
Section: OOP244 AB*/

#ifndef _SICT_HERO_H
#define _SICT_HERO_H

#include <iostream>


namespace sict {
	const int maxRounds = 100;
	const int maxNameLength = 40;

	class Hero {
		int health;
		int attack;
		char heroName[maxNameLength + 1];

	public:
		
		Hero();
		Hero(const char *name, int h, int a);
		Hero(const Hero& copyHero);
		bool isEmpty() const;
		void operator -= (int attack);
		bool isAlive() const;
		int attackStrength() const;
		friend std::ostream& operator<<(std::ostream& os, const Hero& hero);
	};

	const Hero& operator*(const Hero& first, const Hero& second);






}
#endif

