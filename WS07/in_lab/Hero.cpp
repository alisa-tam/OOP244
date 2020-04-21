/*Name: Alisa Tam
Student ID: 131580177
Date: 2018-07-11
Section: OOP244 AB*/

#include <iostream>
#include <string.h>
#include "Hero.h"


sict::Hero::Hero()
{
	health = 0;
	attack = 0;
	heroName[maxNameLength] = '\0';
}

sict::Hero::Hero(const char * name, int h, int a)
{
	health = h;
	attack = a;

	if (name) {
		strncpy(heroName, name, maxNameLength);
		heroName[maxNameLength] = '\0';
	}
	
}

sict::Hero::Hero(const Hero & copyHero)
{
	health = copyHero.health;
	attack = copyHero.attack;
	strncpy(heroName, copyHero.heroName, maxNameLength);
	
}

bool sict::Hero::isEmpty() const
{
	return attack <= 0;
}

void sict::Hero::operator-=(int attack)
{

	if (!isEmpty()) {
		health -= attack;
		if (health < 0) {
			health = 0;
		}
	}
}

bool sict::Hero::isAlive() const
{

	return health > 0;
}

int sict::Hero::attackStrength() const
{
	
	return attack;
	
}


namespace sict {
	std::ostream & operator<<(std::ostream & os, const Hero & hero)
	{
		if (!hero.isEmpty()) {

			os << hero.heroName;
		}
		else {
			os << "No hero";
		}


		return os;
	}
}


const sict::Hero & sict::operator*(const Hero & first, const Hero & second)
{
	std::cout << "Ancient Battle! " << first << " vs " << second << " : Winner is ";
	Hero f(first);
	Hero s(second);

	for (int i = 0; i < maxRounds; i++) {
		f -= s.attackStrength();
		s -= f.attackStrength();

		if (!s.isAlive()) {
			std::cout << f << " in " << i + 1 << " rounds." << std::endl;

			return first;
		} 
		
		if (!f.isAlive()) {
			std::cout << s << " in " << i + 1 << " rounds." << std::endl;

			return second;
		}

	}
	
	std::cout << f << " in " << maxRounds << " rounds." << std::endl;
	
	return first;
}
