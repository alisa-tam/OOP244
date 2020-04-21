/*Name: Alisa Tam
Student ID: 131580177
Date: 2018-07-11
Section: OOP244 AB*/


#ifndef _SICT_SUPERHERO_H
#define _SICT_SUPERHERO_H

#include "Hero.h"

namespace sict {
	class SuperHero : public Hero {

		int bonus; 
		int defendStrength;

	public:
		SuperHero();
		SuperHero(const char *name, int h, int a, int b, int d);
		SuperHero(const SuperHero& copySuperHero);
		int attackStrength() const;
		int defend() const;
	};

	const SuperHero& operator*(const SuperHero& first, const SuperHero& second);
}
#endif
