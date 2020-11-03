/**************************************************
Project: RPG Monsters 2.0
Lab Num: Week 11
Author: Cheryl Howard / Matt Butler
Purpose: ZOMBIE Class Header
**************************************************/
#ifndef ZOMBIE_H
#define ZOMBIE_H
#include "Monster.h"
class Zombie : public Monster {
private:
	Zombie(string name, int health);
	static int numZombies;
public:
		~Zombie();
	// friends of this class
	friend class MonsterFactory;
	friend ostream& operator<<(ostream& os, const Zombie& aZombie);
	// accessor functions
	static int getNumZombies();
	// functions
	virtual string speak();
	virtual string attack();
	virtual void showDetails();
};
#endif
