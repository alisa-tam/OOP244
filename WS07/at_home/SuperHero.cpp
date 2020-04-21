#include "SuperHero.h"

sict::SuperHero::SuperHero(): Hero ()
{
	bonus = 0;
	defendStrength = 0;
}

sict::SuperHero::SuperHero(const char *name, int h, int a, int b, int d) : Hero(name, h, a)
{
	bonus = b;
	defendStrength = d;
}

sict::SuperHero::SuperHero(const SuperHero & copySuperHero) : Hero(copySuperHero)
{
	bonus = copySuperHero.bonus;
	defendStrength = copySuperHero.defendStrength;
}

int sict::SuperHero::attackStrength() const
{
	return Hero::attackStrength() + bonus;
}

int sict::SuperHero::defend() const
{
	return defendStrength;
}

const sict::SuperHero & sict::operator*(const SuperHero & first, const SuperHero & second)
{
	std::cout << "Super Fight! " << first << " vs " << second << " : Winner is ";
	SuperHero f(first);
	SuperHero s(second);

	for (int i = 0; i < maxRounds; i++) {
		f -= s.attackStrength() - f.defend();
		s -= f.attackStrength() - s.defend();

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
	// TODO: insert return statement here
}
